#pragma once
class Menu
{
private:
	char title[10];
	char menu[50][50];
	int n;

	void processSubMenu(int select);
public:
	Menu();
	Menu(char title[10], char menu[50][50], int n);
	void display();
	void allowControl();

};
