#pragma once
#pragma comment(lib, "graphics.lib")
#include "graphics.h"
#include<cmath>
#include<time.h>

#define pi 3.14159265359

class Ball
{
private:
	int x, y;	//Vị trí của banh
	int originalx, originaly;	//Vị trí ban đầu của banh
	double speed, originalspeed;	//Vận tốc của banh
	double dx, dy;	//Vận tốc theo trục hoành và trục tung
	double alpha;	//Góc giữa vận tốc và trục hoành
	int color;	//Màu của banh
	int r;	//Bán kính của banh
public:
	friend class Match;
	
	Ball();
	Ball(int x, int y, int r, int speed, int color);
	//Trạng thái 
	void reset();
	void draw();
	void erase();
	//Chuyển động
	void move();
	void speedup(double);
	void setSpeed(double);
	void randomDirection(int, int);
};

float ROUND(float x);