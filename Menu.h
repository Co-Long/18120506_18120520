#pragma once
class Menu
{
protected:
	char title[10];
	char menu[50][50];
	int n;
	int select = 0;

	virtual void processSubMenu(int select);
public:
	Menu();
	Menu(char title[10], char menu[50][50], int n);
	void display();
	void allowControl();
};
