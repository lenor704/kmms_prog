#include "brick.hpp"

using namespace ule::Brick;

Brick::Brick() : Object(),  {
	vertSpeed = 0;
	horizSpeed = 0;
	isFly = false;
	type = '#';
	brickTtype = BrickType::BRICK;
	wasHit = false;
}

void Brick::spawn(float xPos, float yPos, float newWidth, float newHeight, BrickType bType) {
	x = xPos;
	y = yPos;
	width = newWidth;
	height = newHeight;
	brickType = bType;
	
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
	if (type == BrickType::MISTERY_BOX && !wasHit) {
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