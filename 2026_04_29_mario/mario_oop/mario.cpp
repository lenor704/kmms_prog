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

void Mario::jump() {
	vertSpeed = -1;
	isFly = true;
}

void Mario::gravity() {
	isFly = true;
	vertSpeed += 0.05;
	setPosition(x, y + vertSpeed);
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