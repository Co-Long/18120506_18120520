#pragma once
#include<iostream>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
using namespace std;

class Board
{
private:
	int x;
	int y;
	int width;
	int hight;
public:
	Board();
	Board(int x, int y, int w, int h);
	void setSize(int w, int h);
	void setCordinate(int x, int y);
	void draw();
};

