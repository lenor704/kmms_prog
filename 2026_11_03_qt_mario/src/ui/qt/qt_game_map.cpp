#include "qt_game_map.hpp"

#include <algorithm>

#include "collisionable.hpp"
#include "full_box.hpp"

using biv::QtGameMap;

QtGameMap::QtGameMap(const int height, const int width, QObject* parent)
	: QObject(parent), GameMap(height, width) {
	qRegisterMetaType<biv::SceneFrame>("biv::SceneFrame");
	current_frame.objects.reserve(128);
}

void QtGameMap::add_obj(QtUIObject* obj) {
	objs.push_back(obj);
}

void QtGameMap::clear() noexcept {
	current_frame.objects.clear();
}

void QtGameMap::refresh() noexcept {
	current_frame.objects.clear();

	for (QtUIObject* obj : objs) {
		Collisionable* collisionable = dynamic_cast<Collisionable*>(obj);
		FullBox* full_box = dynamic_cast<FullBox*>(obj);
		if (
			collisionable != nullptr
			&& !collisionable->is_active()
			&& full_box == nullptr
		) {
			continue;
		}

		const char brush = obj->get_brush();
		if (brush == ' ' || brush == '\0') {
			continue;
		}

		current_frame.objects.push_back({
			static_cast<float>(obj->get_left()),
			static_cast<float>(obj->get_top()),
			static_cast<float>(obj->get_right() - obj->get_left()),
			static_cast<float>(obj->get_bottom() - obj->get_top()),
			brush
		});
	}
}

void QtGameMap::remove_obj(QtUIObject* obj) {
	objs.erase(std::remove(objs.begin(), objs.end(), obj), objs.end());
}

void QtGameMap::remove_objs() {
	objs.clear();
	clear();
}

void QtGameMap::show() const noexcept {
	const_cast<QtGameMap*>(this)->frameReady(current_frame);
}
