#include <iostream>
#include <conio.h>
#include "Consola.h"
#include "View.h"
#include "Map.h"
#include "Temp.h"
using namespace std;

int chcount = 0;//�� ���� ���� ������

int main()
{
	
	_setcursortype(1);//Ŀ���� ���ڰŸ��� �ʰ� ��
	View Main, Make;//��ü ����
	Map Map;//��ü ����
	Temp mapcolor;
	chcount=mapcolor.colormap();
	Main.mainScreen(chcount);//����ȭ�� 
	clrscr();//ȭ�� �����
	Make.map(Map.stage1, chcount);//��������1
	clrscr();
	Make.map(Map.stage2, chcount);
	clrscr();
	Make.map(Map.stage3, chcount);
	clrscr();
	Make.map(Map.stage4, chcount);
	clrscr();
	Make.map(Map.stage5, chcount);
	return 0;
}

