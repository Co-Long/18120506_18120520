#include "SubMenu.h"
#include "Menu.h"
#include "graphics.h"
#include <string>
#include <iostream>
#include "Match.h"
#include "Instruction.h"

SubMenu::SubMenu()
{
}

SubMenu::SubMenu(char title[10], char menu[50][50], int n): Menu::Menu(title, menu, n) {
	
}

void SubMenu::processSubMenu(int select)
{
	cleardevice();
	if (select == 0) {
		Match::removeInstance();
		Match* match = Match::getInstance(100, 100, 800, 500);
		match->run();
		return;
	}

	if (select == 1) {
		Match* match = Match::getInstance(100, 100, 800, 500);
		match->run();
		return;
	}

	if (select == 2) {
		Instruction::display();
		Instruction::catchBackEvent();
		this->display();
		return;
	}

	if (select == 3) {
		exit(0);
	}
}
