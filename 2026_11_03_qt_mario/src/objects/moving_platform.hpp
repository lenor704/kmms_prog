#pragma once

#include "moving_collisionable.hpp"
#include "rect_map_movable_adapter.hpp"

namespace biv {
	class MovingPlatform : public RectMapMovableAdapter, public MovingCollisionable {
		private:
			static constexpr float PLATFORM_SPEED = 0.1f;
			static constexpr int STANDING_TOLERANCE = 1;

		private:
			const float left_limit;
			const float right_limit;

			float map_offset;
			float last_offset = 0;

		public:
			MovingPlatform(
				const Coord& top_left,
				const int width, const int height,
				const int left_limit, const int right_limit
			);

			void move_map_left() noexcept override;
			void move_map_right() noexcept override;
			void move_horizontally() noexcept override;
			void move_vertically() noexcept override;
			
			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;
			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(MovingCollisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
			bool can_stand_on() const noexcept override;

		private:
			bool is_standing_on_top(
				const MovingCollisionable* mario
			) const noexcept;
	};
}