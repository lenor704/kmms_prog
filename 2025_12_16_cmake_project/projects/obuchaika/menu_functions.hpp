#pragma once

#include "menu.hpp"

namespace ule {
	const MenuItem* show_menu(const MenuItem* current);
	const MenuItem* pushkin_menu(const MenuItem* current);
	
	const MenuItem* exit(const MenuItem* current);
	
	const MenuItem* go_back(const MenuItem* current);
	
	const MenuItem* writers_lermontov(const MenuItem* current);
	const MenuItem* writers_krylov(const MenuItem* current);
	
	const MenuItem* pushkin_dubrovskiy(const MenuItem* current);
	const MenuItem* pushkin_onegin(const MenuItem* current);
	const MenuItem* pushkin_evening(const MenuItem* current);
}