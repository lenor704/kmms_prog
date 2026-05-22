#include "level.hpp"
#include <windows.h>

using namespace ule;

Level::Level() {
	level = 1;
	brickCount = 0;
	enemyCount = 0;
	coinCount = 0;
	
	brick = nullptr;
    enemy = nullptr;
    coin = nullptr;
}

Level::~Level() {
	clear();
}

void Level::clear() {	
    if (brick != nullptr) {
        delete[] brick;
        brick = nullptr;
    }
    
    if (enemy != nullptr) {
        delete[] enemy;
        enemy = nullptr;
    }
    
    if (coin != nullptr) {
        delete[] coin;
        coin = nullptr;
    }
    
    brickCount = 0;
    enemyCount = 0;
    coinCount = 0;
}

void Level::load(int number) {
	system("color 9F");
    clear();
    level = number;
	coinSpawned = 0;
	int i;
    
    switch (level) {
        case 1:
			brickCount = 13;
			brick = new Brick[brickCount];
			
			i = 0;
            brick[i++].spawn(20, 20, 40, 5, BrickType::BRICK);
			brick[i++].spawn(30, 10, 5, 3, BrickType::MISTERY_BOX);
			brick[i++].spawn(50, 10, 5, 3, BrickType::MISTERY_BOX);
			brick[i++].spawn(60, 15, 40, 10, BrickType::BRICK);
			brick[i++].spawn(60, 5, 10, 3, BrickType::EMPTY_BOX);
			brick[i++].spawn(70, 5, 5, 3, BrickType::MISTERY_BOX);
			brick[i++].spawn(75, 5, 5, 3, BrickType::EMPTY_BOX);
			brick[i++].spawn(80, 5, 5, 3, BrickType::MISTERY_BOX);
			brick[i++].spawn(85, 5, 10, 3, BrickType::EMPTY_BOX);
			brick[i++].spawn(100, 20, 20, 5, BrickType::BRICK);
			brick[i++].spawn(120, 15, 10, 10, BrickType::BRICK);
			brick[i++].spawn(150, 20, 40, 5, BrickType::BRICK);
			brick[i++].spawn(210, 15, 10, 10, BrickType::NEXT_LVL);
			
			enemyCount = 2;
			enemy = new Enemy[enemyCount];
			
			i = 0;
			enemy[i++].spawn(25, 10);
			enemy[i++].spawn(80, 10);
			
			coinCount = 4;
            coin = new Coin[coinCount];
            break;
        case 2:
			brickCount = 6;
			brick = new Brick[brickCount];
			
			i = 0;
			brick[i++].spawn(20, 20, 40, 5, BrickType::BRICK);
			brick[i++].spawn(60, 15, 10, 10, BrickType::BRICK);
			brick[i++].spawn(80, 20, 20, 5, BrickType::BRICK);
			brick[i++].spawn(120, 15, 10, 10, BrickType::BRICK);
			brick[i++].spawn(150, 20, 40, 5, BrickType::BRICK);
			brick[i++].spawn(210, 15, 10, 10, BrickType::NEXT_LVL);
			
			enemyCount = 6;
			enemy = new Enemy[enemyCount];
			
			i = 0;
			enemy[i++].spawn(25, 10);
			enemy[i++].spawn(80, 10);
			enemy[i++].spawn(65, 10);
			enemy[i++].spawn(120, 10);
			enemy[i++].spawn(160, 10);
			enemy[i++].spawn(175, 10);
			
			coinCount = 0;
            coin = nullptr;
            break;
        case 3:
			brickCount = 4;
			brick = new Brick[brickCount];
		
			i = 0;
            brick[i++].spawn(20, 20, 40, 5, BrickType::BRICK);
			brick[i++].spawn(80, 20, 15, 5, BrickType::BRICK);
			brick[i++].spawn(120, 15, 15, 10, BrickType::BRICK);
			brick[i++].spawn(160, 10, 15, 15, BrickType::NEXT_LVL);
			
			enemyCount = 6;
			enemy = new Enemy[enemyCount];
			
			i = 0;
			enemy[i++].spawn(25, 10);
			enemy[i++].spawn(50, 10);
			enemy[i++].spawn(80, 10);
			enemy[i++].spawn(90, 10);
			enemy[i++].spawn(120, 10);
			enemy[i++].spawn(130, 10);
			
			coinCount = 0;
            coin = nullptr;
            break;
        default:
            break;
    }
}

void Level::update() {
    for (int i = 0; i < enemyCount; i++) {
        if (enemy[i].getIsActive()) {
            enemy[i].vertMovement(brick, brickCount);
            enemy[i].horizonMovement(brick, brickCount);
        }
    }
    
    for (int i = 0; i < coinCount; i++) {
        if (coin[i].getIsActive()) {
            coin[i].vertMovement(brick, brickCount);
            coin[i].horizonMovement(brick, brickCount);
        }
    }
}

void Level::spawnCoin(float x, float y) {
    if (coinSpawned < coinCount) {
        coin[coinSpawned].spawn(x, y);
        coinSpawned++;
    }
}

void Level::removeEnemy(int index) {
    if (index >= 0 && index < enemyCount) {
        enemy[index].deactivate();
    }
}

void Level::removeCoin(int index) {
    if (index >= 0 && index < coinCount) {
        coin[index].deactivate();
    }
}

Brick* Level::getBricks() {
	return brick;
}

Enemy* Level::getEnemies() {
	return enemy;
}

Coin* Level::getCoins() {
	return coin;
}
			
int Level::getBrickCount() {
	return brickCount;
}

int Level::getEnemyCount() {
	return enemyCount;
}

int Level::getCoinCount() {
	return coinCount;
}

int Level::getNumber() {
	return level;
}