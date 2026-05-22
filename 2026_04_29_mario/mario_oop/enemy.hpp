#pragma once
#include "object.hpp"
#include "brick.hpp"

namespace ule {
	class Brick;
	
	class Enemy : public Object {
		private:
			bool movingRight;
			
		public:
			Enemy();
			~Enemy() = default;
			
			void spawn(float xPos, float yPos);
			
			void horizonMovement(Brick* bricks, int brickCount);
			void vertMovement(Brick* bricks, int brickCount);
			
			void update() override;
	};
}