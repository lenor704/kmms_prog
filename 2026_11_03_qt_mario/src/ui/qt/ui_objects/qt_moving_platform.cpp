#include "qt_moving_platform.hpp"

using biv::QtMovingPlatform;

QtMovingPlatform::QtMovingPlatform(
	const Coord& top_left,
	const int width, const int height,
	const int left_limit, const int right_limit
) : MovingPlatform(top_left, width, height, left_limit, right_limit),
	QtUIObjectRectAdapter(top_left, width, height) {}

char QtMovingPlatform::get_brush() const noexcept {
	return '=';
}