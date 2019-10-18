#pragma once
#include "graphics.h"
#pragma comment(lib, "graphics.lib")

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
	Ball(int x, int y, int r, int speed, int dx, int dy, int color);
	void reset();
	void draw();
	void erase();
	void move(int top, int bottom, int left, int right);
};

