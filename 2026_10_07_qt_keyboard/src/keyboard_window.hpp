#pragma once

#include <cstddef>

#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QWidget>

#include "keyboard.hpp"

namespace biv {
	class KeyBoardWindow : public QWidget {
		private:
			QLineEdit* display;
			KeyBoard* keyboard;
			QLabel* image;
			bool is_sad = true;
			QString typed_text = "Помоги мне заработать лучше...";
			void process_key(const int code);

		public:
			KeyBoardWindow(QWidget* parent = nullptr);
			
		protected:
			void keyPressEvent(QKeyEvent* event) override;			
	};
}
