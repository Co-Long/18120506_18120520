#include "Instruction.h"

//Hien Thi Instruction screen
void Instruction::display()
{
	cleardevice();
	char* title = "How To Play";
	settextstyle(10, 0, 10);
	setcolor(YELLOW);
	//Hien thi ten game
	outtextxy(getmaxx() / 2 - textwidth(title) / 2, 40, title);

	//in ra man hinh rule
	char* rule[] = { "RULE: Each player control a paddle to bounce the ball", 
		"toward the opponent. If your opponent can't bounce", "the ball, you win.", 
		"Press b - back to menu","Press c - choose"};
	settextstyle(8, 0, 3);
	setcolor(WHITE);
	for (int i = 0; i < 5; i++)
	{
		outtextxy(50, 200 + i*50, rule[i]);
	}

	//in ra man hinh huong dan phim dieu khien
	char* player[] = {"Player 1:", "w - up", "s - down",
		"Player 2:","i - up", "k - down" };
	for (int i = 0; i < 3; i++)
	{
		outtextxy(200, 250 + i * 50 + 200, player[i]);
		outtextxy(getmaxx() - 200 - textwidth(player[5]), 250 + i * 50 + 200, player[i + 3]);
	}

}

//Kiem tra neu nguoi dung bam phim "b", quay ve menu
void Instruction::catchBackEvent()
{
	while (true) {
		if (kbhit()) {
			char c = (char)getch();
			switch (c) {
			case 'b':
				cleardevice();
				return;
			}
		}
	}
}
