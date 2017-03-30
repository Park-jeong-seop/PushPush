#include "Control.h"
#include "Temp.h"
#include "View.h"
#include "Map.h"
#include "Consola.h"
#include <conio.h>
#include <iostream>
using namespace std;

int Control::count = 1000;//SCORE ���� ���� ����

int Control::ClearCheck(int stage[M_MAXY + 1][M_MAXX + 1]){//�������� Ŭ���� Ȯ��
	int data;//�ڽ���ȣ ������� ����
	int x, y;
	for (y = M_MINX; y < M_MAXX + 1; y++) {//M_MINX <= x <M_MAXX+1 �ݺ�
		for (x = M_MINY; x < M_MAXY + 1; x++) {//M_MINY <= y <M_MAXY+1 �ݺ�
			data = stage[x][y];//data�� stage[x][y] ����
			if (data == 2)	return 0;// �ڽ��� �ϳ��� �߰��ϰ� �Ǹ� 0�� �����ش�. 
		}
	}
	return 1;
}

int Control::key(){//ȭ��ǥ �Է� �Լ�
	int ch;//ȭ��ǥ �Է¹��� ����
	return ((ch = _getch()) == 0xe0) ? ((ch << 8) | _getch()) : ch;
	//�Է��� ȭ��ǥ ���� Ư��Ű�̸� �������� ����Ʈ
}

void Control::maincontrol(int chcount){//���� ȭ�鿡���� ĳ���� ��Ʈ��
	View Old, New, view;//��ü ����
	Control control;//��ü ����
	int ch;//ȭ��ǥ �Է¹��� ����
	int x = (M_MAXX + M_MINX) / 2, y = (M_MAXY + M_MINY) / 2 + 5;//ĳ���� ��ǥ ����
	int oldx, oldy;//ĳ���� ���� ��ġ ����

	while ((ch = key()) != 'q'){//�Է°��� 'q'�� �ƴ� ����
		oldx = x, oldy = y;//ĳ���� ��ġ ����
		switch (ch){//ch ���� ���� case ����
		case M_UPKEY://ch�� �� ȭ��ǥ�϶�
			if (y > M_MINY + 11)y--; break;//y > M_MINY + 11�϶��� ĳ���� �̵�
		case M_DOWNKEY:
			if (y < M_MAXY - 1)y++; break;
		case M_LEFTKEY:
			if (x > M_MINX + 2)x -= 2; break;
		case M_RIGHTKEY:
			if (x < M_MAXX - 3)x += 2; break;
		}
		if (x != oldx || y != oldy){//ĳ���Ͱ� �̵� �ߴٸ�
			Old.Xyputstr(oldx, oldy, " ", 0);//������ġ �����
			if (chcount == 1) New.Xyputstr(x, y, "��", 7);//�̵���ġ�� ĳ���� �׸���
			else if (chcount == 2) New.Xyputstr(x, y, "��", 2);//�̵���ġ�� ĳ���� �׸���
		}
		if (ch == 'r'){//'r'�� ������ ��, ĳ���� �ʱ�ȭ
			view.mainScreen(chcount);//����ȭ�� �׸���
			break;
			control.maincontrol(chcount);//����ȭ���� ��Ʈ��
			break;
		}
		if (ch == 'y')//'y'�� ������ ���� ����
			break;
		else if (ch == 'n')//'n'�� ������
			exit(0);//���� ����
	}
}

