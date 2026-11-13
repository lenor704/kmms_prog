#include "third_level.hpp"

#include "second_level.hpp"

using biv::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

biv::GameLevel* SecondLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::ThirdLevel(ui_factory);
	}
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void SecondLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	ui_factory->create_ship({20, 20}, 40, 2);
	ui_factory->create_ship({60, 15}, 10, 7);
	ui_factory->create_ship({80, 20}, 20, 2);
	
	ui_factory->create_moving_platform({101, 20}, 8, 2, 101, 112);
	ui_factory->create_moving_platform({131, 20}, 8, 2, 131, 142);
	
	ui_factory->create_ship({120, 15}, 10, 7);
	ui_factory->create_ship({150, 20}, 40, 2);
	ui_factory->create_ship({210, 15}, 10, 7);
}
