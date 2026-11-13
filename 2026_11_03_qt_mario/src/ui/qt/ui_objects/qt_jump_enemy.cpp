#include "qt_jump_enemy.hpp"

using biv::QtJumpEnemy;

QtJumpEnemy::QtJumpEnemy(
	const Coord& top_left,
	const int width,
	const int height,
	const int map_height
) : JumpEnemy(top_left, width, height, map_height) {}

char QtJumpEnemy::get_brush() const noexcept {
	return 'j';
}
