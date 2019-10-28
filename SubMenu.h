#include "Menu.h"
#pragma once

class SubMenu : public Menu
{
protected:
	//Override
	void processSubMenu(int select);
public:
	SubMenu();
	SubMenu(char title[10], char menu[50][50], int n);
};

