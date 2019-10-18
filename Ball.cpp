#include "Ball.h"

Ball::Ball() {

}

Ball::Ball(int x, int y, int r, int speed, int dx, int dy, int color) {
	this->x = x; // vi tri truc x
	this->y = y; // vi tri truc y
	originalx = x;
	originaly = y;
	this->r = r; // radius
	this->speed = speed; 
	originalspeed = speed;
	this->dx = dx; //Huong thay doi truc x
	this->dy = dy; //Huong thay doi truc y
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
void Ball::move(int top, int bottom, int left, int right) {
		if (x + r >= right || x - r <= left) dx = -dx;
		if (y + r >= bottom || y - r <= top) dy = -dy;
		x += dx;
		y += dy;
		draw();
		delay(100 - speed);
		erase();
}