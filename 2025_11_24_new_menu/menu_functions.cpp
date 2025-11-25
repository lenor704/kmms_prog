#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const ule::MenuItem* ule::show_menu(const MenuItem* current) {
    std::cout << "Обучайка приветствует тебя, юный ученик!" << std::endl;
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const ule::MenuItem* ule::exit(const ule::MenuItem* current) {
    std::exit(0);
}

const ule::MenuItem* ule::algebra_summ(const MenuItem* current) {
    //TO DO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ule::MenuItem* ule::algebra_substract(const MenuItem* current) {
    //TO DO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ule::MenuItem* ule::algebra_multiply(const MenuItem* current) {
    //TO DO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ule::MenuItem* ule::algebra_divide(const MenuItem* current) {
    //TO DO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ule::MenuItem* ule::study_go_back(const MenuItem* current) {
    //TO DO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const ule::MenuItem* ule::mathan_diffur(const MenuItem* current) {
    //TO DO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ule::MenuItem* ule::mathan_integral(const MenuItem* current) {
    //TO DO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}