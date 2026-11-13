#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "moving_platform.hpp"

namespace biv {
	class QtMovingPlatform :
		public MovingPlatform,	
		public QtUIObjectRectAdapter
	{
		public:
			QtMovingPlatform(
				const Coord& top_left,
				const int width, const int height,
				const int left_limit, const int right_limit
			);

			char get_brush() const noexcept override;
	};
}