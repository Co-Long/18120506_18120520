#include "Board.h"
using namespace std;

Board::Board() {
	x = y = 0;
	width = height = 0;
}

Board::Board(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h;
}

void Board::setSize(int w, int h) {
	width = w;
	height = h;
}

void Board::setCordinate(int x, int y) {
	this->x = x;
	this->y = y;
}

int Board::getX() {
	return x;
}

int Board::getY() {
	return y;
}

int Board::getWidth() {
	return width;
}

int Board::getHeight() {
	return height;
}

//void Board::draw(int col) {
//	//Độ rộng của mỗi cột
//	int wid = (width / col)+1;
//	
//	//Biên trên
//	GotoXY(x, y);
//	for (int i = 0; i < width+2; i++)
//	{
//		cout << "\xDB";
//	}
//
//	for (int j = 1; j < col; j++) {
//		for (int i = 0; i < height + 1; i++) {
//			GotoXY(x+wid*j, y + 1 + i);
//			cout << "\xB3";
//		}
//	}
//
//	//Biên trái
//	for (int i = 0; i < height+1; i++) {
//		GotoXY(x, y+1+i);
//		cout << "\xDB";
//	}
//	//Biên phải
//	for (int i = 0; i < height+1; i++) {
//		GotoXY(x+width+1, y + 1 + i);
//		cout << "\xDB";
//	}
//	//Biên dưới
//	GotoXY(x, y+height+1);
//	for (int i = 0; i < width+2; i++)
//	{
//		cout << "\xDB";
//	}
//}

void Board::draw() {

	setcolor(WHITE);
	//Biên trên
	line(x, y, x + width + 1, y);
	//Biên trái
	line(x, y, x, y + height + 1);
	//Biên phải
	line(x + width + 1, y, x + width + 1, y + height + 1);
	//Biên dưới
	line(x, y + height + 1, x + width + 1, y + height + 1);

}
