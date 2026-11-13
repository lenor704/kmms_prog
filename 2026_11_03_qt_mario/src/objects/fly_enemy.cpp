#include "fly_enemy.hpp"

#include <algorithm>
#include <cmath>

#include "map_movable.hpp"

using biv::FlyEnemy;

FlyEnemy::FlyEnemy(
	const Coord& top_left,
	const int width,
	const int height,
	const int map_height,
	const int map_width,
	const int left_limit,
	const int right_limit
) : RectMapMovableAdapter(top_left, width, height),
	map_height(map_height),
	map_width(map_width),
	left_limit(static_cast<float>(left_limit)),
	right_limit(static_cast<float>(right_limit)),
	map_offset(0.0f) {

	hspeed = H_SPEED;
	vspeed = 0.0f;

	const float top_limit = static_cast<float>(EDGE_MARGIN);
	const float bottom_limit = static_cast<float>(map_height - height - EDGE_MARGIN);

	this->top_left.x = std::min(
		std::max(this->top_left.x, this->left_limit),
		this->right_limit
	);
	this->top_left.y = std::min(
		std::max(this->top_left.y, top_limit),
		bottom_limit
	);
}

biv::Rect FlyEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed FlyEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

// ----------------------------------------------------------------------------
// 									VIRTUAL: MOVABLE
// ----------------------------------------------------------------------------
void FlyEnemy::move_horizontally() noexcept {
	if (!is_active_) {
		if (is_hidden()) {
			hspeed = 0.0f;
		} else {
			top_left.x += hspeed;
		}
		return;
	}

	const float old_x = top_left.x;

	const float left_edge = left_limit + map_offset;
	const float right_edge = right_limit + map_offset;

	if (top_left.x <= left_edge) {
		top_left.x = left_edge;
		hspeed = std::fabs(hspeed);
	} else if (top_left.x >= right_edge) {
		top_left.x = right_edge;
		hspeed = -std::fabs(hspeed);
	}

	Movable::move_horizontally();

	top_left.x = std::min(
		std::max(top_left.x, left_edge),
		right_edge
	);

	last_offset = top_left.x - old_x;
}

void FlyEnemy::move_vertically() noexcept {
	if (!is_active_) {
		if (get_top() < map_height) {
			top_left.y += DEATH_FALL_SPEED;
		}
	}
}

void FlyEnemy::move_map_left() noexcept {
	map_offset -= MapMovable::MAP_STEP;
	RectMapMovableAdapter::move_map_left();
}

void FlyEnemy::move_map_right() noexcept {
	map_offset += MapMovable::MAP_STEP;
	RectMapMovableAdapter::move_map_right();
}

// ----------------------------------------------------------------------------
// 									VIRTUAL: COLLISIONABLE
// ----------------------------------------------------------------------------
void FlyEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	const int exit_left = get_right() - obj->get_left();
	const int exit_right = obj->get_right() - get_left();

	if (exit_left < exit_right) {
		top_left.x -= exit_left;
		last_offset -= exit_left;
		hspeed = -std::fabs(hspeed);
	} else {
		top_left.x += exit_right;
		last_offset += exit_right;
		hspeed = std::fabs(hspeed);
	}
}

void FlyEnemy::process_mario_collision(MovingCollisionable* mario) noexcept {
	if (!mario->is_active()) {
		return;
	}

	if (is_standing_on_top(mario)) {
		mario->process_vertical_static_collision(static_cast<Rect*>(this));
		mario->move_vertical_offset(
			get_top() - mario->get_rect().get_bottom()
		);
		mario->move_horizontal_offset(last_offset);
	} else {
		mario->kill();
	}
}

void FlyEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	const int exit_up = get_bottom() - obj->get_top();
	const int exit_down = obj->get_bottom() - get_top();

	if (exit_up < exit_down) {
		top_left.y -= exit_up;
		if (vspeed > 0) {
			vspeed = -vspeed;
		}
	} else {
		top_left.y += exit_down;
		if (vspeed < 0) {
			vspeed = -vspeed;
		}
	}
}

bool FlyEnemy::can_stand_on() const noexcept {
	return true;
}

bool FlyEnemy::is_fly_enemy() const noexcept {
	return true;
}

bool FlyEnemy::is_standing_on_top(
	const MovingCollisionable* mario
) const noexcept {
	if (mario->get_speed().v < 0) {
		return false;
	}

	const Rect mario_rect = mario->get_rect();

	return (
		mario_rect.get_right() > get_left() &&
		mario_rect.get_left() < get_right() &&
		mario_rect.get_bottom() >= get_top() &&
		mario_rect.get_bottom() <= get_top() + STANDING_TOLERANCE
	);
}

bool FlyEnemy::is_hidden() const noexcept {
	return (
		get_left() >= map_width || get_right() <= 0 || get_top() >= map_height
	);
}