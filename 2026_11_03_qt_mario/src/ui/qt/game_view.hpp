#pragma once

#include <QHash>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QWidget>

#include "scene_frame.hpp"

namespace biv {
	class GameView : public QWidget {
		public:
			GameView(QWidget* parent = nullptr);

			void setFrame(const SceneFrame& new_frame);

			QSize sizeHint() const override;

		protected:
			void paintEvent(QPaintEvent* event) override;

		private:
			static constexpr float UNIT = 16.0f;
			static constexpr int MAP_WIDTH = 80;
			static constexpr int MAP_HEIGHT = 25;

			SceneFrame frame;
			QHash<char, QPixmap> sprites;
			QPixmap background;

			void loadSprites();
			void buildBackground();
			void drawObject(QPainter& painter, const ObjectFrame& object);
			void drawTiledSprite(
				QPainter& painter,
				const QPixmap& sprite,
				const ObjectFrame& object
			);
	};
}
