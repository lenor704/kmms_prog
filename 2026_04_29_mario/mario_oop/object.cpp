#include "object.hpp"

using ule::Object;

Object::Object() {
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	vertSpeed = 0;
	horizSpeed = 0;
	isFly = true;
	type = ' ';
	
}

void Object::init(float xPos, float yPos, float w, float h, char newType) {	
	x = xPos;
	y = yPos;
	width = w;
	height = h;
	type = newType;
}

float Object::getX() const {
	return x;
}

void Object::setX(float newX) {
	x = newX;
}

float Object::getY() const {
	return y;
}

void Object::setY(float newY) {
	y = newY;
}

float Object::getHeight() const {
	return height;
}

void Object::setHeight(float newHeight) {
	height = newHeight;
}

float Object::getWidth() const {
	return width;
}

void Object::setWidth(float newWidth) {
	width = newWidth;
}

float Object::getVertSpeed() const {
	return vertSpeed;
}

void Object::setVertSpeed(float speed) {
	vertSpeed = speed;
}

char Object::getType() const {
	return type;
}

void Object::setPosition(float xPos, float yPos) {
	x = xPos;
	y = yPos;
}

void Object::setIsFly(bool fly) {
	isFly = fly;
}
bool Object::getIsFly() const {
	return isFly;
}

bool Object::getIsActive() const {
	return isActive;
}

void Object::setIsActive(bool active) {
	isActive = active;
}

void Object::deactivate() {
	isActive = false;
}

bool Object::isCollision(const Object& other) const {
		return x + width > other.getX() && x < other.getX() + other.getWidth() &&
		   y + height > other.getY() && y < other.getY() + other.getHeight();
}

