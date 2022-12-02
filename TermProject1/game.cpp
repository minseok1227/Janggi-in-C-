#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "winbgi.h"
using namespace std;

class RectangleThing {
	int width = 0;
	int height = 0;
	int rectnum = 1;
	int x = 0;
	int y = 0;
	int color = 0;
public:
	static RectangleThing staticrects[40][50];
	RectangleThing() {
	};
	RectangleThing(int x, int y) {
		this->x = x;
		this->y = y;
	};
	void MakeRectangle(WinBGI& win, WinBGI& win2, WinBGI& win3, WinBGI& win4, int width, int height, int rectnum);
	void MakeSingleRectangle(WinBGI& win, int x, int y, int rectcolor);
	void MakeEmptyRectangle(WinBGI& win, int x, int y);
	void Makexycolor(WinBGI& win, int x, int y, int color);
	~RectangleThing() {
	};
	void operator= (RectangleThing& rectangle) {
		this->x = rectangle.x;
		this->y = rectangle.y;
		this->color = rectangle.color;
	}
	int whatcolor(WinBGI& win) {
		int pixelcolor = 0;
		pixelcolor = win.getpixel(x, y);
		return pixelcolor;
	};
	void show() {
		cout << x << " // " << y << " // " << color << endl;
	}
};

void RectangleThing::Makexycolor(WinBGI& win, int x, int y, int color) {
	this->x = x;
	this->y = y;
	this->color = color;
}

void RectangleThing::MakeSingleRectangle(WinBGI& win, int x , int y, int rectcolor) {
	int w = 20, h = 20; // rectangle size 
	win.setfillstyle(SOLID_FILL, rectcolor);
	win.rectangle(x - w / 2, y - h / 2, x + w / 2, y + h / 2);// 도형 (직사각형)그리기
	win.floodfill(x, y, 15);// 직사각형내부채우기
}

void RectangleThing::MakeEmptyRectangle(WinBGI& win, int x, int y) {
	int w = 20, h = 20; // rectangle size 
	win.setfillstyle(SOLID_FILL, 0);
	win.rectangle(x - w / 2, y - h / 2, x + w / 2, y + h / 2);// 도형 (직사각형)그리기
	win.floodfill(x, y, 0);// 직사각형내부채우기
}

