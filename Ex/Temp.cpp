#include "Temp.h"
#include "Map.h"
#include "View.h"
#include "Consola.h"
#include <conio.h>
#include <iostream>
using namespace std;

int Temp::charcheckX(int stage[M_MAXY + 1][M_MAXX + 1]){//캐릭터의 x좌표 저장
	int data;//정수형 변수 선언
	int x, y;
	for (y = M_MINX; y < M_MAXX + 1; y++) {//M_MINX <= x <M_MAXX+1 반복
		for (x = M_MINY; x < M_MAXY + 1; x++) {//M_MINY <= x <M_MAXY+1 반복
			data = stage[x][y];//data에 stage[x][y] 저장
			if (data == 5)	return y; //datark 5일때 y 반환
		}
	}
	return 1;
}

int Temp::charcheckY(int stage[M_MAXY + 1][M_MAXX + 1]){//캐릭터의 y좌표 저장
	int data;
	int x, y;
	for (y = M_MINX; y < M_MAXX + 1; y++) {//M_MINX <= x <M_MAXX+1 반복
		for (x = M_MINY; x < M_MAXY + 1; x++) {//M_MINY <= x <M_MAXY+1 반복
			data = stage[x][y];//data에 stage[x][y] 저장
			if (data == 5)	return x;//datark 5일때 x 반환
		}
	}
	return 1;
}

int Temp::clearPoint(int stage[M_MAXY + 1][M_MAXX + 1], int count){
	// 클리어시 보상 점수
	Map map;//객체 map 선언
	if (stage == map.stage1)//stage가 첫번째 스테이지 이면
		count += 140;//SCORE 점수에 140 추가
	else if (stage == map.stage2)
		count += 480;
	else if (stage == map.stage3)
		count += 760;
	else if (stage == map.stage4)
		count += 1820;
	else if (stage == map.stage5)
		count += 2020;
	return count;//SCORE 점수 반환
}

int Temp::colormap(){//맵 구성을 보여주고 고르게함
	View make;
	int chcount;
	textbackground(0);
	clrscr();//화면 지우기
	make.Xyputstr(12, 5, "1 또는 2번을 눌러 맵과 캐릭터의 색깔, 모양을 고를 수 있습니다.", 15);
	make.Xyputstr(25, 8, "1 . ", 15);
	make.Xyputstr(30, 8, "▦", 2);
	make.Xyputstr(32, 8, " : 벽", 15);
	make.Xyputstr(30, 9, "♥", 4);
	make.Xyputstr(32, 9, " : 상자", 15);
	make.Xyputstr(30, 10, "○", 9);
	make.Xyputstr(32, 10, " : 목적지", 15);
	make.Xyputstr(30, 11, "●", 9);
	make.Xyputstr(32, 11, " : 상자가 있는 목적지", 15);
	make.Xyputstr(30, 12, "†", 7);
	make.Xyputstr(32, 12, " : 캐릭터", 15);

	make.Xyputstr(25, 14, "2 . ", 15);
	make.Xyputstr(30, 14, "▣", 8);
	make.Xyputstr(32, 14, " : 벽", 15);
	make.Xyputstr(30, 15, "♠", 9);
	make.Xyputstr(32, 15, " : 상자", 15);
	make.Xyputstr(30, 16, "☆", 14);
	make.Xyputstr(32, 16, " : 목적지", 15);
	make.Xyputstr(30, 17, "★", 14);
	make.Xyputstr(32, 17, " : 상자가 있는 목적지", 15);
	make.Xyputstr(30, 18, "§", 2);
	make.Xyputstr(32, 18, " : 캐릭터", 15);

	textbackground(15);
	make.Xyputstr(38, 20, "   ", 15);
	textcolor(0);
	gotoxy(39, 20);
	cin >> chcount;
	if (chcount == 1)
		return chcount; 
	else if (chcount == 2)
		return chcount;
	if (chcount != 1 || chcount != 2){
		make.Xyputstr(24, 22, "1또는 2를 누루지 않았습니다.", 0);
		make.Xyputstr(29, 23, "게임을 종료합니다.", 0);
		_getch();
		exit(0);
	}
}