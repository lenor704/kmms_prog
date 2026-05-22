#pragma once
#include "object.hpp"
#include "brick.hpp"
#include "enemy.hpp"
#include "coin.hpp"

namespace ule {
	class Brick;
	class Enemy;
	class Coin;
	
	class Mario : public Object {
		private:
			bool isAlive;
			float prevY;
			int hitBrickFromBelow;
            bool reachedFinish;
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
			float getPrevY();
			int getHitBrickFromBelow();
            bool getReachedFinish();
			
			void setIsAlive(bool alive);
			
			void update() override;
	};
}