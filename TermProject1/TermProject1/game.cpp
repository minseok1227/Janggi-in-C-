#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "winbgi.h"
#include "red_horse.h"
#include "blue_horse.h"
#include "small_red_horse.h"
#include "small_blue_horse.h"
using namespace std;

void diagonal() {
	WinBGI& win = WinBGI::instance();
	int offset = 25;
	int gap = 60;
	win.line(3 * gap + offset, offset, 4 * gap + offset, offset + 1 * gap);
	win.line(5 * gap + offset, offset, 4 * gap + offset, offset + 1 * gap);
	win.line(3 * gap + offset, 2 * gap + offset, 4 * gap + offset, offset + 1 * gap);
	win.line(5 * gap + offset, 2 * gap + offset, 4 * gap + offset, offset + 1 * gap);
	win.line(3 * gap + offset, 9 * gap + offset, 4 * gap + offset, offset + 8 * gap);
	win.line(5 * gap + offset, 9 * gap + offset, 4 * gap + offset, offset + 8 * gap);
	win.line(3 * gap + offset, 7 * gap + offset, 4 * gap + offset, offset + 8 * gap);
	win.line(5 * gap + offset, 7 * gap + offset, 4 * gap + offset, offset + 8 * gap);
}

int main() {
	WinBGI& win = WinBGI::instance();
	WinBGI& win2 = WinBGI::instance();

LETSGO:
	red_horse redone[16];
	blue_horse blueone[16];
	small_red_horse smallredone[16];
	small_blue_horse smallblueone[16];
	int offset = 25;
	int gap = 60;
	int dot = 0;
	int formerdot = 0;
	int dot_r = 4;
	int red_move = 0, blue_move = 0;
	int newx = 0, newy = 0;
	int newmovex = 0, newmovey = 0;
	static const int  ENTER = 13, UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80;
	static const int  SPACE = 32, ESC = 27;
	int r = 22, b = 22;

	int king_r = gap / 5;
	int symbol_offset = gap / 3;
	int attacknum = 0;
	int redmove = 0, bluemove = 0;
	int movechange = 0;
	int canonmove = 0;
	int elephantnotmove = 0;
	int horsenotmove = 0;
	int left = 0, right = 0, up = 0, down = 0;

	int blue_x[16] = { 4, 3, 5, 2, 6, 1, 7, 0, 8, 1, 7, 0, 2, 4, 6, 8 };
	int blue_y[16] = { 8, 9, 9, 9, 9, 9, 9, 9, 9, 7, 7, 6, 6, 6, 6, 6 };
	int red_x[16] = { 4, 3, 5, 2, 6, 1, 7, 0, 8, 1, 7, 0, 2, 4, 6, 8 };
	int red_y[16] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 3, 3, 3, 3 };
	int move_x[16][8] = { {-gap, -gap, 0, gap, gap, gap, 0, -gap}, {-gap, -gap, 0, gap, gap, gap, 0, -gap}, {-gap, -gap, 0, gap, gap, gap, 0, -gap}, {0, -2 * gap, 0, 2 * gap, 0, 2 * gap, 0, -2 * gap}, {0, -2 * gap, 0, 2 * gap, 0, 2 * gap, 0, -2 * gap},
		{-2 * gap, -gap, gap, 2 * gap, 2 * gap, gap, -gap, -2 * gap}, {-2 * gap, -gap, gap, 2 * gap, 2 * gap, gap, -gap, -2 * gap}, {gap, 2 * gap, 3 * gap, 4 * gap, 5 * gap, 6 * gap, 7 * gap, 8 * gap}, {gap, 2 * gap, 3 * gap, 4 * gap, 5 * gap, 6 * gap, 7 * gap, 8 * gap},
		{ 2 * gap, 3 * gap, 4 * gap, 5 * gap, 6 * gap, 7 * gap, 8 * gap, 9 * gap}, {2 * gap, 3 * gap, 4 * gap, 5 * gap, 6 * gap, 7 * gap, 8 * gap, 9 * gap}, {-gap, 0, 0, 0, gap, 0, 0, 0}, {-gap, 0, 0, 0, gap, 0, 0, 0}, {-gap, 0, 0, 0, gap, 0, 0, 0}, {-gap, 0, 0, 0, gap, 0, 0, 0}, {-gap, 0, 0, 0, gap, 0, 0, 0} };

	int move_y[16][8] = { {0, gap, gap, gap, 0, -gap, -gap, -gap}, {0, gap, gap, gap, 0, -gap, -gap, -gap}, {0, gap, gap, gap, 0, -gap, -gap, -gap}, {0, 2 * gap, 0, 2 * gap, 0, -2 * gap, 0, -2 * gap}, {0, 2 * gap, 0, 2 * gap, 0, -2 * gap, 0, -2 * gap},
		{gap, 2 * gap, 2 * gap, gap, -gap, -2 * gap, -2 * gap, -gap}, {gap, 2 * gap, 2 * gap, gap, -gap, -2 * gap, -2 * gap, -gap}, {gap, 2 * gap, 3 * gap, 4 * gap, 5 * gap, 6 * gap, 7 * gap, 8 * gap}, {gap, 2 * gap, 3 * gap, 4 * gap, 5 * gap, 6 * gap, 7 * gap, 8 * gap},
		{gap, 2 * gap, 3 * gap, 4 * gap, 5 * gap, 6 * gap, 7 * gap, 8 * gap}, {gap, 2 * gap, 3 * gap, 4 * gap, 5 * gap, 6 * gap, 7 * gap, 8 * gap}, {0, 0, gap, 0, 0, 0, 0, 0}, {0, 0, gap, 0, 0, 0, 0, 0}, {0, 0, gap, 0, 0, 0, 0, 0}, {0, 0, gap, 0, 0, 0, 0, 0}, {0, 0, gap, 0, 0, 0, 0, 0 } };

	const char* blue_char[16] = { "楚", "士1", "士2", "象1", "象2", "馬1", "馬2", "車1", "車2", "包1", "包2", "兵1", "兵2", "兵3", "兵4", "兵5" };
	const char* red_char[16] = { "漢", "士1", "士2", "象1", "象2", "馬1", "馬2", "車1", "車2", "包1", "包2", "卒1", "卒2", "卒3", "卒4", "卒5" };

	/*for (int i; i < 20; i++) {
	}*/

	win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);  // 폰트설정
	win.outtextxy(150, 50, "장 기 GAME");   // 문자열출력
	win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);  // 폰트설정
	win.outtextxy(100, 300, "enter any key for the next stage");

	while (1) {
		if (win.kbhit()) {                     // 키보드 입력여부 
			char key = (char)win.getch();         // 입력이 있는 경우 호출
			std::cout << key << std::endl; // 입력값 확인
			win.cleardevice(); // clear screen      // 화면을 지움
			break;                    // 프로그램 중지 
		}
		win.delay(100);                       // 100ms를 멈춤   
	}
	for (int y = 0; y < 10; y++) {
		win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
	}

	for (int x = 0; x < 9; x++) {
		win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
	}
	win.line(3 * gap + offset, offset, 4 * gap + offset, offset + 1 * gap);
	win.line(5 * gap + offset, offset, 4 * gap + offset, offset + 1 * gap);
	win.line(3 * gap + offset, 2 * gap + offset, 4 * gap + offset, offset + 1 * gap);
	win.line(5 * gap + offset, 2 * gap + offset, 4 * gap + offset, offset + 1 * gap);

	for (int blue = 0; blue < 16; blue++) {
		blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
	}

	for (int red = 0; red < 16; red++) {
		redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
	}

	while (1) {
		// vertical lines 
		int a = 22;
		for (int y = 0; y < 10; y++) {
			win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
		}

		for (int x = 0; x < 9; x++) {
			win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
		}
		diagonal();

		for (int blue = 0; blue < 16; blue++) {
			blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
		}

		for (int red = 0; red < 16; red++) {
			redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
		}
		if (attacknum == 0) {
			cout << "홍팀의 차례입니다. 홍 : 漢" << endl;
			dot = 0;
			movechange = 0;
			while (true) {
			CHOOSEONE:
				while (true) {
					if (win.kbhit()) {                     // 키보드 입력여부 
						char key = (int)win.getch();
						if (key == RIGHT) {
							++dot;
							if (dot == 16) {
								dot = 0;
							}
							cout << "홍 : " << red_char[dot] << endl;
						}
						if (key == LEFT) {
							--dot;
							if (dot < 0) {
								dot = 15;
							}
							cout << "홍 : " << red_char[dot] << endl;
						}
						if (key == ENTER) {
							break;
						}
					}
				}

				if (dot == 0) {
					while (true) {
						for (int y = 0; y < 10; y++) {
							win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
						}

						for (int x = 0; x < 9; x++) {
							win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
						}

						for (int blue = 0; blue < 16; blue++) {
							blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
						}

						for (int red = 0; red < 16; red++) {
							redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
						}
						diagonal();
						char key = (int)win.getch();
						if (key == ESC) {
							cout << "다시 선택하시겠습니다." << endl;
							goto CHOOSEONE;
						}
						if (key == SPACE) {
							if (movechange == 8) {
								movechange = 0;
							}
							newmovex = move_x[dot][movechange];
							newmovey = move_y[dot][movechange];
							newx = red_x[dot] * gap + move_x[dot][movechange];
							newy = red_y[dot] * gap + move_y[dot][movechange];
							smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
							blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
							++movechange;
						}
						if (key == ENTER) {
							for (int i = 0; i < 16; i++) {
								if (i == dot) {
								}
								else {
									if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
										r = i;
										cout << "말이 있는 곳으로는 움직일 수 없습니다." << endl;
										break;
									}
									else {
										r = 22;
									}
								}
							}

							for (int n = 0; n < 1; n++) {
								if ((newx < 3 * gap - 1) || (newx > 5 * gap + 1) || (newy < -1) || (newy > 2 * gap + 1)) {
									r = n;
									cout << "판 바깥으로는 움직일 수 없습니다." << endl;
									break;
								}
							}

							if (r == 22) {
								for (int i = 0; i < 16; i++) {
									if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
										a = i;
										cout << blue_char[i] << " " << "아웃!" << endl;
									}
								}
								if (a != 22) {
									blue_y[a] = 12;
									blueone[a].movebhorse(win2, gap * a, gap * 12, blue_char[a]);
									if (a == 0) {
										cout << "대결이 끝났습니다. 홍팀 승리!" << endl;
										break;
									}
								}
								redone[dot].moverhorse(win2, newx, newy, red_char[dot]);
								smallredone[dot].makesrhorse(win2, newx, 1000, red_char[dot]);
								red_x[dot] = newx / gap;
								red_y[dot] = newy / gap;
								break;
							}
						}
					}
				}

				// 선비들 움직임
				if ((dot == 1) || (dot == 2)) {
					if (red_y[dot] == 11) {
						cout << "이미 끝난 장기말입니다." << endl;
						goto CHOOSEONE;
					}
					else {
						while (true) {
							for (int y = 0; y < 10; y++) {
								win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
							}

							for (int x = 0; x < 9; x++) {
								win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
							}

							for (int blue = 0; blue < 16; blue++) {
								blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
							}

							for (int red = 0; red < 16; red++) {
								redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
							}
							diagonal();
							char key = (int)win.getch();
							if (key == ESC) {
								cout << "다시 선택하시겠습니다." << endl;
								goto CHOOSEONE;
							}
							if (key == SPACE) {
								if (movechange == 8) {
									movechange = 0;
								}
								newmovex = move_x[dot][movechange];
								newmovey = move_y[dot][movechange];
								newx = red_x[dot] * gap + move_x[dot][movechange];
								newy = red_y[dot] * gap + move_y[dot][movechange];
								smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
								blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
								++movechange;
							}
							if (key == ENTER) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
											r = i;
											cout <<  "말이 있는 곳으로는 움직일 수 없습니다." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}

								for (int n = 0; n < 1; n++) {
									if ((newx < 3 * gap - 1) || (newx > 5 * gap + 1) || (newy < -1) || (newy > 2 * gap + 1)) {
										r = n;
										cout << "판 바깥으로는 움직일 수 없습니다." << endl;
										break;
									}
								}

								if (r == 22) {
									for (int i = 0; i < 16; i++) {
										if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
											a = i;
											cout << blue_char[i] << " " << "아웃!" << endl;
										}
									}
									if (a != 22) {
										blue_y[a] = 12;
										blueone[a].movebhorse(win2, gap * a, gap * 12, blue_char[a]);
										if (a == 0) {
											cout << "대결이 끝났습니다. 홍팀 승리!" << endl;
											break;
										}
									}
									redone[dot].moverhorse(win2, newx, newy, red_char[dot]);
									smallredone[dot].makesrhorse(win2, newx, 1000, red_char[dot]);
									red_x[dot] = newx / gap;
									red_y[dot] = newy / gap;
									break;
								}
							}
						}
					}
				}

				// 코끼리 움직임
				if ((dot == 3) || (dot == 4)) {
					while (true) {
						for (int y = 0; y < 10; y++) {
							win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
						}

						for (int x = 0; x < 9; x++) {
							win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
						}

						for (int blue = 0; blue < 16; blue++) {
							blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
						}

						for (int red = 0; red < 16; red++) {
							redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
						}
						diagonal();
						char key = (int)win.getch();
						if (key == ESC) {
							cout << "다시 선택하시겠습니다." << endl;
							goto CHOOSEONE;
						}
						if (key == SPACE) {
							if (movechange == 8) {
								movechange = 0;
							}
							newmovex = move_x[dot][movechange];
							newmovey = move_y[dot][movechange];
							newx = red_x[dot] * gap + move_x[dot][movechange];
							newy = red_y[dot] * gap + move_y[dot][movechange];
							smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
							blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
							++movechange;
						}
						if (key == ENTER) {
							for (int i = 0; i < 16; i++) {
								if ((newx == red_x[i] * gap + (move_x[dot][movechange - 1] / 2)) && (newy == red_y[i] * gap + (move_y[dot][movechange - 1] / 2))) {
									elephantnotmove++;
									cout << i;
								}
							}
							if (elephantnotmove == 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
											r = i;
											cout << "말이 있는 곳으로는 움직일 수 없습니다." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}
							else if (elephantnotmove != 0) {
								for (int i = 0; i < 1; i++) {
									r = dot;
									elephantnotmove = 0;
									cout << "그쪽으로는 움직일 수 없습니다 방향키를 다시 누르세요." << endl;
									break;
								}
							}


							for (int n = 0; n < 1; n++) {
								if ((newx < -1) || (newx > 8 * gap + 1) || (newy < -1) || (newy > 9 * gap + 1)) {
									r = n;
									cout << "판 바깥으로는 움직일 수 없습니다." << endl;
									break;
								}
							}

							if (r == 22) {
								for (int i = 0; i < 16; i++) {
									if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
										a = i;
										cout << blue_char[i] << " " << "아웃!" << endl;
									}
								}

								if (a != 22) {
									blue_y[a] = 15;
									blueone[a].movebhorse(win2, blue_x[a], gap * 15, blue_char[a]);
									if (a == 0) {
										cout << "대결이 끝났습니다. 홍팀 승리!" << endl;
										break;
									}
								}
								redone[dot].moverhorse(win2, newx, newy, red_char[dot]);
								smallredone[dot].makesrhorse(win2, newx, 1000, red_char[dot]);
								red_x[dot] = newx / gap;
								red_y[dot] = newy / gap;
								elephantnotmove = 0;
								break;
							}
						}
					}
				}

				//말 움직임
				if ((dot == 5) || (dot == 6)) {
					while (true) {
						for (int y = 0; y < 10; y++) {
							win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
						}

						for (int x = 0; x < 9; x++) {
							win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
						}

						for (int blue = 0; blue < 16; blue++) {
							blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
						}

						for (int red = 0; red < 16; red++) {
							redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
						}
						diagonal();
						char key = (int)win.getch();
						if (key == ESC) {
							cout << "다시 선택하시겠습니다." << endl;
							goto CHOOSEONE;
						}
						if (key == SPACE) {
							if (movechange == 8) {
								movechange = 0;
							}
							newmovex = move_x[dot][movechange];
							newmovey = move_y[dot][movechange];
							newx = red_x[dot] * gap + move_x[dot][movechange];
							newy = red_y[dot] * gap + move_y[dot][movechange];
							smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
							blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
							++movechange;
						}
						if (key == ENTER) {
							--movechange;
							if ((movechange == 0) || (movechange == 7)) {
								for (int i = 0; i < 16; i++) {
									if ((red_x[dot] == red_x[i] + 1) && red_y[dot] == red_y[i]) {
										horsenotmove++;
									}
								}
							}
							else if ((movechange == 6) || (movechange == 5)) {
								for (int i = 0; i < 16; i++) {
									if ((red_x[dot] == red_x[i]) && (red_y[dot] == red_y[i] + 1)) {
										horsenotmove++;
									}
								}
							}
							if ((movechange == 4) || (movechange == 3)) {
								for (int i = 0; i < 16; i++) {
									if ((red_x[dot] == red_x[i] - 1) && (red_y[dot] == red_y[i])) {
										horsenotmove++;
									}
								}
							}
							if ((movechange == 2) || (movechange == 1)) {
								for (int i = 0; i < 16; i++) {
									if ((red_x[dot] == red_x[i]) && (red_y[dot] == red_y[i] - 1)) {
										horsenotmove++;
									}
								}
							}

							if (horsenotmove == 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
											r = i;
											cout << "말이 있는 곳으로는 움직일 수 없습니다." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}

							if (horsenotmove != 0) {
								for (int i = 0; i < 1; i++) {
									r = dot;
									horsenotmove = 0;
									cout << "그쪽으로는 움직일 수 없습니다." << endl;
									break;
								}
							}

							for (int n = 0; n < 1; n++) {
								if ((newx < -1) || (newx > 8 * gap + 1) || (newy < -1) || (newy > 9 * gap + 1)) {
									r = n;
									cout << "판 바깥으로는 움직일 수 없습니다." << endl;
									break;
								}
							}

							if (r == 22) {
								for (int i = 0; i < 16; i++) {
									if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
										a = i;
										cout << blue_char[i] << " " << "아웃!" << endl;
									}
								}

								if (a != 22) {
									blue_y[a] = 15;
									blueone[a].movebhorse(win2, blue_x[a], gap * 15, blue_char[a]);
									if (a == 0) {
										cout << "대결이 끝났습니다. 홍팀 승리!" << endl;
										break;
									}
								}
								redone[dot].moverhorse(win2, newx, newy, red_char[dot]);
								smallredone[dot].makesrhorse(win2, newx, 1000, red_char[dot]);
								red_x[dot] = newx / gap;
								red_y[dot] = newy / gap;
								horsenotmove = 0;
								break;
							}
						}
					}
				}

				//차 움직임
				if ((dot == 7) || (dot == 8)) {
					while (true) {
						for (int y = 0; y < 10; y++) {
							win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
						}

						for (int x = 0; x < 9; x++) {
							win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
						}

						for (int blue = 0; blue < 16; blue++) {
							blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
						}

						for (int red = 0; red < 16; red++) {
							redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
						}
						diagonal();
						char key = (int)win.getch();
						if (key == ESC) {
							cout << "다시 선택하시겠습니다." << endl;
							goto CHOOSEONE;
						}
						if (key == LEFT) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = red_x[dot] * gap - move_x[dot][movechange];
									newy = red_y[dot] * gap;
									smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
									blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
									++movechange;
								}
								if (key == LEFT) {
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									left++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEONE;
								}
							}
						}

						if (key == RIGHT) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = red_x[dot] * gap + move_x[dot][movechange];
									newy = red_y[dot] * gap;
									smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
									blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
									++movechange;
								}
								if (key == RIGHT) {
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									right++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEONE;
								}
							}
						}

						if (key == UP) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = red_x[dot] * gap;
									newy = red_y[dot] * gap - move_y[dot][movechange];
									smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
									blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
									++movechange;
								}
								if (key == UP) {
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									up++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEONE;
								}
							}
						}

						if (key == DOWN) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = red_x[dot] * gap;
									newy = red_y[dot] * gap + move_y[dot][movechange];
									smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
									blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
									++movechange;
								}
								if (key == DOWN) {
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									down++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEONE;
								}
							}
						}

						if (key == ENTER) {
							for (int i = 0; i < 16; i++) {
								if (i == dot) {
								}
								else {
									if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
										r = i;
										cout <<  "말이 있는 곳으로는 움직일 수 없습니다." << endl;
										break;
									}
									else {
										r = 22;
									}
								}
							}

							for (int n = 0; n < 1; n++) {
								if ((newx < -1) || (newx > 8 * gap + 1) || (newy < -1) || (newy > 9 * gap + 1)) {
									r = n;
									cout << "판 바깥으로는 움직일 수 없습니다." << endl;
									break;
								}
							}

							if (left != 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx < red_x[i] * gap) && (newy == red_y[i] * gap)) {
											r = i;
											cout << "그쪽으로는 움직일 수 없습니다. 방향키를 눌러 다시 방향을 설정하세요." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}

							if (right != 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx > red_x[i] * gap) && (newy == red_y[i] * gap)) {
											r = i;
											cout << "그쪽으로는 움직일 수 없습니다. 방향키를 눌러 다시 방향을 설정하세요." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}

							if (up != 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == red_x[i] * gap) && (newy < red_y[i] * gap)) {
											r = i;
											cout << "그쪽으로는 움직일 수 없습니다. 방향키를 눌러 다시 방향을 설정하세요." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}

							if (down != 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == red_x[i] * gap) && (newy > red_y[i] * gap)) {
											r = i;
											cout << "그쪽으로는 움직일 수 없습니다. 방향키를 눌러 다시 방향을 설정하세요." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}

							if (r == 22) {
								for (int i = 0; i < 16; i++) {
									if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
										a = i;
										cout << blue_char[i] << " " << "아웃!" << endl;
									}
								}
								if (a != 22) {
									blue_y[a] = 15;
									blueone[a].movebhorse(win2, blue_x[a], gap * 15, blue_char[a]);
									if (a == 0) {
										cout << "대결이 끝났습니다. 홍팀 승리!" << endl;
										break;
									}
								}
								redone[dot].moverhorse(win2, newx, newy, red_char[dot]);
								smallredone[dot].makesrhorse(win2, newx, 1000, red_char[dot]);
								red_x[dot] = newx / gap;
								red_y[dot] = newy / gap;
								left = 0;
								right = 0;
								up = 0;
								down = 0;
								break;
							}
						}
					}
				}

				//포 움직임
				if ((dot == 9) || (dot == 10)) {
					while (true) {
						for (int y = 0; y < 10; y++) {
							win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
						}

						for (int x = 0; x < 9; x++) {
							win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
						}

						for (int blue = 0; blue < 16; blue++) {
							blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
						}

						for (int red = 0; red < 16; red++) {
							redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
						}
						diagonal();
						char key = (int)win.getch();
						if (key == ESC) {
							cout << "다시 선택하시겠습니다." << endl;
							goto CHOOSEONE;
						}
						if (key == LEFT) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = red_x[dot] * gap - move_x[dot][movechange];
									newy = red_y[dot] * gap;
									smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
									blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
									++movechange;
								}
								if (key == LEFT) {
									movechange = 0;
									left = 0;
									break;
								}
								if (key == ENTER) {
									left++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEONE;
								}
							}
						}

						if (key == RIGHT) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = red_x[dot] * gap + move_x[dot][movechange];
									newy = red_y[dot] * gap;
									smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
									blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
									++movechange;
								}
								if (key == RIGHT) {
									movechange = 0;
									right = 0;
									break;
								}
								if (key == ENTER) {
									right++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEONE;
								}
							}
						}

						if (key == UP) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = red_x[dot] * gap;
									newy = red_y[dot] * gap - move_y[dot][movechange];
									smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
									blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
									++movechange;
								}
								if (key == UP) {
									movechange = 0;
									up = 0;
									break;
								}
								if (key == ENTER) {
									up++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEONE;
								}
							}
						}

						if (key == DOWN) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = red_x[dot] * gap;
									newy = red_y[dot] * gap + move_y[dot][movechange];
									smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
									blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
									++movechange;
								}
								if (key == DOWN) {
									movechange = 0;
									down = 0;
									break;
								}
								if (key == ENTER) {
									down++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEONE;
								}
							}
						}

						if (key == ENTER) {
							for (int i = 0; i < 16; i++) {
								if (i == dot) {
								}
								else {
									if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
										r = i;
										cout << "말이 있는 곳으로는 움직일 수 없습니다." << endl;
										break;
									}
									else {
										r = 22;
									}
								}
							}

							for (int n = 0; n < 1; n++) {
								if ((newx < -1) || (newx > 8 * gap + 1) || (newy < -1) || (newy > 9 * gap + 1)) {
									r = dot;
									cout << "그쪽으로는 움직일 수 없습니다." << endl;;
									break;
								}
							}

							if (left != 0) {
								for (int i = 0; i < 16; i++) {
									if ((red_x[dot] > red_x[i]) && (newx < red_x[i] * gap) && (newy == red_y[i] * gap)) {
										++canonmove;
									}
								}
								if (canonmove == 0) {
									for (int i = 0; i < 1; i++) {
										r = 0;
										cout << "그쪽으로는 움직일 수 없습니다. 방향키를 다시 누르세요" << endl;
										break;
									}
								}
							}

							if (right != 0) {
								for (int i = 0; i < 16; i++) {
									if ((red_x[dot] < red_x[i]) && (newx > red_x[i] * gap) && (newy == red_y[i] * gap)) {
										++canonmove;
									}
								}
								if (canonmove == 0) {
									for (int i = 0; i < 1; i++) {
										r = 0;
										cout << "그쪽으로는 움직일 수 없습니다. 방향키를 다시 누르세요" << endl;
										break;
									}
								}
							}

							if (up != 0) {
								for (int i = 0; i < 16; i++) {
									if ((red_y[dot] > red_y[i]) && (newy < red_y[i] * gap) && (newx == red_x[i] * gap)) {
										++canonmove;
									}
								}
							    if (canonmove == 0) {
									for (int i = 0; i < 1; i++) {
										r = 0;
										cout << "그쪽으로는 움직일 수 없습니다. 방향키를 다시 누르세요" << endl;
										break;
									}
								}
							}

							if (down != 0) {
								for (int i = 0; i < 16; i++) {
									if ((red_y[dot] < red_y[i]) && (newy > red_y[i] * gap) && (newx == red_x[i] * gap)) {
										++canonmove;
									}
								}
								if (canonmove == 0) {
									for (int i = 0; i < 1; i++) {
										r = 0;
										cout << "그쪽으로는 움직일 수 없습니다. 방향키를 다시 누르세요" << endl;
										break;
									}
								}
							}


							if (r == 22) {
								for (int i = 0; i < 16; i++) {
									if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
										a = i;
										cout << blue_char[i] << " " << "아웃!" << endl;
									}
								}
								if (a != 22) {
									blue_y[a] = 15;
									blueone[a].movebhorse(win2, blue_x[a], gap * 15, blue_char[a]);
									if (a == 0) {
										cout << "대결이 끝났습니다. 홍팀 승리!" << endl;
										break;
									}
								}
								redone[dot].moverhorse(win2, newx, newy, red_char[dot]);
								smallredone[dot].makesrhorse(win2, newx, 1000, red_char[dot]);
								red_x[dot] = newx / gap;
								red_y[dot] = newy / gap;
								left = 0;
								right = 0;
								up = 0;
								down = 0;
								canonmove = 0;
								break;
							}
						}
					}
				}

				//졸 움직임
				if ((dot == 11) || (dot == 12) || (dot == 13) || (dot == 14) || (dot == 15)) {
					if (red_y[dot] == 11) {
						cout << "이미 끝난 장기말입니다." << endl;
						goto CHOOSEONE;
					}
					else {
						while (true) {
							for (int y = 0; y < 10; y++) {
								win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
							}

							for (int x = 0; x < 9; x++) {
								win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
							}

							for (int blue = 0; blue < 16; blue++) {
								blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
							}
							diagonal();

							for (int red = 0; red < 16; red++) {
								redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
							}
							char key = (int)win.getch();
							if (key == ESC) {
								cout << "다시 선택하시겠습니다." << endl;
								goto CHOOSEONE;
							}
							if (key == SPACE) {
								if (movechange == 8) {
									movechange = 0;
								}
								newmovex = move_x[dot][movechange];
								newmovey = move_y[dot][movechange];
								newx = red_x[dot] * gap + move_x[dot][movechange];
								newy = red_y[dot] * gap + move_y[dot][movechange];
								smallredone[dot].movesrhorse(win2, newx, newy, red_char[dot]);
								blueone[formerdot].makebhorse(win2, blue_x[formerdot] * gap, blue_y[formerdot] * gap, blue_char[formerdot]);
								++movechange;
							}
							if (key == ENTER) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
											r = i;
											cout << "말이 있는 곳으로는 움직일 수 없습니다." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}

								for (int n = 0; n < 1; n++) {
									if ((newx < -1) || (newx > 8 * gap + 1) || (newy < -1) || (newy > 9 * gap + 1)) {
										r = n;
										cout << "판 바깥으로는 움직일 수 없습니다." << endl;
										break;
									}
								}

								if (r == 22) {
									for (int i = 0; i < 16; i++) {
										if (i == dot) {
										}
										else {
											if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
												r = i;
												cout << "그쪽으로는 움직일 수 없습니다." << endl;
												break;
											}
											else {
												r = 22;
											}
										}
									}
									if (r == 22) {
										for (int i = 0; i < 16; i++) {
											if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
												a = i;
												cout << blue_char[i] << " " << "아웃!" << endl;
											}
										}
										if (a != 22) {
											blue_y[a] = 12;
											blueone[a].movebhorse(win2, gap * a, gap * 12, blue_char[a]);
											if (a == 0) {
												cout << "대결이 끝났습니다. 홍팀 승리!" << endl;
												break;
											}
										}
										redone[dot].moverhorse(win2, newx, newy, red_char[dot]);
										smallredone[dot].makesrhorse(win2, newx, 1000, red_char[dot]);
										red_x[dot] = newx / gap;
										red_y[dot] = newy / gap;
										break;
									}
								}
							}
						}
					}
					formerdot = dot;
				}
				break;
			}
		}
		if (a == 0) {
			win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);  // 폰트설정
			win.outtextxy(40, 50, "GAME OVER : RED WIN!");   // 문자열출력
			win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);  // 폰트설정
			win.outtextxy(100, 300, "PRESS ENTER TO TRY AGAIN");

			while (1) {
				if (win.kbhit()) {                     // 키보드 입력여부 
					char key = (char)win.getch();
					if (key == ENTER) {
						cout << "게임을 다시 시작합니다" << endl; // 입력값 확인
						win.cleardevice(); // clear screen      // 화면을 지움
						goto LETSGO;
						break;
					}// 입력이 있는 경우 호출
					else {
						break;
					}// 프로그램 중지 
				}
				win.delay(100);                       // 100ms를 멈춤   
			}
			break;
		}// 100ms를 멈춤   
		++attacknum;

		if (attacknum == 1) {
			a = 22;
			cout << "청팀의 차례입니다. 청 : 楚" << endl;
			dot = 0;
			movechange = 0;
			for (int y = 0; y < 10; y++) {
				win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
			}

			for (int x = 0; x < 9; x++) {
				win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
			}

			for (int blue = 0; blue < 16; blue++) {
				blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
			}

			for (int red = 0; red < 16; red++) {
				redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
			}
			diagonal();

			while (true) {
				CHOOSEANOTHER:
				while (true) {
					if (win.kbhit()) {                     // 키보드 입력여부 
						char key = (int)win.getch();
						if (key == RIGHT) {
							++dot;
							if (dot == 16) {
								dot = 0;
							}
							cout << "청 : " << blue_char[dot] << endl;;
						}
						if (key == LEFT) {
							--dot;
							if (dot < 0) {
								dot = 15;
							}
							cout << "청 : " << blue_char[dot] << endl;
						}
						if (key == ENTER) {
							break;
						}
					}
				}
				if (dot == 0) {
					while (true) {
						for (int y = 0; y < 10; y++) {
							win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
						}

						for (int x = 0; x < 9; x++) {
							win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
						}

						for (int blue = 0; blue < 16; blue++) {
							blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
						}

						for (int red = 0; red < 16; red++) {
							redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
						}
						diagonal();
						char key = (int)win.getch();
						if (key == ESC) {
							cout << "다시 선택하시겠습니다." << endl;
							goto CHOOSEANOTHER;
						}
						if (key == SPACE) {
							if (movechange == 8) {
								movechange = 0;
							}
							newx = blue_x[dot] * gap + move_x[dot][movechange];
							newy = blue_y[dot] * gap + move_y[dot][movechange];
							smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
							redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
							++movechange;
						}
						if (key == ENTER) {
							for (int i = 0; i < 16; i++) {
								if (i == dot) {
								}
								else {
									if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
										r = i;
										cout <<  "말이 있는 곳으로는 움직일 수 없습니다." << endl;
										break;
									}
									else {
										r = 22;
									}
								}
							}

							for (int n = 0; n < 1; n++) {
								if ((newx < 3 * gap - 1) || (newx > 5 * gap + 1) || (newy < 7 * gap - 1) || (newy > 9 * gap + 1)) {
									r = n;
									cout << "판 바깥으로는 움직일 수 없습니다." << endl;
									break;
								}
							}

							if (r == 22) {
								for (int i = 0; i < 16; i++) {
									if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
										a = i;
										cout << red_char[i] << " " << "아웃!" << endl;
									}
								}

								if (a != 22) {
									red_y[a] = 11;
									redone[a].moverhorse(win2, gap * a, gap * 11, red_char[a]);
									if (a == 0) {
										cout << "대결이 끝났습니다. 청팀 승리!" << endl;
										break;
									}
								}
								blueone[dot].movebhorse(win2, newx, newy, blue_char[dot]);
								smallblueone[dot].makesbhorse(win2, newx, 1000, blue_char[dot]);
								blue_x[dot] = newx / gap;
								blue_y[dot] = newy / gap;
								break;
							}
						}
					}
				}

				// 선비들 움직임
				if ((dot == 1) || (dot == 2)) {
					if (blue_y[dot] == 12) {
						cout << "더이상 움직일 수 없는 장기말입니다" << endl;
						goto CHOOSEANOTHER;
					}
					else {
						while (true) {
							for (int y = 0; y < 10; y++) {
								win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
							}

							for (int x = 0; x < 9; x++) {
								win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
							}

							for (int blue = 0; blue < 16; blue++) {
								blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
							}

							for (int red = 0; red < 16; red++) {
								redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
							}
							diagonal();
							char key = (int)win.getch();
							if (key == ESC) {
								cout << "다시 선택하시겠습니다." << endl;
								goto CHOOSEANOTHER;
							}
							if (key == SPACE) {
								if (movechange == 8) {
									movechange = 0;
								}
								newx = blue_x[dot] * gap + move_x[dot][movechange];
								newy = blue_y[dot] * gap + move_y[dot][movechange];
								smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
								redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
								++movechange;
							}
							if (key == ENTER) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
											r = i;
											cout <<  "말이 있는 곳으로는 움직일 수 없습니다." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}

								for (int n = 0; n < 1; n++) {
									if ((newx < 3 * gap - 1) || (newx > 5 * gap + 1) || (newy < 7 * gap - 1) || (newy > 9 * gap + 1)) {
										r = n;
										cout << "판 바깥으로는 움직일 수 없습니다." << endl;
										break;
									}
								}

								if (r == 22) {
									for (int i = 0; i < 16; i++) {
										if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
											a = i;
											cout << red_char[i] << " " << "아웃!" << endl;
										}
									}
									if (a != 22) {
										red_y[a] = 11;
										redone[a].moverhorse(win2, gap * a, gap * 11, red_char[a]);
										if (a == 0) {
											cout << "대결이 끝났습니다. 청팀 승리!" << endl;
											break;
										}
									}
									blueone[dot].movebhorse(win2, newx, newy, blue_char[dot]);
									smallblueone[dot].makesbhorse(win2, newx, 1000, blue_char[dot]);
									blue_x[dot] = newx / gap;
									blue_y[dot] = newy / gap;
									break;
								}
							}
						}
					}
				}

				// 코끼리 움직임
				if ((dot == 3) || (dot == 4)) {
					while (true) {
						for (int y = 0; y < 10; y++) {
							win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
						}

						for (int x = 0; x < 9; x++) {
							win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
						}

						for (int blue = 0; blue < 16; blue++) {
							blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
						}

						for (int red = 0; red < 16; red++) {
							redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
						}
						diagonal();
						char key = (int)win.getch();
						if (key == ESC) {
							cout << "다시 선택하시겠습니다." << endl;
							goto CHOOSEANOTHER;
						}
						if (key == SPACE) {
							if (movechange == 8) {
								movechange = 0;
							}
							newx = blue_x[dot] * gap + move_x[dot][movechange];
							newy = blue_y[dot] * gap + move_y[dot][movechange];
							smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
							redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
							++movechange;
						}
						if (key == ENTER) {
							for (int i = 0; i < 16; i++) {
								if ((newx == blue_x[i] * gap + (move_x[dot][movechange - 1] / 2)) && (newy == blue_y[i] * gap + (move_y[dot][movechange - 1] / 2))) {
									elephantnotmove++;
									cout << i;
								}
							}
							if (elephantnotmove == 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
											r = i;
											cout <<  "말이 있는 곳으로는 움직일 수 없습니다." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}
							else if (elephantnotmove != 0) {
								for (int i = 0; i < 1; i++) {
									r = dot;
									elephantnotmove = 0;
									cout << "그쪽으로는 움직일 수 없습니다. 방향키를 다시 누르세요." << endl;
									break;
								}
							}

							for (int n = 0; n < 1; n++) {
								if ((newx < -1) || (newx > 8 * gap + 1) || (newy < -1) || (newy > 9 * gap + 1)) {
									r = n;
									cout << "판 바깥으로는 움직일 수 없습니다." << endl;
									break;
								}
							}

							if (r == 22) {
								for (int i = 0; i < 16; i++) {
									if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
										a = i;
										cout << red_char[i] << " " << "아웃!" << endl;
									}
								}
								if (a != 22) {
									blue_y[a] = 14;
									blueone[a].movebhorse(win2, blue_x[a], gap * 14, blue_char[a]);
									if (a == 0) {
										cout << "대결이 끝났습니다. 청팀 승리!" << endl;
										break;
									}
								}
								blueone[dot].movebhorse(win2, newx, newy, blue_char[dot]);
								smallblueone[dot].makesbhorse(win2, newx, 1000, blue_char[dot]);
								blue_x[dot] = newx / gap;
								blue_y[dot] = newy / gap;
								break;
							}
						}
					}
				}

				//말 움직임
				if ((dot == 5) || (dot == 6)) {
					while (true) {
						for (int y = 0; y < 10; y++) {
							win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
						}

						for (int x = 0; x < 9; x++) {
							win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
						}

						for (int blue = 0; blue < 16; blue++) {
							blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
						}

						for (int red = 0; red < 16; red++) {
							redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
						}
						diagonal();
						char key = (int)win.getch();
						if (key == ESC) {
							cout << "다시 선택하시겠습니다." << endl;
							goto CHOOSEANOTHER;
						}
						if (key == SPACE) {
							if (movechange == 8) {
								movechange = 0;
							}
							newx = blue_x[dot] * gap + move_x[dot][movechange];
							newy = blue_y[dot] * gap + move_y[dot][movechange];
							smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
							redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
							++movechange;
						}
						if (key == ENTER) {
							--movechange;
							if ((movechange == 0) || (movechange == 7)) {
								for (int i = 0; i < 16; i++) {
									if ((blue_x[dot] == blue_x[i] + 1) && blue_y[dot] == blue_y[i]) {
										horsenotmove++;
									}
								}
							}
							else if ((movechange == 6) || (movechange == 5)) {
								for (int i = 0; i < 16; i++) {
									if ((blue_x[dot] == blue_x[i]) && (blue_y[dot] == blue_y[i] + 1)) {
										horsenotmove++;
									}
								}
							}
							if ((movechange == 4) || (movechange == 3)) {
								for (int i = 0; i < 16; i++) {
									if ((blue_x[dot] == blue_x[i] - 1) && (blue_y[dot] == blue_y[i])) {
										horsenotmove++;
									}
								}
							}
							if ((movechange == 2) || (movechange == 1)) {
								for (int i = 0; i < 16; i++) {
									if ((blue_x[dot] == blue_x[i]) && (blue_y[dot] == blue_y[i] - 1)) {
										horsenotmove++;
									}
								}
							}

							if (horsenotmove == 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
											r = i;
											cout <<  "말이 있는 곳으로는 움직일 수 없습니다." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}

							if (horsenotmove != 0) {
								for (int i = 0; i < 1; i++) {
									r = dot;
									horsenotmove = 0;
									cout << "그쪽으로는 움직일 수 없습니다." << endl;
									break;
								}
							}


							for (int n = 0; n < 1; n++) {
								if ((newx < -1) || (newx > 8 * gap + 1) || (newy < -1) || (newy > 9 * gap + 1)) {
									r = n;
									cout << "판 바깥으로는 움직일 수 없습니다." << endl;
									break;
								}
							}

							if (r == 22) {
								for (int i = 0; i < 16; i++) {
									if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
										a = i;
										cout << red_char[i] << " " << "아웃!" << endl;
									}
								}
								if (a != 22) {
									blue_y[a] = 14;
									blueone[a].movebhorse(win2, blue_x[a], gap * 14, blue_char[a]);
									if (a == 0) {
										cout << "대결이 끝났습니다. 청팀 승리!" << endl;
										break;
									}
								}
								blueone[dot].movebhorse(win2, newx, newy, blue_char[dot]);
								smallblueone[dot].makesbhorse(win2, newx, 1000, blue_char[dot]);
								blue_x[dot] = newx / gap;
								blue_y[dot] = newy / gap;
								break;
							}
						}
					}
				}

				//차 움직임
				if ((dot == 7) || (dot == 8)) {
					while (true) {
						for (int y = 0; y < 10; y++) {
							win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
						}

						for (int x = 0; x < 9; x++) {
							win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
						}

						for (int blue = 0; blue < 16; blue++) {
							blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
						}

						for (int red = 0; red < 16; red++) {
							redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
						}
						diagonal();
						char key = (int)win.getch();
						if (key == ESC) {
							cout << "다시 선택하시겠습니다." << endl;
							goto CHOOSEANOTHER;
						}
						if (key == LEFT) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = blue_x[dot] * gap - move_x[dot][movechange];
									newy = blue_y[dot] * gap;
									smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
									redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
									++movechange;
								}
								if (key == LEFT) {
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									left++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEANOTHER;
								}
							}
						}

						if (key == RIGHT) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = blue_x[dot] * gap + move_x[dot][movechange];
									newy = blue_y[dot] * gap;
									smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
									redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
									++movechange;
								}
								if (key == RIGHT) {
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									right++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEANOTHER;
								}
							}
						}

						if (key == UP) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = blue_x[dot] * gap;
									newy = blue_y[dot] * gap - move_x[dot][movechange];
									smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
									redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
									++movechange;
								}
								if (key == UP) {
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									up++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEANOTHER;
								}
							}
						}

						if (key == DOWN) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = blue_x[dot] * gap;
									newy = blue_y[dot] * gap + move_x[dot][movechange];
									smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
									redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
									++movechange;
								}
								if (key == DOWN) {
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									down++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEANOTHER;
								}
							}
						}

						if (key == ENTER) {
							for (int i = 0; i < 16; i++) {
								if (i == dot) {
								}
								else {
									if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
										r = i;
										cout <<  "말이 있는 곳으로는 움직일 수 없습니다." << endl;
										break;
									}
									else {
										r = 22;
									}
								}
							}

							for (int n = 0; n < 1; n++) {
								if ((newx < -1) || (newx > 8 * gap + 1) || (newy < -1) || (newy > 9 * gap + 1)) {
									r = n;
									cout << "판 바깥으로는 움직일 수 없습니다." << endl;
									break;
								}
							}

							if (left != 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx < blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
											r = i;
											cout << "그쪽으로는 움직일 수 없습니다. 방향키를 눌러 다시 방향을 설정하세요." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}

							if (right != 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx > blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
											cout << i << endl;
											r = i;
											cout << "그쪽으로는 움직일 수 없습니다. 방향키를 눌러 다시 방향을 설정하세요." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}

							if (up != 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == blue_x[i] * gap) && (newy < blue_y[i] * gap)) {
											r = i;
											cout << "그쪽으로는 움직일 수 없습니다. 방향키를 눌러 다시 방향을 설정하세요." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}

							if (down != 0) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == blue_x[i] * gap) && (newy > blue_y[i] * gap)) {
											r = i;
											cout << "그쪽으로는 움직일 수 없습니다. 방향키를 눌러 다시 방향을 설정하세요." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}
							}

							if (r == 22) {
								for (int i = 0; i < 16; i++) {
									if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
										a = i;
										cout << red_char[i] << " " << "아웃!" << endl;
									}
								}
								if (a != 22) {
									blue_y[a] = 14;
									blueone[a].movebhorse(win2, blue_x[a], gap * 14, blue_char[a]);
									if (a == 0) {
										cout << "대결이 끝났습니다. 청팀 승리!" << endl;
										break;
									}
								}
								blueone[dot].movebhorse(win2, newx, newy, blue_char[dot]);
								smallblueone[dot].makesbhorse(win2, newx, 1000, blue_char[dot]);
								blue_x[dot] = newx / gap;
								blue_y[dot] = newy / gap;
								left = 0;
								right = 0;
								up = 0;
								down = 0;
								break;
							}
						}
					}
				}

				//포 움직임
				if ((dot == 9) || (dot == 10)) {
					while (true) {
						for (int y = 0; y < 10; y++) {
							win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
						}

						for (int x = 0; x < 9; x++) {
							win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
						}

						for (int blue = 0; blue < 16; blue++) {
							blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
						}

						for (int red = 0; red < 16; red++) {
							redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
						}
						diagonal();
						char key = (int)win.getch();
						if (key == ESC) {
							cout << "다시 선택하시겠습니다." << endl;
							goto CHOOSEANOTHER;
						}
						if (key == LEFT) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = blue_x[dot] * gap - move_x[dot][movechange];
									newy = blue_y[dot] * gap;
									smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
									redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
									++movechange;
								}
								if (key == LEFT) {
									left = 0;
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									left++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEANOTHER;
								}
							}
						}

						if (key == RIGHT) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = blue_x[dot] * gap + move_x[dot][movechange];
									newy = blue_y[dot] * gap;
									smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
									redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
									++movechange;
								}
								if (key == RIGHT) {
									right = 0;
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									right++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEANOTHER;
								}
							}
						}

						if (key == UP) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = blue_x[dot] * gap;
									newy = blue_y[dot] * gap - move_x[dot][movechange];
									smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
									redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
									++movechange;
								}
								if (key == UP) {
									up = 0;
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									up++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEANOTHER;
								}
							}
						}

						if (key == DOWN) {
							while (true) {
								for (int y = 0; y < 10; y++) {
									win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
								}

								for (int x = 0; x < 9; x++) {
									win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
								}

								for (int blue = 0; blue < 16; blue++) {
									blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
								}

								for (int red = 0; red < 16; red++) {
									redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
								}
								diagonal();
								key = (int)win.getch();
								if (key == SPACE) {
									if (movechange == 8) {
										movechange = 0;
									}
									newx = blue_x[dot] * gap;
									newy = blue_y[dot] * gap + move_x[dot][movechange];
									smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
									redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
									++movechange;
								}
								if (key == DOWN) {
									down = 0;
									movechange = 0;
									break;
								}
								if (key == ENTER) {
									down++;
									break;
								}
								if (key == ESC) {
									cout << "다시 선택하시겠습니다." << endl;
									goto CHOOSEANOTHER;
								}
							}
						}

						if (key == ENTER) {
							for (int i = 0; i < 16; i++) {
								if (i == dot) {
								}
								else {
									if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
										r = i;
										cout <<  "말이 있는 곳으로는 움직일 수 없습니다." << endl;
										break;
									}
									else {
										r = 22;
									}
								}
							}

							for (int n = 0; n < 1; n++) {
								if ((newx < -1) || (newx > 8 * gap + 1) || (newy < -1) || (newy > 9 * gap + 1)) {
									r = n;
									cout << "판 바깥으로는 움직일 수 없습니다." << endl;
									break;
								}
							}

							if (left != 0) {
								for (int i = 0; i < 16; i++) {
									if ((blue_x[dot] > blue_x[i]) && (newx < blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
										++canonmove;
									}
								}
								if (canonmove == 0) {
									for (int i = 0; i < 1; i++) {
										r = 0;
										cout << "그쪽으로는 움직일 수 없습니다. 방향키를 다시 누르세요" << endl;
										break;
									}
								}
							}

							if (right != 0) {
								for (int i = 0; i < 16; i++) {
									if ((blue_x[dot] < blue_x[i]) && (newx > blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
										++canonmove;
									}
								}
								
								if (canonmove == 0) {
									for (int i = 0; i < 1; i++) {
										r = 0;
										cout << "그쪽으로는 움직일 수 없습니다. 방향키를 다시 누르세요" << endl;
										break;
									}
								}
							}

							if (up != 0) {
								for (int i = 0; i < 16; i++) {
									if ((blue_y[dot] > blue_y[i]) && (newy < blue_y[i] * gap) && (newx == blue_x[i] * gap)) {
										++canonmove;
									}
								}
								
								if (canonmove == 0) {
									for (int i = 0; i < 1; i++) {
										r = 0;
										cout << "그쪽으로는 움직일 수 없습니다. 방향키를 다시 누르세요" << endl;
										break;
									}
								}
							}

							if (down != 0) {
								for (int i = 0; i < 16; i++) {
									if ((blue_y[dot] < blue_y[i]) && (newy > blue_y[i] * gap) && (newx == blue_x[i] * gap)) {
										++canonmove;
									}
								}
								if (canonmove == 0) {
									for (int i = 0; i < 1; i++) {
										r = 0;
										cout << "그쪽으로는 움직일 수 없습니다. 방향키를 다시 누르세요" << endl;
										break;
									}
								}
							}


							if (r == 22) {
								for (int i = 0; i < 16; i++) {
									if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
										a = i;
										cout << red_char[i] << " " << "아웃!" << endl;
									}
								}
								if (a != 22) {
									blue_y[a] = 14;
									blueone[a].movebhorse(win2, blue_x[a], gap * 14, blue_char[a]);
									if (a == 0) {
										cout << "대결이 끝났습니다. 청팀 승리!" << endl;
										break;
									}
								}
								blueone[dot].movebhorse(win2, newx, newy, blue_char[dot]);
								smallblueone[dot].makesbhorse(win2, newx, 1000, blue_char[dot]);
								blue_x[dot] = newx / gap;
								blue_y[dot] = newy / gap;
								left = 0;
								right = 0;
								up = 0;
								down = 0;
								break;
							}
						}
					}
				}

				//졸 움직임
				if ((dot == 11) || (dot == 12) || (dot == 13) || (dot == 14) || (dot == 15)) {
					if (blue_y[dot] == 12) {
						cout << "더이상 움직일 수 없는 장기말입니다" << endl;
						goto CHOOSEANOTHER;
					}
					else {
						while (true) {
							for (int y = 0; y < 10; y++) {
								win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
							}

							for (int x = 0; x < 9; x++) {
								win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
							}

							for (int blue = 0; blue < 16; blue++) {
								blueone[blue].makebhorse(win2, blue_x[blue] * gap, blue_y[blue] * gap, blue_char[blue]);
							}

							for (int red = 0; red < 16; red++) {
								redone[red].makerhorse(win2, red_x[red] * gap, red_y[red] * gap, red_char[red]);
							}
							diagonal();
							char key = (int)win.getch();
							if (key == ESC) {
								cout << "다시 선택하시겠습니다." << endl;
								goto CHOOSEANOTHER;
							}
							if (key == SPACE) {
								if (movechange == 8) {
									movechange = 0;
								}
								newx = blue_x[dot] * gap + move_x[dot][movechange];
								newy = blue_y[dot] * gap - move_y[dot][movechange];
								smallblueone[dot].movesbhorse(win2, newx, newy, blue_char[dot]);
								redone[formerdot].makerhorse(win2, red_x[formerdot] * gap, red_y[formerdot] * gap, red_char[formerdot]);
								++movechange;
							}
							if (key == ENTER) {
								for (int i = 0; i < 16; i++) {
									if (i == dot) {
									}
									else {
										if ((newx == blue_x[i] * gap) && (newy == blue_y[i] * gap)) {
											r = i;
											cout <<  "말이 있는 곳으로는 움직일 수 없습니다." << endl;
											break;
										}
										else {
											r = 22;
										}
									}
								}

								for (int n = 0; n < 1; n++) {
									if ((newx < -1) || (newx > 8 * gap + 1) || (newy < -1) || (newy > 9 * gap + 1)) {
										r = n;
										cout << "판 바깥으로는 움직일 수 없습니다." << endl;
										break;
									}
								}

								if (r == 22) {
									for (int i = 0; i < 16; i++) {
										if ((newx == red_x[i] * gap) && (newy == red_y[i] * gap)) {
											a = i;
											cout << red_char[i] << " " << "아웃!" << endl;
										}
									}
									if (a != 22) {
										red_y[a] = 11;
										redone[a].moverhorse(win2, gap * a, gap * 11, red_char[a]);
										if (a == 0) {
											cout << "대결이 끝났습니다. 청팀 승리!" << endl;
											break;
										}
									}
									blueone[dot].movebhorse(win2, newx, newy, blue_char[dot]);
									smallblueone[dot].makesbhorse(win2, newx, 1000, blue_char[dot]);
									blue_x[dot] = newx / gap;
									blue_y[dot] = newy / gap;
									break;
								}
							}
						}
					}
				
				}
				break;
			}
		}
		--attacknum;
		win.delay(100);
		if (a == 0) {
			win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);  // 폰트설정
			win.outtextxy(40, 50, "GAME OVER : BLUE WIN!");   // 문자열출력
			win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);  // 폰트설정
			win.outtextxy(100, 300, "PRESS ENTER TO TRY AGAIN");

			while (1) {
				if (win.kbhit()) {                     // 키보드 입력여부 
					char key = (char)win.getch(); 
					if (key == ENTER) {
						cout << "게임을 다시 시작합니다" << endl; // 입력값 확인
						win.cleardevice(); // clear screen      // 화면을 지움
						goto LETSGO;
						break;
					}// 입력이 있는 경우 호출
					else {
						break;
					}// 프로그램 중지 
				}
				win.delay(100);                       // 100ms를 멈춤   
			}
			break;
		}// 100ms를 멈춤   
	}
}
