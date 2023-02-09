#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "winbgi.h"
#include "small_red_horse.h"
using namespace std;

void small_red_horse::makesrhorse(WinBGI& win, int x, int y, const char* ch) {
	this->x = x;
	this->y = y;
	this->ch = ch;
	win.setfillstyle(SOLID_FILL, 4);       // ������ ���� ���� 
	win.outtextxy(offset + x, offset + y, ch);
	win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);  // ��Ʈ����
	win.circle(offset + x, offset + y, king_r);
	win.floodfill(offset + x, offset + y, 15);
}

void small_red_horse::movesrhorse(WinBGI& win, int x, int y, const char* ch) {
	this->x = x;
	this->y = y;
	this->ch = ch;
	win.cleardevice();
	win.setfillstyle(SOLID_FILL, 4);       // ������ ���� ���� 
	win.outtextxy(offset + x, offset + y, ch);
	win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);  // ��Ʈ����
	win.circle(offset + x, offset + y, king_r);
	win.floodfill(offset + x, offset + y, 15);
}