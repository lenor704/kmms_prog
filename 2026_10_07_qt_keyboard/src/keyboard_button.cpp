#include "keyboard_button.hpp"

#include <QSizePolicy>

using biv::KeyBoardButton;

KeyBoardButton::KeyBoardButton(const QString& text, QWidget* parent)
    : QPushButton(parent) {
	setFont(QFont("Roboto", 20));
	setText(text);
	setFocusPolicy(Qt::NoFocus);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
