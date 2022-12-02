#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "winbgi.h"
using namespace std;

// »¡°£»ö ¸»µé
class red_horse {
	int x = 0;
	int y = 0;
	int offset = 25, gap = 60;
	int king_r = gap / 5;
	const char* ch;
public:
	red_horse() {};
	void makerhorse(WinBGI& win, int x, int y, const char* ch);
	void moverhorse(WinBGI& win, int x, int y, const char* ch);
	~red_horse() {};
};