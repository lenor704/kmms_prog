#include "menu_items.hpp"
#include "menu_functions.hpp"

const ule::MenuItem ule::PUSHKIN_DUBROVSKIY {
	"1 - Дубровский", ule::pushkin_dubrovskiy, &ule::WRITERS_PUSHKIN
};
const ule::MenuItem ule::PUSHKIN_ONEGIN {
	"2 - Евгений Онегин", ule::pushkin_onegin, &ule::WRITERS_PUSHKIN
};
const ule::MenuItem ule::PUSHKIN_EVENING {
	"3 - Зимний вечер", ule::pushkin_evening, &ule::WRITERS_PUSHKIN
};
const ule::MenuItem ule::PUSHKIN_GO_BACK {
	"0 - Выйти в предыдущее меню", ule::go_back, &ule::WRITERS_PUSHKIN
};

namespace {
	const ule::MenuItem* pushkin_children[] = {
		&ule::PUSHKIN_GO_BACK,
		&ule::PUSHKIN_DUBROVSKIY,
		&ule::PUSHKIN_ONEGIN,
		&ule::PUSHKIN_EVENING		
	};
	const int pushkin_size = sizeof(pushkin_children) / sizeof(pushkin_children[0]);
}

const ule::MenuItem ule::WRITERS_PUSHKIN {
	"1 - Читать Пушкина", ule::pushkin_menu, &ule::WRITERS, pushkin_children, pushkin_size
};
const ule::MenuItem ule::WRITERS_LERMONTOV {
	"2 - Читать Лермонтова", ule::writers_lermontov, &ule::WRITERS
};
const ule::MenuItem ule::WRITERS_KRYLOV {
	"3 - Читать Крылова", ule::writers_krylov, &ule::WRITERS
};
const ule::MenuItem ule::WRITERS_GO_BACK {
	"0 - Выйти в главное меню", ule::go_back, &ule::WRITERS
};

namespace {
	const ule::MenuItem* writers_children[] = {
		&ule::WRITERS_GO_BACK,
		&ule::WRITERS_PUSHKIN,
		&ule::WRITERS_LERMONTOV,
		&ule::WRITERS_KRYLOV		
	};
	const int writers_size = sizeof(writers_children) / sizeof(writers_children[0]);
}

const ule::MenuItem ule::WRITERS {
	"1 - Русские писатели", ule::show_menu, &ule::MAIN, writers_children, writers_size
};
const ule::MenuItem ule::EXIT {
	"0 - Завершить чтение", ule::exit, &ule::MAIN
};

namespace {
	const ule::MenuItem* main_children[] = {
		&ule::EXIT,
		&ule::WRITERS
	};
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const ule::MenuItem ule::MAIN {
	nullptr, ule::show_menu, nullptr, main_children, main_size
};