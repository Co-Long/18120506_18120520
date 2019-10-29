#include "Ball.h"

//Hàm làm tròn số
float ROUND(float x) {
	float result;
	if (x >= 0)
		result = floor(x + 0.5);
	if (x < 0)
		result = -floor(-x + 0.5);
	return result;
}

Ball::Ball() {
	x = y = 0;
	originalx = originaly = 0;
	r = 0; // radius
	originalspeed = speed=0;
	dx = dy = 0;
	alpha = 0;
	color = WHITE;
}

Ball::Ball(int x, int y, int r, int speed, int color) {
	this->x = x; // vi tri truc x
	this->y = y; // vi tri truc y
	originalx = x;
	originaly = y;
	this->r = r; // radius

	alpha = pi / 4;
	this->speed = speed; 
	originalspeed = speed;

	this->dx = ROUND(speed * cos(alpha)); //Vận tốc trên trục hoành
	this->dy = ROUND(speed * sin(alpha)); //Vận tốc trên trục tung

	this->color = color;
}

//reset vị trí ban đầu
void Ball::reset() {
	x = originalx;
	y = originaly;
	alpha = pi / 4;
	speed = originalspeed;
	dx = ROUND(speed * cos(alpha));
	dy = ROUND(speed * sin(alpha));
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

//Hàm tăng tốc banh, Input: độ lệch vận tốc
void Ball::speedup(double dSpeed) {
	speed += dSpeed;

	if (dx <= 0 && dy>=0) {
		dx = -ROUND(speed * cos(alpha*pi/180)); 
		dy = ROUND(speed * sin(alpha * pi / 180));
	}
	else if (dx >= 0 && dy <= 0) {
		dx = ROUND(speed * cos(alpha * pi / 180));
		dy = -ROUND(speed * sin(alpha * pi / 180));
	}
	else if (dx >= 0 && dy >= 0) {
		dx = ROUND(speed * cos(alpha * pi / 180));
		dy = ROUND(speed * sin(alpha * pi / 180));
	}
	else if (dx <= 0 && dy <= 0) {
		dx = -ROUND(speed * cos(alpha * pi / 180));
		dy = -ROUND(speed * sin(alpha * pi / 180));
	}
	
}

void Ball::setSpeed(double s) {
	speed = s;
}

//Tạo ra góc alpha ngẫu nhiên trong khoảng min, max (Đơn vị: Độ)
void Ball::randomDirection(int min, int max) {
	srand(time(NULL));
	alpha = (min + rand() % (max+1));
}