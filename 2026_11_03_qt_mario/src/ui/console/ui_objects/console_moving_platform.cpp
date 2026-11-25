#include "console_moving_platform.hpp"

using biv::ConsoleMovingPlatform;

ConsoleMovingPlatform::ConsoleMovingPlatform(
	const Coord& top_left,
	const int width, const int height,
	const int left_limit, const int right_limit
) : MovingPlatform(top_left, width, height, left_limit, right_limit),
	ConsoleUIObjectRectAdapter(top_left, width, height) {}

char ConsoleMovingPlatform::get_brush() const noexcept {
	return '=';
}