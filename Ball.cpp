#include "Ball.h"

float ROUND(float x) {
	float result;
	if (x >= 0)
		result = floor(x + 0.5);
	if (x < 0)
		result = -floor(-x + 0.5);
	return result;
}

Ball::Ball() {

}

Ball::Ball(int x, int y, int r, int speed, int color) {
	this->x = x; // vi tri truc x
	this->y = y; // vi tri truc y
	originalx = x;
	originaly = y;
	this->r = r; // radius
	this->speed = speed; 
	originalspeed = speed;
	
	this->dx = ROUND(speed * cos(pi/4)); //Huong thay doi truc x
	this->dy = ROUND(speed * sin(pi/4)); //Huong thay doi truc y
	this->color = color;
}

//reset vị trí ban đầu
void Ball::reset() {
	x = originalx;
	y = originaly;
	speed = originalspeed;
}

//Ham ve Ball
void Ball::draw() {
	setcolor(color); //Set color vien
	setfillstyle(1, color); //Set color mien dong
	circle(x, y, r); // ve hinh tron
	floodfill(x, y, color); //to mau vung kin
}

//Xoa ball tai vi tri hien tai
void Ball::erase() {
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	circle(x, y, r);
	floodfill(x, y, BLACK);
}

//Di chuyen ball
void Ball::move() {
		erase();

		x += dx;
		y += dy;

		draw();
}

void Ball::speedup() {
	speed += 1;

	if (dx <= 0 && dy>=0) {
		dx = -ROUND(speed * cos(pi / 4)); 
		dy = ROUND(speed * sin(pi / 4)); 
	}
	else if (dx >= 0 && dy <= 0) {
		dx = ROUND(speed * cos(pi / 4));
		dy = -ROUND(speed * sin(pi / 4));
	}
	else if (dx >= 0 && dy >= 0) {
		dx = ROUND(speed * cos(pi / 4));
		dy = ROUND(speed * sin(pi / 4));
	}
	else if (dx <= 0 && dy <= 0) {
		dx = -ROUND(speed * cos(pi / 4));
		dy = -ROUND(speed * sin(pi / 4));
	}
	
}

//int Ball::getX() {
//	return x;
//}
//
//int Ball::getY() {
//	return y;
//}
//
//int Ball::getDX() {
//	return dx;
//}
//
//void Ball::setDX(int d) {
//	dx = d;
//}
//
//int Ball::getDY() {
//	return dy;
//}
//
//void Ball::setDY(int d) {
//	dy = d;
//}

void Ball::setSpeed(int s) {
	speed = s;
}