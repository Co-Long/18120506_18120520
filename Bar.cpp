#include "Bar.h"
using namespace std;

Bar::Bar() {
	x = y = 0;
	originalX = originalY = 0;
	length = 50;
}

Bar::Bar(int x, int y, int length) {
	this->x = x;
	this->y = y;
	originalX = x;
	originalY = y;
	this->length = length;
}

void Bar::reset() {
	x = originalX;
	y = originalY;
}

void Bar::setLength(int len) {
	length = len;
}

int Bar::getXPos() {
	return x;
}

int Bar::getYPos() {
	return y;
}

void Bar::moveUp() {
	y--;
}

void Bar::moveDown() {
	y++;
}

void Bar::draw() {

	setlinestyle(0, 0, 2);
	line(x, y, x, y+length);

}