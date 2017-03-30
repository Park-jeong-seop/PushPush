#include <iostream>
#include <conio.h>
#include "Consola.h"
#include "View.h"
#include "Map.h"
#include "Temp.h"
using namespace std;

int chcount = 0;//맵 모양과 색을 정해줌

int main()
{
	
	_setcursortype(1);//커서가 깜박거리지 않게 함
	View Main, Make;//객체 선언
	Map Map;//객체 선언
	Temp mapcolor;
	chcount=mapcolor.colormap();
	Main.mainScreen(chcount);//메인화면 
	clrscr();//화면 지우기
	Make.map(Map.stage1, chcount);//스테이지1
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

