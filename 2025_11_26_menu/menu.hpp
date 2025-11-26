#pragma once

namespace ule {
	struct MenuItem {
		const char* title;
		const MenuItem* (*func)(const MenuItem* current);
		const MenuItem* parent;
		
		const MenuItem* const *childrens;
		const int children_count;
	};
}