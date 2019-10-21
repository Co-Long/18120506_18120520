#include "Ball.h"
#include"Bar.h"
#include"Board.h"
#include"Match.h"
#include "graphics.h"
#include "Menu.h"
#pragma comment(lib, "graphics.lib")


int main()
{
	initwindow(1000, 800, "Pingpong");
	char list[50][50] = { "Play now", "How to play", "Quit" };

	Menu* menu = new Menu("Ping Pong", list, 3);
	menu->display();
	menu->allowControl();
	
	getch();
	closegraph();
	return 0;
}