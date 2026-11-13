#include "welcome_window.hpp"

#include <QLabel>
#include <QVBoxLayout>

using biv::WelcomeWindow;

WelcomeWindow::WelcomeWindow(QWidget* parent) : QWidget(parent) {
	const int window_width = 700;
	resize(window_width, 400);
	setWindowTitle("Приветствие");

	go_button = new QPushButton("Перейти к клавиатуре", this);
	go_button->setFont(QFont("Roboto", 20));
	go_button->setMinimumHeight(80);

	QVBoxLayout* main_layout = new QVBoxLayout(this);
	main_layout->addWidget(go_button);

	connect(go_button, &QPushButton::clicked, this, &WelcomeWindow::go_to_keyboard);
}
