#include "qt_fly_enemy.hpp"

using biv::QtFlyEnemy;

QtFlyEnemy::QtFlyEnemy(
	const Coord& top_left,
	const int width,
	const int height,
	const int map_height,
	const int map_width,
	const int left_limit,
	const int right_limit
) : FlyEnemy(top_left, width, height, map_height, map_width, left_limit, right_limit) {}

char QtFlyEnemy::get_brush() const noexcept {
	return 'b';
}