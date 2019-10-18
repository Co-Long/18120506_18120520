#pragma once
#include<iostream>
#include"Process.h"
#include "graphics.h"
#pragma comment(lib, "graphics.lib")

class Bar
{
private:
	int x, y;
	int originalX, originalY;
	int length;
public:
	Bar();
	Bar(int x, int y, int length);
	void reset();
	void setLength(int len);
	int getXPos();
	int getYPos();
	void moveUp();
	void moveDown();
	void draw();

};

