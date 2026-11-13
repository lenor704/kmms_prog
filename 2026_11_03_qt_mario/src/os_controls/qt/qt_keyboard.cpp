#include "qt_keyboard.hpp"

using biv::QtKeyBoard;
using biv::UserInput;

QtKeyBoard::QtKeyBoard(QObject* parent) : QObject(parent) {
	reset();
}

UserInput QtKeyBoard::get_user_input() {
	if (states[LEFT].load(std::memory_order_relaxed)) {
		return UserInput::MAP_RIGHT;
	}
	if (states[RIGHT].load(std::memory_order_relaxed)) {
		return UserInput::MAP_LEFT;
	}
	if (states[JUMP].load(std::memory_order_relaxed)) {
		return UserInput::MARIO_JUMP;
	}
	if (states[EXIT].load(std::memory_order_relaxed)) {
		return UserInput::EXIT;
	}
	return UserInput::NO_INPUT;
}

void QtKeyBoard::on() {
}

void QtKeyBoard::off() {
	reset();
}

bool QtKeyBoard::keyPress(QKeyEvent* event) {
	State state;
	if (!toState(event->key(), state)) {
		return false;
	}

	if (event->isAutoRepeat()) {
		return true;
	}

	states[state].store(true, std::memory_order_relaxed);

	if (
		state == EXIT
		&& !exit_was_pressed.exchange(true, std::memory_order_relaxed)
	) {
		emit exitRequested();
	}

	return true;
}

bool QtKeyBoard::keyRelease(QKeyEvent* event) {
	State state;
	if (!toState(event->key(), state)) {
		return false;
	}

	states[state].store(false, std::memory_order_relaxed);

	if (state == EXIT) {
		exit_was_pressed.store(false, std::memory_order_relaxed);
	}

	return true;
}

void QtKeyBoard::reset() {
	for (int i = 0; i < STATE_COUNT; i++) {
		states[i].store(false, std::memory_order_relaxed);
	}
	exit_was_pressed.store(false, std::memory_order_relaxed);
}

bool QtKeyBoard::toState(int qt_key, State& state) {
	switch (qt_key) {
		case Qt::Key_A:
			state = LEFT;
			return true;
		case Qt::Key_D:
			state = RIGHT;
			return true;
		case Qt::Key_Space:
			state = JUMP;
			return true;
		case Qt::Key_Escape:
		case Qt::Key_Q:
			state = EXIT;
			return true;
		default:
			return false;
	}
}
