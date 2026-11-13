#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "fly_enemy.hpp"

namespace biv {
	class QtFlyEnemy : public FlyEnemy, public QtUIObjectRectAdapter {
		public:
			QtFlyEnemy(
				const Coord& top_left,
				const int width,
				const int height,
				const int map_height,
				const int map_width,
				const int left_limit,
				const int right_limit
			);

			char get_brush() const noexcept override;
	};
}