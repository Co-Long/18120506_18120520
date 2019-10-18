#pragma once
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
	int score1, score2;	//Điểm của người chơi
	char up1, up2, down1, down2; //Các nút điều khiển
	Board* status; 
	Board* playground;
	Ball* gball;
	Bar* player1;
	Bar* player2;
public:
	Match(int cordiX, int cordiY, int w, int h);
	~Match();
	void scoreup();	//Nếu banh va vào tường trái thì player2 ghi điểm và ngược lại. Sau đó reset về vị trí ban đầu
	void draw();	//Vẽ màn chơi
	void control();	//Nhận điều kiển từ bàn phím
	void run();	//Chạy màn chơi
	void collision(); //Xu ly va cham
};