int Control::Stagecontrol(int stage[M_MAXY + 1][M_MAXX + 1], int chcount){//�������� ������ ĳ���� ��Ʈ��
	View draw;//��ü ����
	Temp character, point;//��ü ����
	Map map;//��ü ����
	Control count;//��ü ����
	int MapStore[M_MAXY + 1][M_MAXX + 1], tempx, tempy;// �� ���� ����, ���� (x,y)��ǥ
	for (tempy = M_MINX; tempy < M_MAXX + 1; tempy++)//M_MINX <= tempx <M_MAXX+1 �ݺ�
		for (tempx = M_MINY; tempx < M_MAXY + 1; tempx++)//M_MINY <= tempy <M_MAXY+1 �ݺ�
			MapStore[tempx][tempy] = stage[tempx][tempy];//�������� ����
	int ch, tempCount;//Ű���� �Է°� ����, SCORE �� ����
	int x = character.charcheckX(stage), y = character.charcheckY(stage);//ĳ���� ��ġ ����
	draw.record(count.count);//SCORE �� ǥ��
	tempCount = count.count;//���� ���� ��ħ �Ҷ� SCORE �� ����
	while ((ch = key()) != 'q'){//�Է°��� 'q'�� �ƴ� ����
		switch (ch){//ch���� ���� case ����
			case M_UPKEY://�� ȭ��ǥ�̸�
				count.count -= 10;//SCORE�� -10
				if (stage[y - 1][x] == 2){//ĳ���� ���� ��ġ�� ���ڰ� �����鼭
					if (stage[y - 2][x] == 1 || stage[y - 2][x] == 2 || stage[y - 2][x] == 4){
						//ĳ���� �ٴ��� ��ġ�� ��, ����, �ϼ� �������� ������
						count.count += 10;//SCORE�� ������� 
						break;}
					else if (stage[y - 2][x] == 3){//ĳ���� �ٴ��� ��ġ�� �������� ������
						stage[y - 1][x] = 6, stage[y - 2][x] = 4;
						if (chcount==1) draw.Xyputstr(x, y - 2, "��", 9);//chcount==1 �̸� ù��° �� �������̽� �׸���
						else if(chcount == 2) draw.Xyputstr(x, y - 2, "��", 14);//chcount==2 �̸� ù��° �� �������̽� �׸���
					}//������ġ ����, �ٴ��� ��ġ �ϼ� �������� ����
					else if (stage[y - 2][x] == 6){////ĳ���� ���� ��ġ�� ���ڰ� �����鼭 �ٴ��� ��ġ�� ������ ������
						stage[y - 1][x] = 6, stage[y - 2][x] = 2;
						if (chcount == 1) draw.Xyputstr(x, y - 2, "��", 4);
						else if (chcount == 2) draw.Xyputstr(x, y - 2, "��", 9);
					}//������ġ ����, �ٴ��� ��ġ ���ڷ� ����
				}
				if (stage[y - 1][x] == 4){//ĳ���� ���� ��ġ�� �ϼ� �������� �����鼭
					if (stage[y - 2][x] == 1 || stage[y - 2][x] == 2 || stage[y - 2][x] == 4){
						//ĳ���� �ٴ��� ��ġ�� ��, ����, �ϼ� �������� ������
						count.count += 10;//SCORE�� ������� 
						break;
					}
					else if (stage[y - 2][x] == 3){//ĳ���� �ٴ��� ��ġ�� �������� ������
						stage[y - 1][x] = 3, stage[y - 2][x] = 4;
						if (chcount == 1) draw.Xyputstr(x, y - 2, "��", 9);
						else if (chcount == 2) draw.Xyputstr(x, y - 2, "��", 14);
					}//������ġ ������, �ٴ��� ��ġ �ϼ� �������� ����
					else if (stage[y - 2][x] == 6){//ĳ���� �ٴ��� ��ġ�� ������ ������
						stage[y - 1][x] = 3, stage[y - 2][x] = 2;
						if (chcount == 1) draw.Xyputstr(x, y - 2, "��", 4);
						else if (chcount == 2) draw.Xyputstr(x, y - 2, "��", 9);
					}//������ġ ������, �ٴ��� ��ġ ���ڷ� ����
				}
				if (stage[y - 1][x] != 1){//ĳ���� ���� ��ġ�� ���� �ƴϸ�
					y--;//ĳ���� ���� �̵�
					if(chcount==1) draw.Xyputstr(x, y, "��", 7);
					else if (chcount == 2) draw.Xyputstr(x, y, "��", 2);
					if (stage[y + 1][x] != 3) stage[y + 1][x] = 6, draw.Xyputstr(x, y + 1, " ", 0);
					//ĳ���� ��ġ�� �������� �ƴϸ� ĳ���� �̵��Ŀ� ���� ��ġ�� �������� ���� 
					else {
						if (chcount == 1) draw.Xyputstr(x, y + 1, "��", 9);//ĳ���� ��ġ�� �������̸�
						else if (chcount == 2) draw.Xyputstr(x, y + 1, "��", 14);
					}//ĳ���� �̵��Ŀ� ���� ��ġ�� �������� ����
				}
				else count.count += 10;//Ű���� �Է��� ĳ���Ͱ� �������� ������ SCORE�� ������� 
				break;
			case M_DOWNKEY:
				count.count -= 10;
				if (stage[y + 1][x] == 2){
					if (stage[y + 2][x] == 1 || stage[y + 2][x] == 2 || stage[y + 2][x] == 4){
						count.count += 10;
						break;
					}
					else if (stage[y + 2][x] == 3){
						stage[y + 1][x] = 6, stage[y + 2][x] = 4;
						if (chcount == 1) draw.Xyputstr(x, y + 2, "��", 9);
						else if (chcount == 2) draw.Xyputstr(x, y + 2, "��", 14);
					}
					else if (stage[y + 2][x] == 6){
						stage[y + 1][x] = 6, stage[y + 2][x] = 2;
						if (chcount == 1) draw.Xyputstr(x, y + 2, "��", 4);
						else if (chcount == 2) draw.Xyputstr(x, y + 2, "��", 9);
					}
				}
				if (stage[y + 1][x] == 4){
					if (stage[y + 2][x] == 1 || stage[y + 2][x] == 2 || stage[y + 2][x] == 4){
						count.count += 10;
						break;
					}
					else if (stage[y + 2][x] == 3){
						stage[y + 1][x] = 3, stage[y + 2][x] = 4;
						if (chcount == 1) draw.Xyputstr(x, y + 2, "��", 9);
						else if (chcount == 2) draw.Xyputstr(x, y + 2, "��", 14);
					}
					else if (stage[y + 2][x] == 6){
						stage[y + 1][x] = 3, stage[y + 2][x] = 2;
						if (chcount == 1) draw.Xyputstr(x, y + 2, "��", 4);
						else if (chcount == 2) draw.Xyputstr(x, y + 2, "��", 9);
					}
				}
				if (stage[y + 1][x] != 1){
					y++;
					if (chcount == 1) draw.Xyputstr(x, y, "��", 7);
					else if (chcount == 2) draw.Xyputstr(x, y, "��", 2);
					if (stage[y - 1][x] != 3) stage[y - 1][x] = 6, draw.Xyputstr(x, y - 1, " ", 0);
					else{
						if (chcount == 1) draw.Xyputstr(x, y - 1, "��", 9);
						else if (chcount == 2) draw.Xyputstr(x, y - 1, "��", 14);
					}
				}
				else
					count.count += 10;
				break;
			case M_LEFTKEY:
				count.count -= 10;
				if (stage[y][x - 2] == 2){
					if (stage[y][x - 4] == 1 || stage[y][x - 4] == 2 || stage[y][x - 4] == 4){
						count.count += 10;
						break;
					}
					else if (stage[y][x - 4] == 3){
						stage[y][x - 2] = 6, stage[y][x - 4] = 4;
						if (chcount == 1) draw.Xyputstr(x - 4, y, "��", 9);
						else if (chcount == 2) draw.Xyputstr(x - 4, y, "��", 14);
					}
					else if (stage[y][x - 4] == 6){
						stage[y][x - 2] = 6, stage[y][x - 4] = 2;
						if (chcount == 1) draw.Xyputstr(x - 4, y, "��", 4);
						else if (chcount == 2) draw.Xyputstr(x - 4, y, "��", 9);
					}
				}
				if (stage[y][x - 2] == 4){
					if (stage[y][x - 4] == 1 || stage[y][x - 4] == 2 || stage[y][x - 4] == 4){
						count.count += 10;
						break;
					}
					else if (stage[y][x - 4] == 3){
						stage[y][x - 2] = 3, stage[y][x - 4] = 4;
						if (chcount == 1) draw.Xyputstr(x - 4, y, "��", 9);
						else if (chcount == 2) draw.Xyputstr(x - 4, y, "��", 14);
					}
					else if (stage[y][x - 4] == 6){
						stage[y][x - 2] = 3, stage[y][x - 4] = 2;
						if (chcount == 1) draw.Xyputstr(x - 4, y, "��", 4);
						else if (chcount == 2) draw.Xyputstr(x - 4, y, "��", 9);
					}
				}
				if (stage[y][x - 2] != 1){
					x -= 2;
					if (chcount == 1) draw.Xyputstr(x, y, "��", 7);
					else if (chcount == 2) draw.Xyputstr(x, y, "��", 2);
					if (stage[y][x + 2] != 3) stage[y][x + 2] = 6, draw.Xyputstr(x + 2, y, " ", 0);
					else{
						if (chcount == 1) draw.Xyputstr(x + 2, y, "��", 9);
						else if (chcount == 2) draw.Xyputstr(x + 2, y, "��", 14);
					}
				}
				else
					count.count += 10;
				break;
			case M_RIGHTKEY:
				count.count -= 10;
				if (stage[y][x + 2] == 2){
					if (stage[y][x + 4] == 1 || stage[y][x + 4] == 2 || stage[y][x + 4] == 4){
						count.count += 10;
						break;
					}
					else if (stage[y][x + 4] == 3){
						stage[y][x + 2] = 6, stage[y][x + 4] = 4;
						if (chcount == 1) draw.Xyputstr(x + 4, y, "��", 9);
						else if (chcount == 2) draw.Xyputstr(x + 4, y, "��", 14);
					}
					else if (stage[y][x + 4] == 6){
						stage[y][x + 2] = 6, stage[y][x + 4] = 2;
						if (chcount == 1) draw.Xyputstr(x + 4, y, "��", 4);
						else if (chcount == 2) draw.Xyputstr(x + 4, y, "��", 9);
					}
				}
				if (stage[y][x + 2] == 4){
					if (stage[y][x + 4] == 1 || stage[y][x + 4] == 2 || stage[y][x + 4] == 4){
						count.count += 10;
						break;
					}
					else if (stage[y][x + 4] == 3){
						stage[y][x + 2] = 3, stage[y][x + 4] = 4;
						if (chcount == 1) draw.Xyputstr(x + 4, y, "��", 9);
						else if (chcount == 2) draw.Xyputstr(x + 4, y, "��", 14);
					}
					else if (stage[y][x + 4] == 6){
						stage[y][x + 2] = 3, stage[y][x + 4] = 2;
						if (chcount == 1) draw.Xyputstr(x + 4, y, "��", 4);
						else if (chcount == 2) draw.Xyputstr(x + 4, y, "��", 9);
					}
				}
				if (stage[y][x + 2] != 1){
					x += 2;
					if (chcount == 1) draw.Xyputstr(x, y, "��", 7);
					else if (chcount == 2) draw.Xyputstr(x, y, "��", 2);
					if (stage[y][x - 2] != 3) stage[y][x - 2] = 6, draw.Xyputstr(x - 2, y, " ", 0);
					else{
						if (chcount == 1) draw.Xyputstr(x - 2, y, "��", 9);
						else if (chcount == 2) draw.Xyputstr(x - 2, y, "��", 14);
					}
				}
				else
					count.count += 10;
				break;
			}
		draw.record(count.count);//�����϶����� SCORE�� ���Ҹ� ��Ÿ����
		if (ClearCheck(stage)){//���� Ŭ���� �ߴ��� �����϶����� Ȯ��
			if (stage != map.stage5){//stage�� 1~4�϶�
				clrscr(), draw.clear();//ȭ���� ����� Ŭ���� ȭ���� ������
				if (ch == 'y'){//�Է��� y�϶� 
					count.count = point.clearPoint(stage, count.count);//Ŭ���� ������ score���� ����
					break;//Ŭ����ȭ�� ��
				}
			}
			else if (stage == map.stage5){//stage�� 5�϶�
				count.count = point.clearPoint(stage, count.count);//Ŭ���� ������ score���� ����
				clrscr(), draw.result(count.count);//ȭ���� ����� ���â�� ������
			}
		}
		if (ch == 'r'){//'r'�� �Է��ϸ�
			count.count = tempCount;//SCORE ����
			clrscr();//ȭ�� �����
			draw.map(MapStore, chcount);//����� �� �׸���
			break;
		}

	}
	return 0;
}
