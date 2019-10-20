#pragma once
#include<iostream>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")

class Bar
{
private:
	int x, y;	//Vị trí của thanh
	int originalX, originalY;	//Vị trí ban đầu
	int length;	//Chiều dài thanh
public:
	Bar();
	Bar(int x, int y, int length);
	void reset();
	void setLength(int len);
	int getLength();
	int getXPos();
	int getYPos();
	void moveUp(int distance);
	void moveDown(int distance);
	void draw();
	void erase();
};

