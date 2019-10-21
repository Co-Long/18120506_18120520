#include "Menu.h"
#include "graphics.h"
#include <string>
#include <iostream>
#include "Match.h"
#pragma comment(lib, "graphics.lib")

Menu::Menu()
{
}

Menu::Menu(char title[10], char menu[50][50], int n) {
	for (int i = 0; i < 10; i++)
	{
		this->title[i] = title[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			this->menu[i][j] = menu[i][j];
		}
	}
	this->n = n;
}

//Hien thi menu
void Menu::display()
{
	settextstyle(3, 0, 10);
	setcolor(YELLOW);
	//Hien thi ten game
	outtextxy(getmaxx() / 2 - textwidth(title) / 2, 40, title);

	settextstyle(2, 0, 10);

	//hien thi nhung submenu
	for (int i = 0; i < n; i++)
	{
		if (i == 0) setcolor(LIGHTCYAN);
		outtextxy(getmaxx() / 2 - textwidth(menu[i]) / 2, getmaxy() / 2 + i * 80, menu[i]);
		setcolor(WHITE);
	}
}

//cho phep nguoi choi tuong tac len xuong chon menu
void Menu::allowControl()
{
	int select = 0;
	int prev = 0;

	while (true) {
		if (kbhit()) {
			char c = getch();

			switch (c) {
			case 's':
				prev = select;
				if (select == n - 1) select = 0;
				else select++;
				break;
			case 'w':
				prev = select;
				if (select == 0) select = n - 1;
				else select--;
				break;
			case 'l':
				processSubMenu(select);
				break;
			}

			setcolor(WHITE);
			outtextxy(getmaxx() / 2 - textwidth(menu[prev]) / 2, getmaxy() / 2 + (prev) * 80, menu[prev]);
			setcolor(LIGHTCYAN);
			outtextxy(getmaxx() / 2 - textwidth(menu[select]) / 2, getmaxy() / 2 + select * 80, menu[select]);
		}
	}
}

//Xu ly lua chon submenu
void Menu::processSubMenu(int select)
{
	cleardevice();
	if (select == 0) {
		Match m(100, 100, 800, 500);
		m.run();
		return;
	}

	if (select == 1) {
		return;
	}

	if (select == 2) {
		exit(0);
	}
}