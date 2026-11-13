#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "jump_enemy.hpp"

namespace biv {
	class QtJumpEnemy : public JumpEnemy, public QtUIObjectRectAdapter {
		public:
			QtJumpEnemy(
				const Coord& top_left,
				const int width,
				const int height,
				const int map_height
			);

			char get_brush() const noexcept override;
	};
}
