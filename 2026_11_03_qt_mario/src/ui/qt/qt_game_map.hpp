#pragma once

#include <vector>

#include <QObject>

#include "game_map.hpp"
#include "qt_ui_obj.hpp"
#include "scene_frame.hpp"

namespace biv {
	class QtGameMap : public QObject, public GameMap {
		Q_OBJECT

		private:
			std::vector<QtUIObject*> objs;
			SceneFrame current_frame;

		public:
			QtGameMap(const int height, const int width, QObject* parent = nullptr);

			void add_obj(QtUIObject*);
			void clear() noexcept override;
			void refresh() noexcept override;
			void remove_obj(QtUIObject*);
			void remove_objs() override;
			void show() const noexcept override;

		signals:
			void frameReady(biv::SceneFrame frame);
	};
}
