#include "brick.hpp"

using namespace ule;

Brick::Brick() : Object(), brickType(BrickType::BRICK), wasHit(false) {
	vertSpeed = 0;
	horizSpeed = 0;
	isFly = false;
	type = '#';
}

void Brick::spawn(float xPos, float yPos, float newWidth, float newHeight, BrickType bType) {
	x = xPos;
	y = yPos;
	width = newWidth;
	height = newHeight;
	brickType = bType;
	isActive = true;
	
	switch (brickType) {
        case BrickType::BRICK:
            type = '#';
            break;
        case BrickType::MISTERY_BOX:
            type = '?';
            break;
        case BrickType::EMPTY_BOX:
            type = '-';
            break;
        case BrickType::NEXT_LVL:
            type = '+';
            break;
    }
}

bool Brick::hit() {
	if (brickType == BrickType::MISTERY_BOX && !wasHit) {
		toEmpty();
		wasHit = true;
		return true;
	}
	return false;
}

void Brick::toEmpty() {
	brickType = BrickType::EMPTY_BOX;
	type = '-';
}

BrickType Brick::getType() {
	return brickType;
}

bool Brick::isFinish() {
	return brickType == BrickType::NEXT_LVL;
}

bool Brick::getWasHit() {
	return wasHit;
}