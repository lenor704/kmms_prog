#pragma once

#include "game_window.hpp"
#include "qt_box.hpp"
#include "qt_enemy.hpp"
#include "qt_fly_enemy.hpp"
#include "qt_full_box.hpp"
#include "qt_game_map.hpp"
#include "qt_jump_enemy.hpp"
#include "qt_mario.hpp"
#include "qt_money.hpp"
#include "qt_moving_platform.hpp"
#include "qt_ship.hpp"
#include "ui_factory.hpp"

namespace biv {
	class QtUIFactory : public UIFactory {
		private:
			QtGameMap* game_map = nullptr;
			QtKeyBoard* keyboard = nullptr;
			GameWindow* window = nullptr;
			int map_height = 0;
			int map_width = 0;
			std::vector<QtBox*> boxes;
			std::vector<QtFullBox*> full_boxes;
			std::vector<QtJumpEnemy*> jump_enemies;
			std::vector<QtShip*> ships;
			QtMario* mario = nullptr;
			std::vector<QtEnemy*> enemies;
			std::vector<QtFlyEnemy*> fly_enemies;
			std::vector<QtMoney*> moneys;
			std::vector<QtMovingPlatform*> moving_platforms;

		public:
			QtUIFactory(Game* game, QtKeyBoard* keyboard);
			
			void clear_data() override;
			void create_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_enemy(
				const Coord& top_left, const int width, const int height
			) override;
			void create_fly_enemy(
				const Coord& top_left, const int width, const int height,
				const int left_limit, const int right_limit
			) override;
			void create_full_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_jump_enemy(
				const Coord& top_left, const int width, const int height
			) override;
			void create_mario(
				const Coord& top_left, const int width, const int height
			) override;
			void create_money(
				const Coord& top_left, const int width, const int height
			) override;
			void create_moving_platform(
				const Coord& top_left, const int width, const int height,
				const int left_limit, const int right_limit
			) override;
			void create_ship(
				const Coord& top_left, const int width, const int height
			) override;
			GameMap* get_game_map(const int height, const int width) override;
			Mario* get_mario() override;
	};
}
