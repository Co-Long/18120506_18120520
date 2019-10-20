#include "Match.h"
using namespace std;

Match::Match(int cordiX, int cordiY, int w, int h) {
	up1 = 'w';
	up2 = 'i';
	down1 = 's';
	down2 = 'k';
	width = w;
	height = h;
	x = cordiX;
	y = cordiY;
	playground = new Board(x, y, w, h);
	gball = new Ball(w / 2, h / 2, 10, 40, 1, 1, WHITE);
	player1 = new Bar(x + 15, h / 2 - 5, h/10);
	player2 = new Bar(x+w-15, h / 2 - 5, h/10);
}

Match::~Match() {
	delete playground, gball, player1, player2;
}

void Match::scoreup(Bar* player) {
	if (player==player1) {
		char s[] = "Player_1 win";
		settextstyle(1, 0, 3);
		outtextxy(x+width+40, y+height/2, s);
		delay(3000);
	}
	else if (player == player2) {
		char s[] = "Player_2 win";
		settextstyle(1, 0, 3);
		outtextxy(x + width/2 + 40, y + height/2, s);
		delay(3000);
	}
	//reset màn chơi
	gball->reset();
	player1->reset();
	player2->reset();
	cleardevice();
	draw();
	delay(100);
}

void Match::draw() {
	playground->draw();
	gball->draw();
	player1->draw();
	player2->draw();
}

void Match::control(int distance) {

	if (kbhit()) {
		player1->erase();
		player2->erase();
		char control = (char)getch();

		if (control == up1) {
			if (player1->getYPos() - distance > y)
				player1->moveUp(distance);
		}
		if (control == up2) {
			if (player2->getYPos() - distance > y)
				player2->moveUp(distance);
		}
		if (control == down1) {
			if (player1->getYPos() < y + height- distance -player1->getLength())
				player1->moveDown(distance);
		}
		if (control == down2) {
			if (player2->getYPos() < y + height- distance -player1->getLength())
				player2->moveDown(distance);
		}
		player1->draw();
		player2->draw();
	}
}

void Match::collision() {
	int top = y;
	int bottom = y + height;
	int left = x;
	int right = x + width;

	//Banh chạm vào biên trên hay biên dưới
	if (gball->y + gball->r >= bottom - 1 || gball->y - gball->r <= top + 1) {
		gball->dy = - gball->dy;
	}

	//Banh chạm vào người chơi
	if (gball->y >= player1->getYPos() &&
		gball->y <= player1->getYPos() + player1->getLength() &&
		gball->x - gball->r <= player1->getXPos() + 1) {
		gball->dx = -gball->dx;
	}

	//Banh chạm vào người chơi
	if (gball->y >= player2->getYPos() &&
		gball->y <= player2->getYPos() + player2->getLength() &&
		gball->x + gball->r >= player2->getXPos() - 1) {
		gball->dx = -gball->dx;
	}

	//Nếu đụng biên phải thì player1 ghi điểm
	if (gball->x + gball->r >= x + width) {
		scoreup(player1);
	}
	//Nếu đụng biên trái thì player2 ghi điểm
	else if (gball->x - gball->r <= x) {
		scoreup(player2);
	}

}

void Match::run() {
	draw();

	while (true) {
		gball->move(y, y + height, x, x + width);
		collision();
		control(height /40);

		delay(10);
	}
}