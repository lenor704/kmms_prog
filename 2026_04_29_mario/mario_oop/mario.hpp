#pragma once
#include "object.hpp"

namespace ule {
	class Brick;
	class Enemy;
	class Coin;
	
	class Mario : public Object {
		private:
			bool isAlive;
		public:
			Mario();
			~Mario() = default;
			
			void spawn();
			
			void jump();
			void gravity();
			void death();
			
			void vertMovement(Brick* bricks, int brickCount);
			
			bool enemyCollision(Enemy* enemy);
			bool coinCollision(Coin* coin);
			bool upEnemyCollision(Enemy* enemy);
			
			bool getIsAlive();
			void setIsAlive(bool alive);
			
			void update() override;
	};
}