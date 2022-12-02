#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "winbgi.h"
using namespace std;

// 빨간색 알갱이
class small_red_horse {
	int x = 0;
	int y = 0;
	int offset = 25, gap = 60;
	int king_r = gap / 10;
	const char* ch;
public:
	small_red_horse() {};
	void makesrhorse(WinBGI& win, int x, int y, const char* ch);
	void movesrhorse(WinBGI& win, int x, int y, const char* ch);
	~small_red_horse() {};
};
