#pragma once
#include "object.hpp"

namespace ule {
	class Enemy : public Object {
		private:
			bool movingRight;
			
		public:
			Enemy();
			~Enemy = default;
			
			void spawn(float xPos, float yPos);
			
			void horizonMovement(Brick* bricks, int brickCount);
			void vertMovement(Brick* bricks, int brickCount);
			
			void update() override;
	};
}