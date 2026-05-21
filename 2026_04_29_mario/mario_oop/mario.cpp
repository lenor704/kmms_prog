#include "mario.hpp"
#include "brick.hpp"
#include "enemy.hpp"
#include "coin.hpp"

using namespace ule;

Mario::Mario() : Object(), isAlive(true) {
	width = 3;
	height = 3;
	type = '@';
	spawn();
}

void Mario::spawn() {
	x = 39;
	y = 10;
	vertSpeed = 0;
	horizSpeed = 0;
	isFly = true;
	isAlive = true;
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
	isAlive = false;
}

void Mario::vertMovement(Brick* brick, int brickCount) {
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
bool Mario::enemyCollision(Enemy* enemy) {
	return isCollision(*enemy);
}

bool Mario::coinCollision(Coin* coin) {
	return isCollision(*coin);
}

bool Mario::upEnemyCollision(Enemy* enemy) {
	if (isCollision(*enemy)) {
		return isFly == true && vertSpeed > 0 && y + height < enemy->getY() + enemy->getHeight() * 0.5;
	}
	return false;
}

bool Mario::getIsAlive() {
	return isAlive;
}

void Mario::setIsAlive(bool alive) {
	isAlive = alive;
}

void Mario::update() {
	gravity();
}