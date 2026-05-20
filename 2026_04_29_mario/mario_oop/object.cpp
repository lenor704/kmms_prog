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

void Object::init(float x, float y, float width, float height, char type)
	: x(x),
	y(y),
	width(width),
	height(height),
	type(type)
{	
}

float Object::x() {
	return x;
}

void Object::setX(float newX) {
	x = newX;
}

float Object::y() {
	return y;
}

void Object::setY(float newY) {
	y = newY;
}

float Object::getHeight() {
	return height;
}

void Object::setHeight(float newHeight) {
	height = newHeight;
}

float Object::getWidth() {
	return width;
}

void Object::setWidth(float newWidth) {
	width = newWidth;
}

char Object::getType() {
	return type;
}

void Object::setPositon(float x, float y) : x(x), y(y) {
}

bool Object::getIsActive() {
	return isActive;
}

void Object::setIsActive(bool active) {
	isActive = active;
}

void Object::deactivate() {
	isActive = false;
}

bool Object::isCollision(Object& other) {
		return x + width > other.x() && x < other.x() + other.getWidth() &&
		   y + height > other.y() && y < other.y() + other.getHeight();
}

void Object::draw(Show& showing) {
	showing.drawObject(*this);
}
