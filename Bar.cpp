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

int Bar::getLength() {
	return length;
}

int Bar::getXPos() {
	return x;
}

int Bar::getYPos() {
	return y;
}

void Bar::moveUp(int distance) {
	y-=distance;
}

void Bar::moveDown(int distance) {
	y+= distance;
}

void Bar::draw() {
	setcolor(WHITE);
	setlinestyle(0, 0, 2);
	line(x, y, x, y + length);

}

void Bar::erase() {
	setlinestyle(0, 0, 2);
	setcolor(BLACK);
	line(x, y, x, y + length);
}
