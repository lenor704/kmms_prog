#include "coin.hpp"

using namespace ule;

Coin::Coin() : Object() {
    width = 3;
    height = 2;
    type = '$';
    vertSpeed = -0.7;
    horizSpeed = 0;
    isFly = true;
	isActive = false;
}

void Coin::spawn(float xPos, float yPos) {
    x = xPos;
    y = yPos - 3;
    vertSpeed = -0.7;
	isActive = true;
}

void Coin::update() {
    vertSpeed += 0.05;
    y += vertSpeed;
}