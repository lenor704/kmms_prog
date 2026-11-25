#include "keyboard_window.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

using biv::KeyBoardWindow;

KeyBoardWindow::KeyBoardWindow(QWidget* parent) : QWidget(parent) {
	const int keyboard_width = 1160;
	resize(keyboard_width, 710);
    setWindowTitle("Грустная Клавиатура");
	
	QPixmap pixmap("img/grustnii-smail.png");
	image = new QLabel(this);
	image->setFixedSize(200, 200);
	image->setPixmap(pixmap);
	image->setScaledContents(true);
	
	QHBoxLayout* smail_layout = new QHBoxLayout();
	smail_layout->addWidget(image);

    display = new QLineEdit();
	display->setMinimumHeight(80);
	display->setFont(QFont("Roboto", 40));
    display->setReadOnly(true);
	display->setFocusPolicy(Qt::NoFocus);
	display->setText("Помоги мне заработать лучше...");

	keyboard = new KeyBoard(keyboard_width);
	connect(keyboard, &biv::KeyBoard::key_pressed, this, &KeyBoardWindow::process_key);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
	main_layout->addLayout(smail_layout);
    main_layout->addWidget(display);
    main_layout->addWidget(keyboard);
}

void KeyBoardWindow::keyPressEvent(QKeyEvent* event) {
	const int key = event->nativeVirtualKey();
	keyboard->animate_button(key);
	process_key(key);
}

void KeyBoardWindow::process_key(const int code) {
	if (code == 8) { 
		typed_text.chop(1);
	} else if (code == 32) { 
		typed_text += " ";
	} else if (keyboard->is_key_allowed(code)) {
		typed_text += keyboard->get_key_text(code);
	} else {
		return;
	}

	display->setText(typed_text);

	if (is_sad) {
		image->setPixmap(QPixmap("img/radostni-smail.png"));
		is_sad = false;
	}
}
