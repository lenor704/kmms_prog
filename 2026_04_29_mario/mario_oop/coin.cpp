#include "coin.hpp"
#include "mapSize.hpp"

using namespace ule;

Coin::Coin() : Object() {
    width = 3;
    height = 2;
    type = '$';
    vertSpeed = -0.7;
    horizSpeed = 0.2;
    isFly = true;
}

void Coin::spawn(float xPos, float yPos) {
    x = xPos;
    y = yPos - 3;
    vertSpeed = -0.7;
	horizSpeed = 0.2;
	isActive = true;
}

void Coin::horizonMovement(Brick* brick, int brickCount) {
    x += horizSpeed;
    
    for (int i = 0; i < brickCount; i++) {
        if (isCollision(brick[i])) {
            x -= horizSpeed;
            horizSpeed = -horizSpeed;
            return;
        }
    }
}

void Coin::vertMovement(Brick* brick, int brickCount) {
    isFly = true;
    vertSpeed += 0.05;
    y += vertSpeed;
    
    for (int i = 0; i < brickCount; i++) {
        if (isCollision(brick[i])) {
            if (vertSpeed > 0) {
                isFly = false;
            }
            y -= vertSpeed;
            vertSpeed = 0;
        }
    }
    
    if (y > mapHeight) {
        isActive = false;
    }
}

void Coin::update() {}