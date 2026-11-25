#include "qt_control_settings.hpp"

#include <QApplication>

using biv::QtControlSettings;

void QtControlSettings::init() {
}

void QtControlSettings::process_events() {
	QApplication::processEvents();
}

void QtControlSettings::set_cursor_start_position() {
}
