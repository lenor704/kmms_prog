#include "menu_functions.hpp"
#include "menu.hpp"

#include <iostream>
#include <cstdlib>

namespace {
	const ule::MenuItem* menu(const ule::MenuItem* current) {
		for (int i = 1; i < current->children_count; i++) {
			std::cout << current->childrens[i]->title << std::endl;
		}
		std::cout << current->childrens[0]->title << std::endl;
		
		int user_input;
		std::cout << "Выберите число > ";
		std::cin >> user_input;
		std::cout << std::endl;
		
		return current->childrens[user_input];
	}
}

const ule::MenuItem* ule::show_menu(const ule::MenuItem* current) {
	std::cout << "Читальный зал приветствует Вас!" << std::endl;
	return menu(current);
}
const ule::MenuItem* ule::pushkin_menu(const ule::MenuItem* current) {
	std::cout << "Пушкин приветствует Вас!" << std::endl;
	return menu(current);
}

const ule::MenuItem* ule::exit(const ule::MenuItem* current) {
	std::exit(0);
}

const ule::MenuItem* ule::go_back(const ule::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent->parent;
}

const ule::MenuItem* ule::writers_lermontov(const ule::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}
const ule::MenuItem* ule::writers_krylov(const ule::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const ule::MenuItem* ule::pushkin_dubrovskiy(const ule::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}
const ule::MenuItem* ule::pushkin_onegin(const ule::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}
const ule::MenuItem* ule::pushkin_evening(const ule::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}