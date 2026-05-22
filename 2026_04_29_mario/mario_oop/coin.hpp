#pragma once
#include "object.hpp"
#include "brick.hpp"

namespace ule{
	class Coin : public Object {
		public:
			Coin();
			~Coin() = default;;
			
			void spawn(float xPos, float yPos);
			
			void horizonMovement(Brick* brick, int brickCount);
            void vertMovement(Brick* brick, int brickCount);
			
			void update() override;
	};
}
