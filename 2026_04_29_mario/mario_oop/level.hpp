#pragma once

#include "brick.hpp"
#include "enemy.hpp"
#include "coin.hpp"

namespace ule {
	class Level {
		private:
			int level;
			
			Brick* brick;
			Enemy* enemy;
			Coin* coin;
			
			int brickCount;
            int enemyCount;
            int coinCount;
			
			void addBrick(float x, float y, float w, float h, BrickType type);
			void addEnemy(float x, float y);
		public:
			Level();
			~Level;
			
			void load(int number);
			void update();
			void spawnCoin(float x, float y);
			void removeEnemy(int index);
			void removeCoin(int index);
			
			Brick* getBricks();
			Enemy* getEnemies();
			Coin* getCoins();
			
			int getBrickCount();
			int getEnemyCount();
			int getCoinCount();
			int getNumber();
	};
}