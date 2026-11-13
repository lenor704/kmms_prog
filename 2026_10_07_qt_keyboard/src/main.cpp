#include <QApplication>

#include "keyboard_window.hpp"
#include "welcome_window.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
	
    biv::WelcomeWindow welcome_window;
    biv::KeyBoardWindow keyboard_window;

    QObject::connect(
        &welcome_window, &biv::WelcomeWindow::go_to_keyboard,
        &keyboard_window, [&keyboard_window, &welcome_window]() {
            keyboard_window.show();
            welcome_window.hide();
        }
    );

    welcome_window.show();
	
    return app.exec();
}
