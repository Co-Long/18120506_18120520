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
	score1 = score2 = 0;
	playground = new Board(x, y, w, h);
	status = new Board(x, y + h + 30, w, h / 5);
	gball = new Ball(x+w / 2, y+h / 2, h/50, 1, WHITE);
	player1 = new Bar(x + 15, h / 2 - 5, h/5);
	player2 = new Bar(x+w-15, h / 2 - 5, h/5);
}

Match::~Match() {
	delete playground, status, gball, player1, player2;
}

void Match::scoreup(Bar* player) {
	if (player==player1) {
		score1++;
	}
	else if (player == player2) {
		score2++;
	}
	//reset màn chơi
	gball->reset();
	player1->reset();
	player2->reset();
	cleardevice();
	draw();
	delay(1000);
}

void Match::draw() {
	playground->draw();
	status->draw();
	gball->draw();
	player1->draw();
	player2->draw();

	//In điểm của player1
	char buffer[3];
	_itoa(score1, buffer, 10);
	settextstyle(6, 0, 5);
	outtextxy(status->getX() + status->getWidth()/10, status->getY() + status->getHeight()/3, buffer);
	//In điểm của player2
	_itoa(score2, buffer, 10);
	settextstyle(6, 0, 5);
	outtextxy(status->getX() + status->getWidth()- status->getWidth()/10, status->getY() + status->getHeight() / 3, buffer);
}

void Match::control(int distance) {

	if (kbhit()) {
		player1->erase();
		player2->erase();
		char control = (char)getch();

		if (control == up1) {
			if (player1->getYPos() - distance > y+1)
				player1->moveUp(distance);
		}
		if (control == up2) {
			if (player2->getYPos() - distance > y+1)
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
		gball->move();
		collision();
		control(height /40);

		delay(10);
	}
}