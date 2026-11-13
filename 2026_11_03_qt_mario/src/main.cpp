#include <atomic>
#include <chrono>
#include <thread>

#include <QApplication>
#include <QCoreApplication>
#include <QMetaObject>

#include "first_level.hpp"
#include "game.hpp"
#include "game_level.hpp"
#include "game_map.hpp"
#include "game_window.hpp"
#include "mario.hpp"
#include "qt_control_settings.hpp"
#include "qt_game_map.hpp"
#include "qt_keyboard.hpp"
#include "qt_ui_factory.hpp"
#include "ui_factory.hpp"

int main(int argc, char* argv[]) {
	using namespace std::chrono_literals;
	using biv::UserInput;

	QApplication app(argc, argv);

	const int map_height = 25;
	const int map_width = 80;
	const auto frame_delay = std::chrono::milliseconds(10);

	biv::QtControlSettings control_settings;
	biv::QtKeyBoard keyboard;
	control_settings.init();
	keyboard.on();

	biv::Game game;
	biv::QtUIFactory ui_factory(&game);
	biv::GameMap* game_map = ui_factory.get_game_map(map_height, map_width);
	biv::GameLevel* game_level = new biv::FirstLevel(&ui_factory);
	biv::Mario* mario = ui_factory.get_mario();

	biv::QtGameMap* qt_game_map = dynamic_cast<biv::QtGameMap*>(game_map);
	biv::GameWindow window(&keyboard, qt_game_map);

	std::atomic_bool running{true};

	QObject::connect(
		&keyboard,
		&biv::QtKeyBoard::exitRequested,
		&app,
		&QCoreApplication::quit
	);
	QObject::connect(
		&app,
		&QCoreApplication::aboutToQuit,
		[&running]() {
			running.store(false);
		}
	);

	window.show();

	std::thread game_thread([&]() {
		do {
			const UserInput user_input = keyboard.get_user_input();
			switch (user_input) {
				case UserInput::MAP_LEFT:
					mario->move_map_left();
					if (!game.check_static_collisions(mario)) {
						game.move_map_left();
					}
					mario->move_map_right();
					break;
				case UserInput::MAP_RIGHT:
					mario->move_map_right();
					if (!game.check_static_collisions(mario)) {
						game.move_map_right();
					}
					mario->move_map_left();
					break;
				case UserInput::MARIO_JUMP:
					mario->jump();
					break;
				case UserInput::EXIT:
					game.finish();
					break;
				case UserInput::NO_INPUT:
					break;
			}

			game.move_objs_horizontally();
			game.check_horizontally_static_collisions();

			game.move_objs_vertically();
			game.check_mario_collision();
			game.check_vertically_static_collisions();

			float camera_margin_left = map_width / 4.0f;
			float camera_margin_right = map_width * 3.0f / 4.0f;
			if (game.is_mario_on_fly_enemy()) {
				camera_margin_left = map_width / 2.0f - 1.0f;
				camera_margin_right = map_width / 2.0f + 1.0f;
			}

			while (mario->get_x() > camera_margin_right) {
				mario->move_horizontal_offset(-1.0f);
				if (game.check_static_collisions(mario)) {
					mario->move_horizontal_offset(1.0f);
					break;
				}
				game.move_map_left();
			}

			while (mario->get_x() < camera_margin_left) {
				mario->move_horizontal_offset(1.0f);
				if (game.check_static_collisions(mario)) {
					mario->move_horizontal_offset(-1.0f);
					break;
				}
				game.move_map_right();
			}

			if (
				game_map->is_below_map(mario->get_top())
				|| !mario->is_active()
			) {
				keyboard.off();
				keyboard.on();
				game_level->restart();
				mario = ui_factory.get_mario();
				std::this_thread::sleep_for(1000ms);
			}

			if (game.is_level_end()) {
				if (!game_level->is_final()) {
					game_level = game_level->get_next();
					mario = ui_factory.get_mario();
					std::this_thread::sleep_for(1000ms);
					keyboard.off();
					keyboard.on();
					game.start_level();
				} else {
					game.finish();
				}
			}

			game_map->refresh();
			control_settings.set_cursor_start_position();
			game_map->show();
			std::this_thread::sleep_for(frame_delay);
		} while (running.load() && !game.is_finished());

		running.store(false);
		QMetaObject::invokeMethod(
			QCoreApplication::instance(),
			"quit",
			Qt::QueuedConnection
		);
	});

	const int result = app.exec();

	running.store(false);
	if (game_thread.joinable()) {
		game_thread.join();
	}

	return result;
}
