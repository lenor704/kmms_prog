#include "mario.hpp"
#include "brick.hpp"
#include "enemy.hpp"
#include "coin.hpp"


using namespace ule;

Mario::Mario() : Object(), isAlive(true), hitBrickFromBelow(-1), reachedFinish(false) {
	width = 3;
	height = 3;
	type = '@';
	spawn();
}

void Mario::spawn() {
	prevY = y;
	x = 39;
	y = 10;
	vertSpeed = 0;
	horizSpeed = 0;
	isFly = true;
	isAlive = true;
	isActive = true;
	hitBrickFromBelow = -1;
    reachedFinish = false;
}

void Mario::jump() {
	vertSpeed = -1.5;
	isFly = true;
}

void Mario::gravity() {
	vertSpeed += 0.05;
}

void Mario::death() {
	isAlive = false;
}

void Mario::vertMovement(Brick* brick, int brickCount) {
	prevY = y;
    isFly = true;
    vertSpeed += 0.05;
	hitBrickFromBelow = -1;
	reachedFinish = false;
    setPosition(x, y + vertSpeed);
    
    for (int i = 0; i < brickCount; i++) {
        if (isCollision(brick[i])) {
            if (vertSpeed > 0) {
                isFly = false;
            } else if (vertSpeed < 0) {
                hitBrickFromBelow = i;
            }
			if (brick[i].isFinish()) {
                reachedFinish = true;
            }
            y -= vertSpeed;
            vertSpeed = 0;
			break;
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

float Mario::getPrevY() {
	return prevY;
}

int Mario::getHitBrickFromBelow() {
    return hitBrickFromBelow;
}

bool Mario::getReachedFinish() {
    return reachedFinish;
}

void Mario::setIsAlive(bool alive) {
	isAlive = alive;
}

void Mario::update() {
	gravity();
}