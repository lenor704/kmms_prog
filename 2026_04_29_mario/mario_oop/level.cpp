#include "level.hpp"

using namespace ule;

Level::Level() {
	level = 1;
	brickCount = 0;
	enemyCount = 0;
	coinCount = 0;
}

Level::~Level() {
	clear();
}

void Level::clear() {
    for (int i = 0; i < brickCount; i++) {
        brick[i].deactivate();
    }
    for (int i = 0; i < enemyCount; i++) {
        enemy[i].deactivate();
    }
    for (int i = 0; i < coinCount; i++) {
        coin[i].deactivate();
    }
    
    brickCount = 0;
    enemyCount = 0;
    coinCount = 0;
}

void Level::load(int number) {
    clear();
    level = number;
    
    switch (number) {
        case 1:
            addBrick(20, 20, 40, 5, BrickType::BRICK);
			addBrick(30, 10, 5, 3, BrickType::MISTERY_BOX);
			addBrick(50, 10, 5, 3, BrickType::MISTERY_BOX);
			addBrick(60, 15, 40, 10, BrickType::BRICK);
			addBrick(60, 5, 10, 3, BrickType::EMPTY_BOX);
			addBrick(70, 5, 5, 3, BrickType::MISTERY_BOX);
			addBrick(75, 5, 5, 3, BrickType::EMPTY_BOX);
			addBrick(80, 5, 5, 3, BrickType::MISTERY_BOX);
			addBrick(85, 5, 10, 3, BrickType::EMPTY_BOX);
			addBrick(100, 20, 20, 5, BrickType::BRICK);
			addBrick(120, 15, 10, 10, BrickType::BRICK);
			addBrick(150, 20, 40, 5, BrickType::BRICK);
			addBrick(210, 15, 10, 10, BrickType::NEXT_LVL);
			
			addEnemy(25, 10);
			addEnemy(80, 10);
            break;
        case 2:
			addBrick(20, 20, 40, 5, BrickType::BRICK);
			addBrick(60, 15, 10, 10, BrickType::BRICK);
			addBrick(80, 20, 20, 5, BrickType::BRICK);
			addBrick(120, 15, 10, 10, BrickType::BRICK);
			addBrick(150, 20, 40, 5, BrickType::BRICK);
			addBrick(210, 15, 10, 10, BrickType::NEXT_LVL);
			
			addEnemy(25, 10);
			addEnemy(80, 10);
			addEnemy(65, 10);
			addEnemy(120, 10);
			addEnemy(160, 10);
			addEnemy(175, 10);
            break;
        case 3:
            addBrick(20, 20, 40, 5, BrickType::BRICK);
			addBrick(80, 20, 15, 5, BrickType::BRICK);
			addBrick(120, 15, 15, 10, BrickType::BRICK);
			addBrick(160, 10, 15, 15, BrickType::NEXT_LVL);
			
			addEnemy(25, 10);
			addEnemy(50, 10);
			addEnemy(80, 10);
			addEnemy(90, 10);
			addEnemy(120, 10);
			addEnemy(130, 10);
            break;
        default:
            break;
    }
}

void Level::addBrick(float x, float y, float w, float h, BrickType type) {
    brick[brickCount].spawn(x, y, w, h, type);
    brickCount++;
}

void Level::addEnemy(float x, float y) {
    enemy[enemyCount].spawn(x, y);
	enemyCount++;
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
            coin[i].update();
        }
    }
}

void Level::spawnCoin(float x, float y) {
    coin[coinCount].spawn(x, y);
    coinCount++;
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