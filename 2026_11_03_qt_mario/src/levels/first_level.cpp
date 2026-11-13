#include "first_level.hpp"

#include "second_level.hpp"

using biv::FirstLevel;

FirstLevel::FirstLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

biv::GameLevel* FirstLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::SecondLevel(ui_factory);
	}
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void FirstLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	ui_factory->create_ship({20, 20}, 40, 2);
	
	ui_factory->create_full_box({30, 10}, 5, 3);
	ui_factory->create_full_box({50, 10}, 5, 3);
	
	ui_factory->create_ship({60, 15}, 40, 7);
	
	ui_factory->create_box({60, 5}, 10, 3);
	ui_factory->create_full_box({70, 5}, 5, 3);
	ui_factory->create_box({75, 5}, 5, 3);
	ui_factory->create_full_box({80, 5}, 5, 3);
	ui_factory->create_box({85, 5}, 10, 3);
	
	ui_factory->create_ship({100, 20}, 20, 2);
	ui_factory->create_ship({120, 15}, 10, 7);
	ui_factory->create_ship({150, 20}, 40, 2);
	ui_factory->create_ship({210, 15}, 15, 7);
	
	ui_factory->create_enemy({25, 18}, 3, 2);
	ui_factory->create_enemy({32, 18}, 3, 2);
	ui_factory->create_enemy({70, 13}, 3, 2);
	ui_factory->create_enemy({82, 13}, 3, 2);
	ui_factory->create_enemy({126, 13}, 3, 2);
	ui_factory->create_enemy({160, 18}, 3, 2);
	
	ui_factory->create_fly_enemy({18, 8}, 3, 3, 18 - 15, 18 + 15);
	ui_factory->create_fly_enemy({108, 12}, 3, 3, 108 - 15, 108 + 15);
	ui_factory->create_fly_enemy({136, 7}, 3, 3, 136 - 15, 136 + 15);
	
	ui_factory->create_jump_enemy({45, 18}, 3, 2);
	ui_factory->create_jump_enemy({95, 13}, 3, 2);
	ui_factory->create_jump_enemy({175, 18}, 3, 2);
}
