#include "game.hpp"

#include <algorithm>

using biv::Game;

Game::Game() {}

void Game::add_collisionable(Collisionable* obj) {
	collisionable_objs.push_back(obj);
}

void Game::add_map_movable(MapMovable* obj) {
	map_movable_objs.push_back(obj);
}

void Game::add_mario(Mario* obj) {
	mario = obj;
}

void Game::add_movable(Movable* obj) {
	movable_objs.push_back(obj);
}

void Game::add_static_obj(Rect* obj) {
	static_objs.push_back(obj);
}

void Game::check_horizontally_static_collisions() noexcept {
	for (Collisionable* obj: collisionable_objs) {
		for (Rect* static_obj: static_objs) {
			if (obj->has_collision(static_obj)) {
				obj->process_horizontal_static_collision(static_obj);
				break;
			}
		}
	}
}

void Game::check_mario_collision() {
	mario_on_fly_enemy_ = false;
	for (int i = 0; i < collisionable_objs.size(); i++) {
		Collisionable* obj = collisionable_objs[i];
		const bool stands_above = (
			obj->can_stand_on() && is_mario_standing(obj, mario)
		);
		if (obj->has_collision(mario) || stands_above) {
			obj->process_mario_collision(mario);
			if (!mario->is_active()) {
				break;
			}
			if (stands_above && obj->is_fly_enemy()) {
				mario_on_fly_enemy_ = true;
			}
			if (!obj->is_active()) {
				// TODO
				collisionable_objs[i] = collisionable_objs.back();
				collisionable_objs.pop_back();
				i--;
			}
		}
	}
}

bool Game::check_static_collisions(Collisionable* obj) const noexcept {
	for (Rect* static_obj: static_objs) {
		if (obj->has_collision(static_obj)) {
			return true;
		}
	}
	return false;
}

void Game::check_vertically_static_collisions() noexcept {
	if (mario->has_collision(static_objs[static_objs.size() - 1])) {
		is_level_end_ = true;
	}
	
	for (Collisionable* obj: collisionable_objs) {
		for (Rect* static_obj: static_objs) {
			if (obj->has_collision(static_obj)) {
				obj->process_vertical_static_collision(static_obj);
				break;
			}
		}
	}
}

void Game::finish() noexcept {
	is_finished_ = true;
}

bool Game::is_finished() const noexcept {
	return is_finished_;
}

bool Game::is_level_end() const noexcept {
	return is_level_end_;
}

bool Game::is_mario_on_fly_enemy() const noexcept {
	return mario_on_fly_enemy_;
}

void Game::move_map_left() noexcept {
	for (MapMovable* obj: map_movable_objs) {
		obj->move_map_left();
	}
}

void Game::move_map_right() noexcept {
	for (MapMovable* obj: map_movable_objs) {
		obj->move_map_right();
	}
}

void Game::move_objs_horizontally() noexcept {
	for (Movable* obj: movable_objs) {
		obj->move_horizontally();
	}
}

void Game::move_objs_vertically() noexcept {
	for (Movable* obj: movable_objs) {
		obj->move_vertically();
	}
}

void Game::remove_collisionable(Collisionable* obj) {
	remove_obj(collisionable_objs, obj);
}

void Game::remove_map_movable(MapMovable* obj) {
	remove_obj(map_movable_objs, obj);
}

void Game::remove_mario() noexcept {
	mario = nullptr;
}

void Game::remove_movable(Movable* obj) {
	remove_obj(movable_objs, obj);
}

void Game::remove_objs() {
	collisionable_objs.clear();
	map_movable_objs.clear();
	movable_objs.clear();
	static_objs.clear();
	remove_mario();
}

void Game::remove_static_obj(Rect* obj) {
	remove_obj(static_objs, obj);
}

void Game::start_level() noexcept {
	is_level_end_ = false;
}

// ----------------------------------------------------------------------------
// 									PRIVATE
// ----------------------------------------------------------------------------
bool Game::is_mario_standing(
	const Collisionable* obj, const MovingCollisionable* mario
) const noexcept {
	if (mario->get_speed().v < 0) {
		return false;
	}

	const Rect obj_rect = obj->get_rect();
	const Rect mario_rect = mario->get_rect();

	return (
		mario_rect.get_right() > obj_rect.get_left() &&
		mario_rect.get_left() < obj_rect.get_right() &&
		mario_rect.get_bottom() >= obj_rect.get_top() &&
		mario_rect.get_bottom() <= obj_rect.get_top() + STANDING_TOLERANCE
	);
}

template<class T>
void Game::remove_obj(std::vector<T*>& container, T* obj) {
	container.erase(
		std::remove(
			container.begin(), container.end(), obj
		), 
		container.end()
	);
}
