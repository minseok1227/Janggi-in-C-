#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "winbgi.h"
using namespace std;

// 파란색 말들
class blue_horse {
	int x = 0;
	int y = 0;
	int offset = 25, gap = 60;
	int king_r = gap / 5;
	const char* ch;
public:
	blue_horse() {};
	void makebhorse(WinBGI& win, int x, int y, const char* ch);
	void movebhorse(WinBGI& win, int x, int y, const char* ch);
	~blue_horse() {};
};