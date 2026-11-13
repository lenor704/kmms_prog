#pragma once

#include <QPushButton>
#include <QWidget>

namespace biv {
	class WelcomeWindow : public QWidget {
		Q_OBJECT

		public:
			WelcomeWindow(QWidget* parent = nullptr);

		signals:
			void go_to_keyboard();

		private:
			QPushButton* go_button;
	};
}
