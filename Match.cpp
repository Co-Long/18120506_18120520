#include "Match.h"
using namespace std;

Match::Match(int cordiX, int cordiY, int w, int h) {
	up1 = 'w';
	up2 = 'i';
	down1 = 's';
	down2 = 'k';
	score1 = score2 = 0;
	width = w;
	height = h;
	x = cordiX;
	y = cordiY;
	playground = new Board(x, y, w, h);
	status = new Board(x, y + h + 20, w, 100);
	gball = new Ball(w / 2, h / 2, 10, 40, 1, 1, WHITE);
	player1 = new Bar(x + 15, h / 2 - 5, 80);
	player2 = new Bar(x+w-15, h / 2 - 5, 80);
}

Match::~Match() {
	delete playground, status, gball, player1, player2;
}

void Match::scoreup() {
	if (gball->x + gball->r >= x + width) {
		score1++;
		//reset màn chơi
		gball->reset();
		player1->reset();
		player2->reset();
		cleardevice();
		draw();
		delay(1000);
	}
	else if (gball->x - gball->r <= x) {
		score2++;
		gball->reset();
		player1->reset();
		player2->reset();
		cleardevice();
		draw();
		delay(1000);
	}
}

void Match::draw() {
	playground->draw();
	status->draw();
	gball->draw();
	player1->draw();
	player2->draw();
}

void Match::control() {
	

	if (kbhit()) {
		player1->erase();
		player2->erase();
		char control = (char)getch();
		if (control == up1) {
			if (player1->getYPos() - player1->getLength() > 0)
				player1->moveUp();
		}
		if (control == up2) {
			if (player2->getYPos() - player1->getLength() > 0)
				player2->moveUp();
		}
		if (control == down1) {
			if (player1->getYPos() < 100 + height)
				player1->moveDown();
		}
		if (control == down2) {
			if (player2->getYPos() < 100 + height)
				player2->moveDown();
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

	if (gball->y + gball->r >= bottom - 1 || gball->y - gball->r <= top + 1) {
		gball->dy = - gball->dy;
	}

	if (gball->y >= player1->getYPos() &&
		gball->y <= player1->getYPos() + player1->getLength() &&
		gball->x - gball->r <= player1->getXPos() + 1) {
		gball->dx = -gball->dx;
	}

	if (gball->y >= player2->getYPos() &&
		gball->y <= player2->getYPos() + player2->getLength() &&
		gball->x + gball->r >= player2->getXPos() - 1) {
		gball->dx = -gball->dx;
	}
}

void Match::run() {
	draw();

	while (true) {
		gball->move(y, y + height, x, x + width);
		collision();
		control();
		scoreup();

		delay(10);
	}
}