void RectangleThing::MakeRectangle(WinBGI& win, WinBGI& win2, WinBGI& win3, WinBGI& win4, int width, int height, int rectnum) {
	int x = width, y = height; // center 
	int w = 20, h = 20; // rectangle size 
	if (rectnum == 1) {
		win.setfillstyle(SOLID_FILL, 1);   // 도형의 내부 선택 	
		win2.setfillstyle(SOLID_FILL, 1);   // 도형의 내부 선택 
		win3.setfillstyle(SOLID_FILL, 1);   // 도형의 내부 선택 	
		win4.setfillstyle(SOLID_FILL, 1);   // 도형의 내부 선택 
		win.rectangle(x - w / 2, y - h / 2, x + w / 2, y + h / 2);// 도형 (직사각형)그리기
		win2.rectangle(x + w / 2, y - h / 2, x + 3 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win3.rectangle(x - w / 2, y + h / 2, x + w / 2, y + 3 * h / 2);// 도형 (직사각형)그리기
		win4.rectangle(x + w / 2, y + h / 2, x + 3 * w / 2, y + 3 * h / 2);// 도형 (직사각형)그리기
		win.floodfill(x, y, 15);// 직사각형내부채우기
		win2.floodfill(x + w, y, 15);// 직사각형내부채우기
		win3.floodfill(x, y + h, 15);// 직사각형내부채우기
		win4.floodfill(x + w, y + h, 15);// 직사각형내부채우기

	}
	else if (rectnum == 2) {
		win.setfillstyle(SOLID_FILL, 6);   // 도형의 내부 선택 	
		win2.setfillstyle(SOLID_FILL, 6);   // 도형의 내부 선택 
		win3.setfillstyle(SOLID_FILL, 6);   // 도형의 내부 선택 	
		win4.setfillstyle(SOLID_FILL, 6);   // 도형의 내부 선택 
		win.rectangle(x - w / 2, y - h / 2, x + w / 2, y + h / 2);// 도형 (직사각형)그리기
		win2.rectangle(x + w / 2, y - h / 2, x + 3 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win3.rectangle(x + 3 * w / 2, y - h / 2, x + 5 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win4.rectangle(x + w / 2, y - 3 * h / 2, x + 3 * w / 2, y - h / 2);// 도형 (직사각형)그리기
		win.floodfill(x, y, 15);// 직사각형내부채우기
		win2.floodfill(x + w, y, 15);// 직사각형내부채우기
		win3.floodfill(x + 2 * w, y, 15);// 직사각형내부채우기
		win4.floodfill(x + w, y - h, 15);// 직사각형내부채우기

	}
	else if (rectnum == 3) {
		win.setfillstyle(SOLID_FILL, 7);   // 도형의 내부 선택 	
		win2.setfillstyle(SOLID_FILL, 7);   // 도형의 내부 선택 
		win3.setfillstyle(SOLID_FILL, 7);   // 도형의 내부 선택 	
		win4.setfillstyle(SOLID_FILL, 7);   // 도형의 내부 선택 
		win.rectangle(x - w / 2, y - h / 2, x + w / 2, y + h / 2);// 도형 (직사각형)그리기
		win2.rectangle(x + w / 2, y - h / 2, x + 3 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win3.rectangle(x + 3 * w / 2, y - h / 2, x + 5 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win4.rectangle(x + 3 * w / 2, y - 3 * h / 2, x + 5 * w / 2, y - h / 2);// 도형 (직사각형)그리기
		win.floodfill(x, y, 15);// 직사각형내부채우기
		win2.floodfill(x + w, y, 15);// 직사각형내부채우기
		win3.floodfill(x + 2 * w, y, 15);// 직사각형내부채우기
		win4.floodfill(x + 2 * w, y - h, 15);// 직사각형내부채우기

	}
	else if (rectnum == 4) {
		win.setfillstyle(SOLID_FILL, 10);   // 도형의 내부 선택 	
		win2.setfillstyle(SOLID_FILL, 10);   // 도형의 내부 선택 
		win3.setfillstyle(SOLID_FILL, 10);   // 도형의 내부 선택 	
		win4.setfillstyle(SOLID_FILL, 10);   // 도형의 내부 선택 
		win.rectangle(x - w / 2, y - h / 2, x + w / 2, y + h / 2);// 도형 (직사각형)그리기
		win2.rectangle(x + w / 2, y - h / 2, x + 3 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win3.rectangle(x + 3 * w / 2, y - h / 2, x + 5 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win4.rectangle(x + 5 * w / 2, y - h / 2, x + 7 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win.floodfill(x, y, 15);// 직사각형내부채우기
		win2.floodfill(x + w, y, 15);// 직사각형내부채우기
		win3.floodfill(x + 2 * w, y, 15);// 직사각형내부채우기
		win4.floodfill(x + 3 * w, y, 15);// 직사각형내부채우기

	}
}

int *Block1(WinBGI& win, WinBGI& win2, WinBGI& win3, WinBGI& win4, int xaxis[], int yaxis[], int xaxis2[], int yaxis2[], int xaxis3[], int yaxis3[], int xaxis4[], int yaxis4[], int xsize, int colorset[]) {
	/*OO
	  OO*/
	static const int  UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80;
	RectangleThing rects[1000];

	int x = 300, y = 300; // center 
	int w = 20, h = 20; // rectangle size 
	int step = 20;
	int* finalxy = new int[10];
	int max_x = win.getmaxx(), max_y = win.getmaxy();

	while (true)
	{
		win.setfillstyle(SOLID_FILL, 1);   // 도형의 내부 선택 	
		win2.setfillstyle(SOLID_FILL, 1);   // 도형의 내부 선택 
		win3.setfillstyle(SOLID_FILL, 1);   // 도형의 내부 선택 	
		win4.setfillstyle(SOLID_FILL, 1);   // 도형의 내부 선택 
		win.rectangle(x - w / 2, y - h / 2, x + w / 2, y + h / 2);// 도형 (직사각형)그리기
		win2.rectangle(x + w / 2, y - h / 2, x + 3 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win3.rectangle(x - w / 2, y + h / 2, x + w / 2, y + 3 * h / 2);// 도형 (직사각형)그리기
		win4.rectangle(x + w / 2, y + h / 2, x + 3 * w / 2, y + 3 * h / 2);// 도형 (직사각형)그리기
		win.floodfill(x, y, 15);// 직사각형내부채우기
		win2.floodfill(x + w, y, 15);// 직사각형내부채우기
		win3.floodfill(x, y + h, 15);// 직사각형내부채우기
		win4.floodfill(x + w, y + h, 15);// 직사각형내부채우기
		win.delay(300);
		win.cleardevice();// 100ms를 멈춤  
		for (int i = 0; i < xsize; i++) {
			rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
		}
		y += step;
		COORD pos = { x - w /2 -1, y };
		if ((win.getpixel(x, y + w / 2 + 1) != 0) || (win.getpixel(x + w, y + w / 2 + 1) != 0)) {
			break;
		}
		if (y > max_y - (h / 2)) {
			y = max_y - (h / 2);
			break;
		}
		if (win.kbhit()) { //  
			int key = win.getch();
			if (key == 'q')  // 종료 키 
				break;
			else if (key == 224 || key == 0) {  // 방향키는 2 byte  
				key = win.getch();
				if (key == UP) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					y -= step;
					if (y < h / 2)
						y = h / 2;
				}
				else if (key == LEFT) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					x -= step;
					if (win.getpixel(x - w / 2 - 1, y) != 0) {
						x = x + step;
					}
					if (x < w / 2)
						x = w / 2;
				}
				else if (key == RIGHT) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice(); for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					x += step;
					if (win.getpixel(x + 3 * w / 2 + 1, y) != 0) {
						x = x - step;
					}
					if (x > max_x - 3 * (w / 2))
						x = max_x - 3 * (w / 2);
				}

			} //else
		} // kbhit		       // 화면을 지움
		
	} // while 

	finalxy[0] = x;
	finalxy[1] = y;
	finalxy[2] = 1;
	finalxy[3] = x + w;
	finalxy[4] = y;
	finalxy[5] = x;
	finalxy[6] = y - h;
	finalxy[7] = x + w;
	finalxy[8] = y - h;
	finalxy[9] = 1;
	return finalxy;
}

int *Block2(WinBGI& win, WinBGI& win2, WinBGI& win3, WinBGI& win4, int xaxis[], int yaxis[], int xaxis2[], int yaxis2[], int xaxis3[], int yaxis3[], int xaxis4[], int yaxis4[], int xsize, int colorset[]) {
	/* O
	  OOO*/
	static const int  UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80;
	RectangleThing rects[1000];

	int x = 300, y = 300; // center 
	int w = 20, h = 20; // rectangle size 
	int step = 20;
	int* finalxy = new int[10];
	int max_x = win.getmaxx(), max_y = win.getmaxy();

	while (true)
	{
		win.setfillstyle(SOLID_FILL, 6);   // 도형의 내부 선택 	
		win2.setfillstyle(SOLID_FILL, 6);   // 도형의 내부 선택 
		win3.setfillstyle(SOLID_FILL, 6);   // 도형의 내부 선택 	
		win4.setfillstyle(SOLID_FILL, 6);   // 도형의 내부 선택 
		win.rectangle(x - w / 2, y - h / 2, x + w / 2, y + h / 2);// 도형 (직사각형)그리기
		win2.rectangle(x + w / 2, y - h / 2, x + 3 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win3.rectangle(x + 3 * w / 2, y - h / 2, x + 5 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win4.rectangle(x + w / 2, y - 3 * h / 2, x + 3 * w / 2, y - h / 2);// 도형 (직사각형)그리기
		win.floodfill(x, y, 15);// 직사각형내부채우기
		win2.floodfill(x + w, y, 15);// 직사각형내부채우기
		win3.floodfill(x + 2 * w, y, 15);// 직사각형내부채우기
		win4.floodfill(x + w, y - h, 15);// 직사각형내부채우기
		win.delay(300);
		win.cleardevice();// 100ms를 멈춤 
		for (int i = 0; i < xsize; i++) {
			rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
		}
		y += step;
		COORD pos = { x - w, y };
		if ((win.getpixel(x, y + w / 2 + 1) != 0) || (win.getpixel(x + w, y + w / 2 + 1) != 0) || (win.getpixel(x + 2 * w, y + w / 2 + 1) != 0)) {
			break;
		}
		if (y > max_y - (h / 2)) {
			y = max_y - (h / 2);
			break;
		}

		if (win.kbhit()) { //  
			int key = win.getch();
			if (key == 'q')  // 종료 키 
				break;
			else if (key == 224 || key == 0) {  // 방향키는 2 byte  
				key = win.getch();
				if (key == UP) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					y -= step;
					if (y < h / 2)
						y = h / 2;
				}
				else if (key == LEFT) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					x -= step;
					if (win.getpixel(x - w / 2 - 1, y) != 0) {
						x = x + step;
					}
					if (x < w / 2)
						x = w / 2;
				}
				else if (key == RIGHT) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					x += step;
					if (win.getpixel(x + 3 * w / 2 + 1, y) != 0) {
						x = x - step;
					}
					if (x > max_x - (5 * w / 2))
						x = max_x - (5 * w / 2);
				}
				
			} //else
		} // kbhit		       // 화면을 지움
	} // while
	finalxy[0] = x;
	finalxy[1] = y;
	finalxy[2] = 2;
	finalxy[3] = x + w;
	finalxy[4] = y;
	finalxy[5] = x + 2 * w;
	finalxy[6] = y;
	finalxy[7] = x + w;
	finalxy[8] = y - h;
	finalxy[9] = 6;
	return finalxy;
}

int *Block3(WinBGI& win, WinBGI& win2, WinBGI& win3, WinBGI& win4, int xaxis[], int yaxis[], int xaxis2[], int yaxis2[], int xaxis3[], int yaxis3[], int xaxis4[], int yaxis4[], int xsize, int colorset[]) {
	/*  O
	  OOO*/
	static const int  UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80;
	RectangleThing rects[1000];

	int x = 300, y = 300; // center 
	int w = 20, h = 20; // rectangle size 
	int step = 20;
	int* finalxy = new int[10];
	int max_x = win.getmaxx(), max_y = win.getmaxy();

	while (true)
	{
		win.setfillstyle(SOLID_FILL, 7);   // 도형의 내부 선택 	
		win2.setfillstyle(SOLID_FILL, 7);   // 도형의 내부 선택 
		win3.setfillstyle(SOLID_FILL, 7);   // 도형의 내부 선택 	
		win4.setfillstyle(SOLID_FILL, 7);   // 도형의 내부 선택 
		win.rectangle(x - w / 2, y - h / 2, x + w / 2, y + h / 2);// 도형 (직사각형)그리기
		win2.rectangle(x + w / 2, y - h / 2, x + 3 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win3.rectangle(x + 3 * w / 2, y - h / 2, x + 5 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win4.rectangle(x + 3 * w / 2, y - 3 * h / 2, x + 5 * w / 2, y - h / 2);// 도형 (직사각형)그리기
		win.floodfill(x, y, 15);// 직사각형내부채우기
		win2.floodfill(x + w, y, 15);// 직사각형내부채우기
		win3.floodfill(x + 2 * w, y, 15);// 직사각형내부채우기
		win4.floodfill(x + 2 * w, y - h, 15);// 직사각형내부채우기
		win.delay(300);
		win.cleardevice();// 100ms를 멈춤  

		for (int i = 0; i < xsize; i++) {
			rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
		}
		y += step;
		COORD pos = { x - w, y };
		if ((win.getpixel(x, y + w / 2 + 1) != 0) || (win.getpixel(x + w, y + w / 2 + 1) != 0) || (win.getpixel(x + 2 * w, y + w / 2 + 1) != 0)) {
			break;
		}
		if (y > max_y - (h / 2)) {
			y = max_y - (h / 2);
			break;
		}
		if (win.kbhit()) { //  
			int key = win.getch();
			if (key == 'q')  // 종료 키 
				break;
			else if (key == 224 || key == 0) {  // 방향키는 2 byte  
				key = win.getch();
				if (key == UP) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					y -= step;
					if (y < h / 2)
						y = h / 2;
				}
				else if (key == LEFT) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					x -= step;
					if (win.getpixel(x - w / 2 - 1, y) != 0) {
						x = x + step;
					}
					if (x < w / 2)
						x = w / 2;
				}
				else if (key == RIGHT) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					x += step;
					if (win.getpixel(x + 3 * w / 2 + 1, y) != 0) {
						x = x - step;
					}
					if (x > max_x - (5 * w / 2))
						x = max_x - (5 * w / 2);
				}
				
			} //else
		} // kbhit		       // 화면을 지움
	} // while 
	finalxy[0] = x;
	finalxy[1] = y;
	finalxy[2] = 3;
	finalxy[3] = x + w;
	finalxy[4] = y;
	finalxy[5] = x + 2 * w;
	finalxy[6] = y;
	finalxy[7] = x + 2 * w;
	finalxy[8] = y - h;
	finalxy[9] = 7;
	return finalxy;
}

int *Block4(WinBGI& win, WinBGI& win2, WinBGI& win3, WinBGI& win4, int xaxis[], int yaxis[], int xaxis2[], int yaxis2[], int xaxis3[], int yaxis3[], int xaxis4[], int yaxis4[], int xsize, int colorset[]) {
	/*OOOO*/
	static const int  UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80;
	RectangleThing rects[1000];
	int x = 300, y = 300; // center 
	int w = 20, h = 20; // rectangle size 
	int step = 20;
	int* finalxy = new int[10];
	int max_x = win.getmaxx(), max_y = win.getmaxy();

	while (true)
	{
		win.setfillstyle(SOLID_FILL, 10);   // 도형의 내부 선택 	
		win2.setfillstyle(SOLID_FILL, 10);   // 도형의 내부 선택 
		win3.setfillstyle(SOLID_FILL, 10);   // 도형의 내부 선택 	
		win4.setfillstyle(SOLID_FILL, 10);   // 도형의 내부 선택 
		win.rectangle(x - w / 2, y - h / 2, x + w / 2, y + h / 2);// 도형 (직사각형)그리기
		win2.rectangle(x + w / 2, y - h / 2, x + 3 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win3.rectangle(x + 3 * w / 2, y - h / 2, x + 5 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win4.rectangle(x + 5 * w / 2, y - h / 2, x + 7 * w / 2, y + h / 2);// 도형 (직사각형)그리기
		win.floodfill(x, y, 15);// 직사각형내부채우기
		win2.floodfill(x + w, y, 15);// 직사각형내부채우기
		win3.floodfill(x + 2 * w, y, 15);// 직사각형내부채우기
		win4.floodfill(x + 3 * w, y, 15);// 직사각형내부채우기
		win.delay(300);
		win.cleardevice();// 100ms를 멈춤  
		for (int i = 0; i < xsize; i++) {
			rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]); // xaxis와 yaxis를 비교하여 해당하면 채우기
			rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
			rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
		}
		
		y += step;
		COORD pos = { x - w, y };
		if ((win.getpixel(x, y + w / 2 + 1) != 0) || (win.getpixel(x + w, y + w / 2 + 1) != 0) || (win.getpixel(x + 2 * w, y + w / 2 + 1) != 0) || (win.getpixel(x + 3 * w, y + w / 2 + 1) != 0)) {
			break;
		}
		if (y > max_y - (h / 2)) {
			y = max_y - (h / 2);
			break;
		}
		if (win.kbhit()) { //  
			int key = win.getch();
			if (key == 'q')  // 종료 키 
				break;
			else if (key == 224 || key == 0) {  // 방향키는 2 byte  
				key = win.getch();
				if (key == UP) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					y -= step;
					if (y < h / 2)
						y = h / 2;
				}
				else if (key == LEFT) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i  <xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					x -= step;
					if (win.getpixel(x - w / 2 - 1, y) != 0) {
						x = x + step;
					}
					if (x < w / 2)
						x = w / 2;
				}
				else if (key == RIGHT) {
					win.delay(30);                    // 100ms를 멈춤   
					win.cleardevice();
					for (int i = 0; i < xsize; i++) {
						rects[i].MakeSingleRectangle(win, xaxis[i], yaxis[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis2[i], yaxis2[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis3[i], yaxis3[i], colorset[i]);
						rects[i].MakeSingleRectangle(win, xaxis4[i], yaxis4[i], colorset[i]);
					}
					x += step;
					if (win.getpixel(x + w / 2 + 1, y) != 0) {
						x = x - step;
					}
					if (x > max_x - (7 * w / 2))
						x = max_x - (7 * w / 2);
				}
			} //else
		} // kbhit		       // 화면을 지움
	} // while 
	finalxy[0] = x;
	finalxy[1] = y;
	finalxy[2] = 4;
	finalxy[3] = x + w;
	finalxy[4] = y;
	finalxy[5] = x + 2 * w;
	finalxy[6] = y;
	finalxy[7] = x + 3 * w;
	finalxy[8] = y;
	finalxy[9] = 10;
	return finalxy;
}

int main()
{
	
	int j = 0;
	int lines = 0;
	int linedisappear = 0;
	int singlerectnum = 0;
	int maxnum = 1;
	int w = 20, h = 20; // rectangle size 
	int storenum[10][1000];
	int arrangenum[40][50];
	int removex[40];
	int removey[40];
	int removecolor[40];
	int blocktoremove = 0;
	int colorblack = 0;
	RectangleThing rects[1000];
	RectangleThing arrangerects[40][50];
	WinBGI& win = WinBGI::instance();
	WinBGI& win2 = WinBGI::instance();
	WinBGI& win3 = WinBGI::instance();
	WinBGI& win4 = WinBGI::instance();
	int* axis = 0;
	while (true) {
		int blocknum = 0;
		int whatblock = rand() % 4 + 1;
		for (int pixelcolory = 780; pixelcolory >= 0; pixelcolory -= 20) {
			for (int pixelcolorx = 0; pixelcolorx < 720; pixelcolorx += 20) {
				if (win.getpixel(pixelcolorx, pixelcolory) != 0) {
					blocktoremove++;
					if (blocktoremove == 35) {
						for (int a = 0; a < 36; a++) {
							removecolor[a] = win.getpixel(20 * a, pixelcolory);
							removex[a] = 20 * a;
							removey[a] = pixelcolory;
							cout << "color : " << removecolor[a] << " x축 : " << removex[a] << " y축 : " << removey[a] << endl;
						}
					}
				}
			}
			blocktoremove = 0;
		}
		cout << blocktoremove << endl;
		blocktoremove = 0;
		for (int j = 0; j < 36; j++) {
			for (int k = 0; k < maxnum; k++) {
				if (removecolor[j] == storenum[9][k]) {
					if (removex[j] == storenum[0][k]) {
						if (removey[j] == storenum[1][k]) {
							colorblack = k;
							storenum[9][colorblack] = 0;
						}
					}
					else if (removex[j] == storenum[3][k]) {
						if (removey[j] == storenum[4][k]) {
							colorblack = k;
							storenum[9][colorblack] = 0;
						}
					}
					else if (removex[j] == storenum[5][k]) {
						if (removey[j] == storenum[6][k]) {
							colorblack = k;
							storenum[9][colorblack] = 0;
						}
					}
					else if (removex[j] == storenum[7][k]) {
						if (removey[j] == storenum[8][k]) {
							colorblack = k;
							storenum[9][colorblack] = 0;
						}
					}
				}
			}
		}
		if (whatblock == 1) {
			axis = Block1(win, win2, win3, win4, storenum[0], storenum[1], storenum[3], storenum[4], storenum[5], storenum[6], storenum[7], storenum[8], maxnum, storenum[9]);
		}
		else if (whatblock == 2) {
			axis = Block2(win, win2, win3, win4, storenum[0], storenum[1], storenum[3], storenum[4], storenum[5], storenum[6], storenum[7], storenum[8], maxnum, storenum[9]);
		}
		else if (whatblock == 3) {
			axis = Block3(win, win2, win3, win4, storenum[0], storenum[1], storenum[3], storenum[4], storenum[5], storenum[6], storenum[7], storenum[8], maxnum, storenum[9]);
		}
		else if (whatblock == 4) {
			axis = Block4(win, win2, win3, win4, storenum[0], storenum[1], storenum[3], storenum[4], storenum[5], storenum[6], storenum[7], storenum[8], maxnum, storenum[9]);
		}
		for (int k = 0; k < 10; k++) {
			storenum[k][maxnum - 1] = axis[k];
		}
		
		lines = 0;
		++maxnum;
	}
}