﻿#pragma once
#pragma comment(lib, "graphics.lib")
#include<iostream>
#include "graphics.h"
#include"Ball.h"
#include"Bar.h"
#include"Board.h"

class Match
{
private:
	int width, height;	//Kích thước sân chơi
	int x,y;			//Vị trí sân chơi
	char up1, up2, down1, down2; //Các nút điều khiển
	int score1, score2;
	Board* playground;
	Board* status;
	Ball* gball;
	Bar* player1;
	Bar* player2;
	static Match* instance; //Singleton

	Match();
	Match(int cordiX, int cordiY, int w, int h);
public:
	static Match* getInstance(int cordiX, int cordiY, int w, int h);
	static void removeInstance();

	~Match();
	void setPlayerControl(char player1Up, char player2Up, char player1Down, char player2Down);
	void scoreup(Bar* player);	//Nếu banh va vào tường trái thì player2 ghi điểm và ngược lại. Sau đó reset về vị trí ban đầu
	void draw();	//Vẽ màn chơi
	bool control(int distance);	//Nhận điều kiển từ bàn phím và di chuyển 1 khoảng có độ dài: distance 
	void run();	//Chạy màn chơi
	void collision(); //Xu ly va cham
};

