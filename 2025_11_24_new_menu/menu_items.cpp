#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const ule::MenuItem ule::ALGEBRA_SUMM = {
	"1 - Хочу научиться складывать!", ule::algebra_summ, &ule::STUDY_ALGEBRA
};
const ule::MenuItem ule::ALGEBRA_SUBSTRACT = {
	"2 - Хочу научиться вычитать!", ule::algebra_substract, &ule::STUDY_ALGEBRA
};
const ule::MenuItem ule::ALGEBRA_MULTIPLY = {
	"3 - Хочу научиться умножать!", ule::algebra_multiply, &ule::STUDY_ALGEBRA
};
const ule::MenuItem ule::ALGEBRA_DIVIDE = {
	"4 - Хочу научиться делить!", ule::algebra_divide, &ule::STUDY_ALGEBRA
};
const ule::MenuItem ule::GO_TO_STUDY = {
	"0 - Вернуться к выбору предметов.", ule::study_go_back, &ule::STUDY_ALGEBRA
};

namespace {
	const ule::MenuItem* const algebra_children[] = {
		&ule::GO_TO_STUDY,
		&ule::ALGEBRA_SUMM,
		&ule::ALGEBRA_SUBSTRACT,
		&ule::ALGEBRA_MULTIPLY,
		&ule::ALGEBRA_DIVIDE
	};
	const int algebra_size = sizeof(algebra_children) / sizeof(algebra_children[0]);
}

const ule::MenuItem ule::MATHAN_DIFFUR = {
	"1 - Хочу изучить дифференциальное исчисление!", ule::mathan_diffur, &ule::STUDY_MATHAN
};
const ule::MenuItem ule::MATHAN_INTEGRAL = {
	"2 - Хочу изучить интегральное исчисление!", ule::mat	han_integral, &ule::STUDY_MATHAN
};

namespace {
	const ule::MenuItem* const mathan_children[] = {
		&ule::GO_TO_STUDY,
		&ule::MATHAN_DIFFUR,
		&ule::MATHAN_INTEGRAL
	};
	const int mathan_size = sizeof(mathan_children) / sizeof(mathan_children[0]);
}

const ule::MenuItem ule::STUDY_ALGEBRA = {
    "1 - Хочу изучать алгебру!", ule::show_menu, &ule::STUDY, algebra_children, algebra_size
};
const ule::MenuItem ule::STUDY_MATHAN = {
    "2 - Хочу изучать математический анализ!", ule::show_menu, &ule::STUDY, mathan_children, mathan_size
};
const ule::MenuItem ule::STUDY_GO_BACK = {
    "0 - Выйти в главное меню", ule::study_go_back, &ule::STUDY
};

namespace {
    const ule::MenuItem* const study_children[] = {
        &ule::STUDY_GO_BACK,
        &ule::STUDY_ALGEBRA,
        &ule::STUDY_MATHAN
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const ule::MenuItem ule::STUDY = {
    "1 - Хочу учиться математике!", ule::show_menu, &ule::MAIN, study_children, study_size
};
const ule::MenuItem ule::EXIT = {
    "0 - Я лучше пойду полежу...", ule::exit, &ule::MAIN
};

namespace {
    const ule::MenuItem* const main_chidren[] = {
        &ule::EXIT,
        &ule::STUDY
    };
    const int main_size = sizeof(main_chidren) / sizeof(main_chidren[0]);
}

const ule::MenuItem ule::MAIN = {
    nullptr, ule::show_menu, nullptr, main_chidren, main_size
};