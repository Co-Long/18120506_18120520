#pragma once
#include<iostream>
#include<Windows.h>

void remove_scrollbar(); // cboard.cprogramming.com

void hidecursor();

void fixConsole();

// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height);


// Hàm tô màu.
void textcolor(int x);

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void GotoXY(int x, int y);

