#pragma once

#include <atomic>

#include <QKeyEvent>
#include <QObject>

#include "keyboard.hpp"

namespace biv {
	class QtKeyBoard : public QObject, public KeyBoard {
		Q_OBJECT

		public:
			QtKeyBoard(QObject* parent = nullptr);

			UserInput get_user_input() override;
			void on() override;
			void off() override;

			bool keyPress(QKeyEvent* event);
			bool keyRelease(QKeyEvent* event);
			void reset();

		signals:
			void exitRequested();

		private:
			enum State {
				LEFT,
				RIGHT,
				JUMP,
				EXIT,
				STATE_COUNT
			};

			mutable std::atomic_bool states[STATE_COUNT];
			std::atomic_bool exit_was_pressed{false};

			static bool toState(int qt_key, State& state);
	};
}
