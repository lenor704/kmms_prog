#include "enemy.hpp"
#include "brick.hpp"

using namespace ule;

Enemy::Enemy() : Object(), movingRight(true) {
	width = 3;
	height = 2;
	type = 'o';
	isFly = true;
	horizSpeed = 0.2;
	vertSpeed = 0;
}

void Enemy::spawn(float xPos, float yPos) {
	x = xPos;
	y = yPos;
}

void Enemy::horizonMovement(Brick* brick, int brickCount) {
	x += horizSpeed;
	
	for (int i = 0; i < brickCount; i++) {
		if (isCollision(brick[i])) {
			x -= horizSpeed;
			horizSpeed = -horizSpeed;
			return;
		}
	}
	
	Object tmp;
	tmp.init(movingRight ? (x + 1) : (x - 1), y, 1, 1, ' ');
	if (tmp.getIsFly() == true) {
		x -= horizSpeed;
		horizSpeed = -horizSpeed;
	}
}

void Enemy::vertMovement(Brick* brick, int brickCount) {
	isFly = true;
	vertSpeed += 0.05;
	setPosition(x, y + vertSpeed);
	
	for (int i = 0; i < brickCount; i++) {
		if (isCollision(brick[i])) {
			if (vertSpeed > 0) {
				isFly = false;
			}
			
			y -= vertSpeed;
			vertSpeed = 0;
		}
	}
}

void Enemy::update() {}