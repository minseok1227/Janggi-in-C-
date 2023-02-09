#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "winbgi.h"
#include "small_blue_horse.h"
using namespace std;

void small_blue_horse::makesbhorse(WinBGI& win, int x, int y, const char* ch) {
	this->x = x;
	this->y = y;
	this->ch = ch;
	win.setfillstyle(SOLID_FILL, 4);       // ������ ���� ���� 
	win.outtextxy(offset + x, offset + y, ch);
	win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);  // ��Ʈ����
	win.circle(offset + x, offset + y, king_r);
	win.floodfill(offset + x, offset + y, 15);
}

void small_blue_horse::movesbhorse(WinBGI& win, int x, int y, const char* ch) {
	this->x = x;
	this->y = y;
	this->ch = ch;
	win.cleardevice();
	win.setfillstyle(SOLID_FILL, 1);       // ������ ���� ���� 
	win.outtextxy(offset + x, offset + y, ch);
	win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);  // ��Ʈ����
	win.circle(offset + x, offset + y, king_r);
	win.floodfill(offset + x, offset + y, 15);
}