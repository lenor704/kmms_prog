/**
	- Прыгающий на месте враг.

	- В отличие от Enemy, враг не передвигается по горизонтали и не
		разворачивается на краю корабля: он прыгает на одном месте,
		опираясь на высоту, на которой появился.
	- Высота прыжка ограничена, поэтому враг не выходит за пределы карты
		ни при прыжках, ни при прокрутке.
	- Врага можно убить, если Марио упадёт на него сверху.
*/

#pragma once

#include "moving_collisionable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
	class JumpEnemy : public RectMapMovableAdapter, public Movable, public Collisionable {
		private:
			static constexpr float DEATH_FALL_SPEED = 0.5f;
			static constexpr int JUMP_HEIGHT = 10;
			static constexpr int EDGE_MARGIN = 1;

			const int map_height;

			float base_y = 0;
			float jump_top = 0;

		public:
			JumpEnemy(
				const Coord& top_left,
				const int width,
				const int height,
				const int map_height
			);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			void move_horizontally() noexcept override;
			void move_vertically() noexcept override;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(MovingCollisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
