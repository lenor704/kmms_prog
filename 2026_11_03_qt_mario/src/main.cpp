#include <chrono>
#include <thread>

#include "first_level.hpp"
#include "game.hpp"
#include "game_level.hpp"
#include "game_map.hpp"
#include "keyboard.hpp"
#include "mario.hpp"
#include "os_control_settings.hpp"
#include "ui_factory.hpp"

#ifdef QT_GAME
	#include <QApplication>

	#include "qt_control_settings.hpp"
	#include "qt_keyboard.hpp"
	#include "qt_ui_factory.hpp"
#elif defined(WINDOWS_CONSOLE)
	#include "console_ui_factory.hpp"
	#include "windows_control_settings.hpp"
	#include "windows_keyboard.hpp"
#elif defined(LINUX_CONSOLE)
	#include "console_ui_factory.hpp"
	#include "linux_control_settings.hpp"
	#include "linux_keyboard.hpp"
	#include "ncurses.h"
#endif

int main(int argc, char* argv[]) {
	using namespace std::chrono_literals;

	// 1. Установка параметров игры
	const int map_height = 25;
	const int map_width = 80;
	auto frame_delay = std::chrono::milliseconds(0);

	biv::Game game;
	biv::UIFactory* ui_factory = nullptr;
	biv::OSControlSettings* control_settings = nullptr;
	biv::KeyBoard* keyboard = nullptr;

	#ifdef QT_GAME
		QApplication app(argc, argv);

		static biv::QtControlSettings qt_control_settings;
		static biv::QtKeyBoard qt_keyboard;

		control_settings = &qt_control_settings;
		keyboard = &qt_keyboard;
		frame_delay = std::chrono::milliseconds(10);

		static biv::QtUIFactory qt_ui_factory(&game, &qt_keyboard);
		ui_factory = &qt_ui_factory;
	#else
		#ifdef WINDOWS_CONSOLE
			static biv::WindowsControlSettings windows_control_settings;
			static biv::WindowsKeyBoard windows_keyboard;

			control_settings = &windows_control_settings;
			keyboard = &windows_keyboard;
			frame_delay = std::chrono::milliseconds(10);
		#elif defined(LINUX_CONSOLE)
			static biv::LinuxControlSettings linux_control_settings(
				map_height, map_width
			);
			static biv::LinuxKeyboard linux_keyboard;

			control_settings = &linux_control_settings;
			keyboard = &linux_keyboard;
			frame_delay = std::chrono::milliseconds(50);
		#endif
		static biv::ConsoleUIFactory console_ui_factory(&game);
		ui_factory = &console_ui_factory;
	#endif

	control_settings->init();
	keyboard->on();

	biv::GameMap* game_map = ui_factory->get_game_map(map_height, map_width);
	biv::GameLevel* game_level = new biv::FirstLevel(ui_factory);
	biv::Mario* mario = ui_factory->get_mario();

	biv::UserInput user_input;
	do {
		// 2. Получение пользовательского ввода
		control_settings->process_events();
		user_input = keyboard->get_user_input();
		switch (user_input) {
			case biv::UserInput::MAP_LEFT:
				mario->move_map_left();
				if (!game.check_static_collisions(mario)) {
					game.move_map_left();
				}
				mario->move_map_right();
				break;
			case biv::UserInput::MAP_RIGHT:
				mario->move_map_right();
				if (!game.check_static_collisions(mario)) {
					game.move_map_right();
				}
				mario->move_map_left();
				break;
			case biv::UserInput::MARIO_JUMP:
				mario->jump();
				break;
			case biv::UserInput::EXIT:
				game.finish();
				break;
			case biv::UserInput::NO_INPUT:
				break;
		}

		// 3. Обновление внутреннего состояния игры
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
			keyboard->off();
			keyboard->on();
			game_level->restart();
			mario = ui_factory->get_mario();
			std::this_thread::sleep_for(1000ms);
		}

		if (game.is_level_end()) {
			if (!game_level->is_final()) {
				game_level = game_level->get_next();
				mario = ui_factory->get_mario();
				std::this_thread::sleep_for(1000ms);
				keyboard->off();
				keyboard->on();
				game.start_level();
			} else {
				game.finish();
			}
		}

		// 4. Обновление изображения на экране
		game_map->refresh();
		control_settings->set_cursor_start_position();
		game_map->show();
		std::this_thread::sleep_for(frame_delay);
	} while (
		/* 5. Проверка того, не окончена ли игра */
		!game.is_finished()
	);

	// 6. Завершение
	return 0;
}
