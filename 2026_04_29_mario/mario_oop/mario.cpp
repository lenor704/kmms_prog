#include "mario.hpp"
#include "level.hpp"

using namespace ule::Mario;

Mario::Mario() : Object() {
	x = 39;
	y = 10;
	width = 3;
	height = 3;
	type = '@';
	vertSpeed = 0;
	horizSpeed = 0;
	isFly = true;
}

void Mario::spawn() {
	x = 39;
	y = 10;
	vertSpeed = 0;
	horizSpeed = 0;
	isFly = true;
}

void Mario::jump() {
	if (!isFly) {
		vertSpeed = -1;
		isFly = true;
	}
}

void Mario::gravity() {
	vertSpeed += 0.05;
}

void Mario::death() {
	system("color 4F");
	Sleep(500);
	createLevel(level, &mario, 
				brick, brickLength, 
				moving, movingLength, 
				score, maxLvl);     //!!!!!!!!!!!!!!!!!!!
}

bool Mario::isFly() {
	return isFly;
}

void Mario:setVertSpeed(float speed) {
	vertSpeed = speed;
}

void Mario::setIsFly(bool fly) {
	isFly = fly;
}

void Mario::vertMovement(Brick* bricks, int brickCount) {
	isFly = true;
	vertSpeed += 0.05;
	setPosition(x, y + vertSpeed);
	
	for (int i = 0; i < brickCount; i++) {
		if (isCollision(brick[i])) {
			if (vertSpeed > 0) {
				isFly = false;
			}
			y = vertSpeed;
			vertSpeed = 0;
		}	
	}	
}

void Mario::moveLeft(Brick* bricks, int brickCount) {
	x -= 1;
	
	for (int i = 0; i < brickCount; i++) {
		if (isCollision(brick[i])) {
			x += 1;
			return;
		}
	}
}

void Mario::moveRight(Brick* bricks, int brickCount) {
	x += 1;
	
	for (int i = 0; i < brickCount; i++) {
		if (isCollision(brick[i])) {
			x -= 1;
			return;
		}
	}
}

bool Mario::enemyCollision(Enemy* enemy) {
	return isCollision(*enemy);
}

bool Mario::coinCollision(Coin* coin) {
	return isCollision(*coin);
}

bool Mario::upEnemyCollision(Enemy* enemy) {
	if (isCollision(*enemy)) {
		return isFly == true && vertSpeed > 0 && y + height < enemy.y() + enemy.getHeight() * 0.5;
	}
}

void Mario::update() {
	gravity();
}