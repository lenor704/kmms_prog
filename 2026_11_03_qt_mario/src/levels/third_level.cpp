#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool ThirdLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* ThirdLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void ThirdLevel::init_data() {
	ui_factory->create_mario({39, 8}, 3, 3);
	
	ui_factory->create_ship({20, 20}, 30, 2);
	
	ui_factory->create_box({25, 12}, 10, 3);
	ui_factory->create_full_box({38, 12}, 5, 3);
	
	ui_factory->create_ship({55, 15}, 10, 7);
	ui_factory->create_ship({70, 20}, 25, 2);
	
	ui_factory->create_moving_platform({100, 20}, 10, 2, 100, 114);
	
	ui_factory->create_ship({125, 15}, 12, 7);
	ui_factory->create_ship({142, 20}, 20, 2);
	
	ui_factory->create_box({145, 15}, 10, 3);
	ui_factory->create_box({155, 10}, 8, 3);
	
	ui_factory->create_moving_platform({167, 20}, 8, 2, 167, 176);
	
	ui_factory->create_ship({185, 15}, 15, 7);
	ui_factory->create_ship({205, 20}, 20, 2);
	
	ui_factory->create_box({210, 15}, 10, 3);
	
	ui_factory->create_ship({230, 15}, 15, 7);
	
	ui_factory->create_enemy({28, 18}, 3, 2);
	ui_factory->create_enemy({75, 18}, 3, 2);
	ui_factory->create_enemy({150, 18}, 3, 2);
	ui_factory->create_enemy({212, 18}, 3, 2);
	
	ui_factory->create_fly_enemy({60, 8}, 3, 3, 60 - 20, 60 + 20);
	ui_factory->create_fly_enemy({133, 10}, 3, 3, 133 - 20, 133 + 20);
	ui_factory->create_fly_enemy({196, 8}, 3, 3, 196 - 20, 196 + 20);
	
	ui_factory->create_jump_enemy({80, 18}, 3, 2);
	ui_factory->create_jump_enemy({172, 18}, 3, 2);
}