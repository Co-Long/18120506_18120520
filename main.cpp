#include "Ball.h"
#include"Bar.h"
#include"Board.h"
#include"Match.h"
#include "graphics.h"
#pragma comment(lib, "graphics.lib")

int main()
{
	initwindow(1600, 900, "Pingpong");

	Match m(300,100,1000, 700);
	m.run();
	
	getch();
	closegraph();
	return 0;
}