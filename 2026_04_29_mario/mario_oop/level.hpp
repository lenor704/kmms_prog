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
		public:
			Level();
			~Level();
			
			void clear();
			void load(int number);
			void update();
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