#include "object.hpp"

using ule::Object;

Object::Object(float width, float height, float vertSpeed, float horixSpeed, char type) 
			  : width(width), height(height), vertSpeed(vertSpeed), horixSpeed(horixSpeed), type(type) 
			  {
}

float Object::x() {
	return x;
}

float Object::y() {
	return y;
}

float Object::getHeight() {
	return height;
}

float Object::getWidth() {
	return width;
}

void Object::setPositon(float x, float y) : x(x), y(y) {
}

bool Object::isCollision(Object& other) {
		return x + width > other.x() && x < other.x() + other.getWidth() &&
		   y + height > other.y() && y < other.y() + other.getHeight();
}

void Object::draw(Show& showing) {
	showing.drawObject(*this);
}
