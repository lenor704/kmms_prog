#pragma once
#include "object.hpp"
#include "brick.hpp"
#include "coin.hpp"
#include "enemy.hpp"

namespace ule {
	class Mario : public Object {
		public:
			Mario();
			~Mario() = default;
			
			void spawn();
			
			void jump();
			void gravity();
			void death();
			
			void vertMovement(Brick* bricks, int brickCount);
			void moveLeft(Brick* bricks, int brickCount);
			void moveRight(Brick* bricks, int brickCount);
			
			bool enemyCollision(Enemy* enemy);
			bool coinCollision(Coin* coin);
			bool upEnemyCollision(Enemy* enemy);
			
			void update() override;
		};
}