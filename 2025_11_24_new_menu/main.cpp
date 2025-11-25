#include <clocale>
#include <iostream>
#include <windows.h>

#include "menu.hpp"
#include "menu_functions.hpp"
#include "menu_items.hpp"

int main() {
	std::setlocale(LC_ALL, "");

	const ule::MenuItem* current = &ule::MAIN;
	do {
		current = current->func(current);
	} while (true);

	return 0;
}