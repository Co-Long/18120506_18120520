#include "Ball.h"
#include"Bar.h"
#include"Board.h"
#include"Match.h"
#include "graphics.h"
#pragma comment(lib, "graphics.lib")

int main()
{
	initwindow(1000, 800, "Pingpong");

	Match m(100,100,800, 500);
	m.run();
	
	getch();
	closegraph();
	return 0;
}