#pragma once
#include<iostream>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
using namespace std;

class Board
{
private:
	int x;	//Hoành độ của bảng
	int y;	//Tung độ của bảng
	int width; //Chiều rộng
	int height; //Chiều dài
public:
	Board();
	Board(int x, int y, int w, int h);
	void setSize(int w, int h);
	void setCordinate(int x, int y);
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	void draw();
};

