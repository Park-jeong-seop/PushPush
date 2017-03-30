#include "View.h"
#include "Control.h"
#include "Map.h"
#include "Consola.h"
#include <conio.h>
#include <iostream>
using namespace std;

void View::Xyputstr(int x, int y, char str[], int color){
	//(x,y) 좌표에 색상 문자열 출력
	textcolor(color);//글자색 변경
	gotoxy(x, y);//(x,y) 좌표로 이동
	cout << str;//문자열 출력
}

void View::explain(){//게임 인터페이스 화면
	//textbackground(0);//글자 배경을 검은색으로 변경
	Xyputstr(M_MAXX + 10, M_MINY + 2, "※조작법※", YELLOW);//문자열 출력
	Xyputstr(M_MAXX + 14, M_MINY + 4, "↑ 위", 7);
	Xyputstr(M_MAXX + 9, M_MINY + 6, "←   ↓   →", 7);
	Xyputstr(M_MAXX + 7, M_MINY + 8, "왼쪽  아래  오른쪽", 7);
	Xyputstr(M_MAXX + 4, M_MINY + 11, "[R] : 현재 단계를 다시시작", 7);
	Xyputstr(M_MAXX + 4, M_MINY + 12, "[Q] : 다음 단계로 이동", 7);
	Xyputstr(M_MAXX + 11, M_MINY + 15, "S C O R E", RED);
	textcolor(7);
}

void View::result(int count){//게임 결과 화면
	char name[100];//문자열 변수 선언
	Xyputstr(26, 4, "이름을 입력하세요",7);//문자열 출력
	textbackground(15);//글자 배경을 흰색으로 변경
	Xyputstr(30, 6, "          ",7);
	textcolor(0);
	gotoxy(32, 6);
	cin >> name;//플레이어 이름 입력
	textbackground(0);
	clrscr();//화면 지우기
	Xyputstr(30, 10, "S C O R E\n",4);
	textcolor(15);
	gotoxy(28, 12);
	cout << name << " : " << count;//결과 출력
	Xyputstr(24, 16, "종료하시려면",7);
	Xyputstr(37, 16, "N",RED);
	Xyputstr(38, 16, "을 누르세요\n",7);
	char ch = _getch();//문자 한개 입력
	if (ch == 'n')//입력 문자가 n이면
		exit(0);//종료
	}

void View::clear(){//스테이지 클리어 화면
	clrscr();//화면 지우기
	Xyputstr(27, 10, "※ STAGE CLAER ※", GREEN);//문자열 출력
	Xyputstr(20, 12, "다음 단계로 가려면",7);
	Xyputstr(39, 12, "Y",YELLOW);
	Xyputstr(41, 12, "를 누르세요\n",7);
}

void View::record(int count){//점수 화면
	Xyputstr(M_MAXX + 13, M_MINY + 17, "             ", 7);//문자열 출력
	textcolor(7);
	gotoxy(M_MAXX + 13, M_MINY + 17);
	cout << count;//점수 출력
}

void View::mainScreen(int chcount){//시작화면 그리기
	Control control;//객체 control 선언
	Map map;//객체 map 선언
	textbackground(BLACK);//텍스트 배경 검정
	clrscr();//화면 지우기
	explain();//게임 인터페이스 화면
	Draw(map.main, chcount);//시작 화면 그리기
	textbackground(0);
	Xyputstr(M_MAXX / 4 + M_MINX, M_MINY + 3, "※ WELCOME PUSHPUSH ※\n",9);//문자열 출력
	Xyputstr(M_MAXX / 4 + M_MINX - 2, M_MINY + 6, "시작하시려면",7);
	Xyputstr(M_MAXX / 4 + M_MINX + 11, M_MINY + 6, "Y",YELLOW);
	Xyputstr(M_MAXX / 4 + M_MINX + 13, M_MINY + 6, "를 누르세요\n",7);
	Xyputstr(M_MAXX / 4 + M_MINX - 2, M_MINY + 7, "종료하시려면",7);
	Xyputstr(M_MAXX / 4 + M_MINX + 11, M_MINY + 7, "N",RED);
	Xyputstr(M_MAXX / 4 + M_MINX + 13, M_MINY + 7, "을 누르세요\n",7);
	control.maincontrol(chcount);//시작화면에서의 조작 
}

void View::map(int map[M_MAXY + 1][M_MAXX + 1], int chcount){//스테이지 인터페이스 그리기
	Control control;//객체 control 선언
	textbackground(0);//텍스트 배경 검정
	explain();//게임 인터페이스 화면
	Draw(map, chcount);//스테이지 그리기
	textcolor(7);
	control.Stagecontrol(map, chcount);//스테이지에서의 조작
}

int View::Draw(int map[M_MAXY + 1][M_MAXX + 1],int chcount){//스테이지 그리기
		for (int i = M_MINX; i < M_MAXX + 1; i++){//M_MINX <= x <M_MAXX+1 반복
			for (int j = M_MINY; j < M_MAXY + 1; j++){//M_MINY <= x <M_MAXY+1 반복
				switch (map[j][i]){//map[j][i] 값에 따라 case 실행
				case 1://map[j][i]=1일때
					if (chcount == 1){
						Xyputstr(i, j, "▦", 2);//문자열 출력
						break;
					}
					else if (chcount == 2){
						Xyputstr(i, j, "▣", 8);//문자열 출력
						break;
					}
				case 2:
					if (chcount == 1){
						Xyputstr(i, j, "♥", 4);//문자열 출력
						break;
					}
					else if (chcount == 2){
						Xyputstr(i, j, "♠", 9);//문자열 출력
						break;
					}
				case 3:
					if (chcount == 1){
						Xyputstr(i, j, "○", 9);//문자열 출력
						break;
					}
					else if (chcount == 2){
						Xyputstr(i, j, "☆", 14);//문자열 출력
						break;
					}
				case 4:
					if (chcount == 1){
						Xyputstr(i, j, "●", 9);//문자열 출력
						break;
					}
					else if (chcount == 2){
						Xyputstr(i, j, "★", 14);//문자열 출력
						break;
					}
				case 5:
					if (chcount == 1){
						Xyputstr(i, j, "†", 7);//문자열 출력
						break;
					}
					else if (chcount == 2){
						Xyputstr(i, j, "§", 2);//문자열 출력
						break;
					}
				case 6:
					Xyputstr(i, j, " ", 7);
					break;
				}
			}
		}
	return 0;
}
