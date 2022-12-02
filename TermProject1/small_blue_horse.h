#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "winbgi.h"
using namespace std;

// 파란색 알갱이
class small_blue_horse {
	int x = 0;
	int y = 0;
	int offset = 25, gap = 60;
	int king_r = gap / 10;
	const char* ch;
public:
	small_blue_horse() {};
	void makesbhorse(WinBGI& win, int x, int y, const char* ch);
	void movesbhorse(WinBGI& win, int x, int y, const char* ch);
	~small_blue_horse() {};
};
