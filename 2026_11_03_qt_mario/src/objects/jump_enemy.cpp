#include "jump_enemy.hpp"

#include <algorithm>
#include <cmath>

using biv::JumpEnemy;

JumpEnemy::JumpEnemy(
	const Coord& top_left,
	const int width,
	const int height,
	const int map_height
) : RectMapMovableAdapter(top_left, width, height),
	map_height(map_height) {

	hspeed = 0;
	vspeed = 0;

	// Опора и верхняя граница прыжка не должны выходить за пределы карты.
	const float top_limit = static_cast<float>(EDGE_MARGIN);
	const float bottom_limit = static_cast<float>(map_height - height - EDGE_MARGIN);

	base_y = std::min(std::max(top_left.y, top_limit), bottom_limit);
	jump_top = std::max(
		std::min(base_y - JUMP_HEIGHT, bottom_limit), top_limit
	);

	this->top_left.y = base_y;
}

biv::Rect JumpEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed JumpEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

// ----------------------------------------------------------------------------
// 									VIRTUAL: MOVABLE
// ----------------------------------------------------------------------------
void JumpEnemy::move_horizontally() noexcept {
	// Враг прыгает на месте.
}

void JumpEnemy::move_vertically() noexcept {
	if (!is_active_) {
		// Убитый враг падает вниз, пока не скроется за нижним краем карты.
		if (get_top() < map_height) {
			top_left.y += DEATH_FALL_SPEED;
		}
		return;
	}

	jump();
	if (vspeed < MAX_V_SPEED) {
		vspeed += V_ACCELERATION;
	}
	top_left.y += vspeed;

	if (top_left.y <= jump_top) {
		top_left.y = jump_top;
		vspeed = std::fabs(vspeed);
	} else if (top_left.y >= base_y) {
		top_left.y = base_y;
		vspeed = 0;
	}
}

// ----------------------------------------------------------------------------
// 									VIRTUAL: COLLISIONABLE
// ----------------------------------------------------------------------------
void JumpEnemy::process_horizontal_static_collision(Rect*) noexcept {
}

void JumpEnemy::process_mario_collision(MovingCollisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}

void JumpEnemy::process_vertical_static_collision(Rect*) noexcept {
}
