#include "Temp.h"
#include "Map.h"
#include "View.h"
#include "Consola.h"
#include <conio.h>
#include <iostream>
using namespace std;

int Temp::charcheckX(int stage[M_MAXY + 1][M_MAXX + 1]){//ĳ������ x��ǥ ����
	int data;//������ ���� ����
	int x, y;
	for (y = M_MINX; y < M_MAXX + 1; y++) {//M_MINX <= x <M_MAXX+1 �ݺ�
		for (x = M_MINY; x < M_MAXY + 1; x++) {//M_MINY <= x <M_MAXY+1 �ݺ�
			data = stage[x][y];//data�� stage[x][y] ����
			if (data == 5)	return y; //datark 5�϶� y ��ȯ
		}
	}
	return 1;
}

int Temp::charcheckY(int stage[M_MAXY + 1][M_MAXX + 1]){//ĳ������ y��ǥ ����
	int data;
	int x, y;
	for (y = M_MINX; y < M_MAXX + 1; y++) {//M_MINX <= x <M_MAXX+1 �ݺ�
		for (x = M_MINY; x < M_MAXY + 1; x++) {//M_MINY <= x <M_MAXY+1 �ݺ�
			data = stage[x][y];//data�� stage[x][y] ����
			if (data == 5)	return x;//datark 5�϶� x ��ȯ
		}
	}
	return 1;
}

int Temp::clearPoint(int stage[M_MAXY + 1][M_MAXX + 1], int count){
	// Ŭ����� ���� ����
	Map map;//��ü map ����
	if (stage == map.stage1)//stage�� ù��° �������� �̸�
		count += 140;//SCORE ������ 140 �߰�
	else if (stage == map.stage2)
		count += 480;
	else if (stage == map.stage3)
		count += 760;
	else if (stage == map.stage4)
		count += 1820;
	else if (stage == map.stage5)
		count += 2020;
	return count;//SCORE ���� ��ȯ
}

int Temp::colormap(){//�� ������ �����ְ� ������
	View make;
	int chcount;
	textbackground(0);
	clrscr();//ȭ�� �����
	make.Xyputstr(12, 5, "1 �Ǵ� 2���� ���� �ʰ� ĳ������ ����, ����� �� �� �ֽ��ϴ�.", 15);
	make.Xyputstr(25, 8, "1 . ", 15);
	make.Xyputstr(30, 8, "��", 2);
	make.Xyputstr(32, 8, " : ��", 15);
	make.Xyputstr(30, 9, "��", 4);
	make.Xyputstr(32, 9, " : ����", 15);
	make.Xyputstr(30, 10, "��", 9);
	make.Xyputstr(32, 10, " : ������", 15);
	make.Xyputstr(30, 11, "��", 9);
	make.Xyputstr(32, 11, " : ���ڰ� �ִ� ������", 15);
	make.Xyputstr(30, 12, "��", 7);
	make.Xyputstr(32, 12, " : ĳ����", 15);

	make.Xyputstr(25, 14, "2 . ", 15);
	make.Xyputstr(30, 14, "��", 8);
	make.Xyputstr(32, 14, " : ��", 15);
	make.Xyputstr(30, 15, "��", 9);
	make.Xyputstr(32, 15, " : ����", 15);
	make.Xyputstr(30, 16, "��", 14);
	make.Xyputstr(32, 16, " : ������", 15);
	make.Xyputstr(30, 17, "��", 14);
	make.Xyputstr(32, 17, " : ���ڰ� �ִ� ������", 15);
	make.Xyputstr(30, 18, "��", 2);
	make.Xyputstr(32, 18, " : ĳ����", 15);

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
		make.Xyputstr(24, 22, "1�Ǵ� 2�� ������ �ʾҽ��ϴ�.", 0);
		make.Xyputstr(29, 23, "������ �����մϴ�.", 0);
		_getch();
		exit(0);
	}
}