#pragma once
#include "graphics.h"
#include<cmath>
#pragma comment(lib, "graphics.lib")
#define pi 3.1415926

class Ball
{
public:
	int x, y;
	int originalx, originaly;
	int speed, originalspeed;
	int dx, dy;
	int color;
	int r;

	Ball();
	Ball(int x, int y, int r, int speed, int color);
	void reset();
	void draw();
	void erase();
	void move();
	void speedup();
	/*int getX();
	int getY();
	int getDX();
	void setDX(int);
	int getDY();
	void setDY(int);*/
	void setSpeed(int);
};

float ROUND(float x);