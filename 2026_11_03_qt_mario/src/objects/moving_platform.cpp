#include "moving_platform.hpp"

#include <algorithm>
#include <cmath>

using biv::MovingPlatform;

MovingPlatform::MovingPlatform(
	const Coord& top_left,
	const int width, const int height,
	const int left_limit, const int right_limit
) : RectMapMovableAdapter(top_left, width, height),
	left_limit(left_limit),
	right_limit(right_limit),
	map_offset(0.0f) {

	hspeed = PLATFORM_SPEED;
	vspeed = 0;

	this->top_left.x = std::min(
		std::max(this->top_left.x, static_cast<float>(left_limit)),
		static_cast<float>(right_limit)
	);
}

void MovingPlatform::move_map_left() noexcept {
	map_offset -= MapMovable::MAP_STEP;
	RectMapMovableAdapter::move_map_left();
}

void MovingPlatform::move_map_right() noexcept {
	map_offset += MapMovable::MAP_STEP;
	RectMapMovableAdapter::move_map_right();
}

void MovingPlatform::move_horizontally() noexcept {
	const float old_x = top_left.x;

	const float left_edge = left_limit + map_offset;
	const float right_edge = right_limit + map_offset;

	if (top_left.x <= left_edge) {
		hspeed = std::fabs(hspeed);
	} else if (top_left.x >= right_edge) {
		hspeed = -std::fabs(hspeed);
	}

	Movable::move_horizontally();

	top_left.x = std::min(
		std::max(top_left.x, left_edge), right_edge
	);

	last_offset = top_left.x - old_x;
}

void MovingPlatform::move_vertically() noexcept {
}

biv::Rect MovingPlatform::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed MovingPlatform::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void MovingPlatform::process_horizontal_static_collision(Rect*) noexcept {
}

void MovingPlatform::process_mario_collision(MovingCollisionable* mario) noexcept {
	if (!mario->is_active() || !is_standing_on_top(mario)) {
		return;
	}

	mario->process_vertical_static_collision(static_cast<Rect*>(this));
	mario->move_vertical_offset(
		get_top() - mario->get_rect().get_bottom()
	);
	mario->move_horizontal_offset(last_offset);
}

void MovingPlatform::process_vertical_static_collision(Rect*) noexcept {
}

bool MovingPlatform::can_stand_on() const noexcept {
	return true;
}

bool MovingPlatform::is_standing_on_top(
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