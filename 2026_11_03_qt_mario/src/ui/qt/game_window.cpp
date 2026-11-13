#include "game_window.hpp"

#include <QFocusEvent>
#include <QKeyEvent>
#include <QShowEvent>
#include <QVBoxLayout>

using biv::GameWindow;

GameWindow::GameWindow(
	QtKeyBoard* input,
	QtGameMap* game_map,
	QWidget* parent
) : QWidget(parent), input(input) {
	setWindowTitle(QStringLiteral("Mario - Qt"));
	setFocusPolicy(Qt::StrongFocus);

	view = new GameView(this);

	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	layout->addWidget(view);

	setFixedSize(view->size());

	connect(
		game_map,
		&QtGameMap::frameReady,
		view,
		&GameView::setFrame,
		Qt::QueuedConnection
	);
}

void GameWindow::keyPressEvent(QKeyEvent* event) {
	if (input != nullptr && input->keyPress(event)) {
		event->accept();
		return;
	}

	QWidget::keyPressEvent(event);
}

void GameWindow::keyReleaseEvent(QKeyEvent* event) {
	if (input != nullptr && input->keyRelease(event)) {
		event->accept();
		return;
	}

	QWidget::keyReleaseEvent(event);
}

void GameWindow::focusOutEvent(QFocusEvent* event) {
	if (input != nullptr) {
		input->reset();
	}

	QWidget::focusOutEvent(event);
}

void GameWindow::showEvent(QShowEvent* event) {
	QWidget::showEvent(event);
	setFocus();
}
