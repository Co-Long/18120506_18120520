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
	gball = new Ball(w / 2, h / 2, 10, 40, 5, 10, WHITE);
	player1 = new Bar(x + 15, h / 2 - 5, 80);
	player2 = new Bar(x+w-15, h / 2 - 5, 80);
}

Match::~Match() {
	delete playground, status, gball, player1, player2;
}

void Match::scoreup() {
	if (gball->x + gball->r == x + width) {
		score1++;
		gball->reset();
		player1->reset();
		player2->reset();
	}
	else if (gball->x - gball->r == x) {
		score2++;
		gball->reset();
		player1->reset();
		player2->reset();
	}
}

void Match::draw() {
	playground->draw();
	status->draw();
	player1->draw();
	player2->draw();

}

void Match::control() {
	gball->move(y,y+height,x,x+width);

	/*if (_kbhit()) {
		char control = _getch();
		if (control == up1) {
			if (player1->getYPos() > 0)
				player1->moveUp();
		}
		if (control == up2) {
			if (player2->getYPos() > 0)
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
	}*/
}

void Match::run() {
	while (true) {
		draw();
		control();
		scoreup();
	}
}