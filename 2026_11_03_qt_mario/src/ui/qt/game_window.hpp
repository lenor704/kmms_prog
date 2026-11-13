#pragma once

#include <QFocusEvent>
#include <QKeyEvent>
#include <QShowEvent>
#include <QWidget>

#include "game_view.hpp"
#include "qt_game_map.hpp"
#include "qt_keyboard.hpp"

namespace biv {
	class GameWindow : public QWidget {
		public:
			GameWindow(
				QtKeyBoard* input,
				QtGameMap* game_map,
				QWidget* parent = nullptr
			);

		protected:
			void keyPressEvent(QKeyEvent* event) override;
			void keyReleaseEvent(QKeyEvent* event) override;
			void focusOutEvent(QFocusEvent* event) override;
			void showEvent(QShowEvent* event) override;

		private:
			QtKeyBoard* input;
			GameView* view;
	};
}
