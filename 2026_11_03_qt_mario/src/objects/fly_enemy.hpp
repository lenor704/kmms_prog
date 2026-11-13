#pragma once

#include "moving_collisionable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
	class FlyEnemy : public RectMapMovableAdapter, public Movable, public Collisionable {
		private:
			static constexpr float H_SPEED = 0.15f;
			static constexpr float DEATH_FALL_SPEED = 0.5f;
			static constexpr int EDGE_MARGIN = 1;
			static constexpr int STANDING_TOLERANCE = 1;

			const int map_height;
			const int map_width;

			const float left_limit;
			const float right_limit;

			float map_offset = 0.0f;
			float last_offset = 0.0f;

		public:
			FlyEnemy(
				const Coord& top_left,
				const int width,
				const int height,
				const int map_height,
				const int map_width,
				const int left_limit,
				const int right_limit
			);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			void move_horizontally() noexcept override;
			void move_vertically() noexcept override;
			void move_map_left() noexcept override;
			void move_map_right() noexcept override;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(MovingCollisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
			bool can_stand_on() const noexcept override;
			bool is_fly_enemy() const noexcept override;

		private:
			bool is_hidden() const noexcept;
			bool is_standing_on_top(
				const MovingCollisionable* mario
			) const noexcept;
	};
}