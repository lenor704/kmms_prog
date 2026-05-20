#pragma once
#include "object.hpp"

class Coin : public GameObject {
	public:
		Coin();
		~Coin() = default;;
		
		void spawn(float xPos, float yPos);
		
		void update() override;
};