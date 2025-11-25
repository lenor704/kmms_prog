#pragma once

#include "menu.hpp"

namespace ule {
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);
	
	const MenuItem* study_go_back(const MenuItem* current);
	
    const MenuItem* algebra_summ(const MenuItem* current);
    const MenuItem* algebra_substract(const MenuItem* current);
    const MenuItem* algebra_multiply(const MenuItem* current);
    const MenuItem* algebra_divide(const MenuItem* current);
	
	const MenuItem* mathan_diffur(const MenuItem* current);
    const MenuItem* mathan_integral(const MenuItem* current);    
}