#include "Control.h"
#include "Temp.h"
#include "View.h"
#include "Map.h"
#include "Consola.h"
#include <conio.h>
#include <iostream>
using namespace std;

int Control::count = 1000;//SCORE 점수 저장 변수

int Control::ClearCheck(int stage[M_MAXY + 1][M_MAXX + 1]){//스테이지 클리어 확인
	int data;//박스번호 저장받을 변수
	int x, y;
	for (y = M_MINX; y < M_MAXX + 1; y++) {//M_MINX <= x <M_MAXX+1 반복
		for (x = M_MINY; x < M_MAXY + 1; x++) {//M_MINY <= y <M_MAXY+1 반복
			data = stage[x][y];//data에 stage[x][y] 저장
			if (data == 2)	return 0;// 박스를 하나라도 발견하게 되면 0을 돌려준다. 
		}
	}
	return 1;
}

int Control::key(){//화살표 입력 함수
	int ch;//화살표 입력받을 변수
	return ((ch = _getch()) == 0xe0) ? ((ch << 8) | _getch()) : ch;
	//입력이 화살표 같은 특수키이면 왼쪽으로 쉬프트
}

void Control::maincontrol(int chcount){//시작 화면에서의 캐릭터 컨트롤
	View Old, New, view;//객체 선언
	Control control;//객체 선언
	int ch;//화살표 입력받을 변수
	int x = (M_MAXX + M_MINX) / 2, y = (M_MAXY + M_MINY) / 2 + 5;//캐릭터 좌표 변수
	int oldx, oldy;//캐릭터 이전 위치 변수

	while ((ch = key()) != 'q'){//입력값이 'q'가 아닐 동안
		oldx = x, oldy = y;//캐릭터 위치 저장
		switch (ch){//ch 값에 따라 case 실행
		case M_UPKEY://ch가 위 화살표일때
			if (y > M_MINY + 11)y--; break;//y > M_MINY + 11일때만 캐릭터 이동
		case M_DOWNKEY:
			if (y < M_MAXY - 1)y++; break;
		case M_LEFTKEY:
			if (x > M_MINX + 2)x -= 2; break;
		case M_RIGHTKEY:
			if (x < M_MAXX - 3)x += 2; break;
		}
		if (x != oldx || y != oldy){//캐릭터가 이동 했다면
			Old.Xyputstr(oldx, oldy, " ", 0);//이전위치 지우기
			if (chcount == 1) New.Xyputstr(x, y, "†", 7);//이동위치에 캐릭터 그리기
			else if (chcount == 2) New.Xyputstr(x, y, "§", 2);//이동위치에 캐릭터 그리기
		}
		if (ch == 'r'){//'r'을 누르면 맵, 캐릭터 초기화
			view.mainScreen(chcount);//시작화면 그리기
			break;
			control.maincontrol(chcount);//시작화면의 컨트롤
			break;
		}
		if (ch == 'y')//'y'을 누르면 게임 시작
			break;
		else if (ch == 'n')//'n'을 눌르면
			exit(0);//게임 종료
	}
}

int Control::Stagecontrol(int stage[M_MAXY + 1][M_MAXX + 1], int chcount){//스테이지 에서의 캐릭터 컨트롤
	View draw;//객체 선언
	Temp character, point;//객체 선언
	Map map;//객체 선언
	Control count;//객체 선언
	int MapStore[M_MAXY + 1][M_MAXX + 1], tempx, tempy;// 맵 저장 변수, 맵의 (x,y)좌표
	for (tempy = M_MINX; tempy < M_MAXX + 1; tempy++)//M_MINX <= tempx <M_MAXX+1 반복
		for (tempx = M_MINY; tempx < M_MAXY + 1; tempx++)//M_MINY <= tempy <M_MAXY+1 반복
			MapStore[tempx][tempy] = stage[tempx][tempy];//스테이지 저장
	int ch, tempCount;//키보드 입력값 저장, SCORE 값 저장
	int x = character.charcheckX(stage), y = character.charcheckY(stage);//캐릭터 위치 저장
	draw.record(count.count);//SCORE 값 표시
	tempCount = count.count;//맵을 새로 고침 할때 SCORE 값 저장
	while ((ch = key()) != 'q'){//입력값이 'q'가 아닐 동안
		switch (ch){//ch값에 따라 case 실행
			case M_UPKEY://위 화살표이면
				count.count -= 10;//SCORE값 -10
				if (stage[y - 1][x] == 2){//캐릭터 다음 위치에 상자가 있으면서
					if (stage[y - 2][x] == 1 || stage[y - 2][x] == 2 || stage[y - 2][x] == 4){
						//캐릭터 다다음 위치에 벽, 상자, 완성 목적지가 있으면
						count.count += 10;//SCORE값 원래대로 
						break;}
					else if (stage[y - 2][x] == 3){//캐릭터 다다음 위치에 목적지가 있으면
						stage[y - 1][x] = 6, stage[y - 2][x] = 4;
						if (chcount==1) draw.Xyputstr(x, y - 2, "●", 9);//chcount==1 이면 첫번째 맵 인터페이스 그리기
						else if(chcount == 2) draw.Xyputstr(x, y - 2, "★", 14);//chcount==2 이면 첫번째 맵 인터페이스 그리기
					}//다음위치 공백, 다다음 위치 완성 목적지로 변경
					else if (stage[y - 2][x] == 6){////캐릭터 다음 위치에 상자가 있으면서 다다음 위치에 공백이 있으면
						stage[y - 1][x] = 6, stage[y - 2][x] = 2;
						if (chcount == 1) draw.Xyputstr(x, y - 2, "♥", 4);
						else if (chcount == 2) draw.Xyputstr(x, y - 2, "♠", 9);
					}//다음위치 공백, 다다음 위치 상자로 변경
				}
				if (stage[y - 1][x] == 4){//캐릭터 다음 위치에 완성 목적지가 있으면서
					if (stage[y - 2][x] == 1 || stage[y - 2][x] == 2 || stage[y - 2][x] == 4){
						//캐릭터 다다음 위치에 벽, 상자, 완성 목적지가 있으면
						count.count += 10;//SCORE값 원래대로 
						break;
					}
					else if (stage[y - 2][x] == 3){//캐릭터 다다음 위치에 목적지가 있으면
						stage[y - 1][x] = 3, stage[y - 2][x] = 4;
						if (chcount == 1) draw.Xyputstr(x, y - 2, "●", 9);
						else if (chcount == 2) draw.Xyputstr(x, y - 2, "★", 14);
					}//다음위치 목적지, 다다음 위치 완성 목적지로 변경
					else if (stage[y - 2][x] == 6){//캐릭터 다다음 위치에 공백이 있으면
						stage[y - 1][x] = 3, stage[y - 2][x] = 2;
						if (chcount == 1) draw.Xyputstr(x, y - 2, "♥", 4);
						else if (chcount == 2) draw.Xyputstr(x, y - 2, "♠", 9);
					}//다음위치 목적지, 다다음 위치 상자로 변경
				}
				if (stage[y - 1][x] != 1){//캐릭터 다음 위치에 벽이 아니면
					y--;//캐릭터 위로 이동
					if(chcount==1) draw.Xyputstr(x, y, "†", 7);
					else if (chcount == 2) draw.Xyputstr(x, y, "§", 2);
					if (stage[y + 1][x] != 3) stage[y + 1][x] = 6, draw.Xyputstr(x, y + 1, " ", 0);
					//캐릭터 위치가 목적지가 아니면 캐릭터 이동후에 이전 위치를 공백으로 변경 
					else {
						if (chcount == 1) draw.Xyputstr(x, y + 1, "○", 9);//캐릭터 위치가 목적지이면
						else if (chcount == 2) draw.Xyputstr(x, y + 1, "☆", 14);
					}//캐릭터 이동후에 이전 위치를 목적지로 변경
				}
				else count.count += 10;//키보드 입력후 캐릭터가 움직이지 않으면 SCORE값 원래대로 
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
						if (chcount == 1) draw.Xyputstr(x, y + 2, "●", 9);
						else if (chcount == 2) draw.Xyputstr(x, y + 2, "★", 14);
					}
					else if (stage[y + 2][x] == 6){
						stage[y + 1][x] = 6, stage[y + 2][x] = 2;
						if (chcount == 1) draw.Xyputstr(x, y + 2, "♥", 4);
						else if (chcount == 2) draw.Xyputstr(x, y + 2, "♠", 9);
					}
				}
				if (stage[y + 1][x] == 4){
					if (stage[y + 2][x] == 1 || stage[y + 2][x] == 2 || stage[y + 2][x] == 4){
						count.count += 10;
						break;
					}
					else if (stage[y + 2][x] == 3){
						stage[y + 1][x] = 3, stage[y + 2][x] = 4;
						if (chcount == 1) draw.Xyputstr(x, y + 2, "●", 9);
						else if (chcount == 2) draw.Xyputstr(x, y + 2, "★", 14);
					}
					else if (stage[y + 2][x] == 6){
						stage[y + 1][x] = 3, stage[y + 2][x] = 2;
						if (chcount == 1) draw.Xyputstr(x, y + 2, "♥", 4);
						else if (chcount == 2) draw.Xyputstr(x, y + 2, "♠", 9);
					}
				}
				if (stage[y + 1][x] != 1){
					y++;
					if (chcount == 1) draw.Xyputstr(x, y, "†", 7);
					else if (chcount == 2) draw.Xyputstr(x, y, "§", 2);
					if (stage[y - 1][x] != 3) stage[y - 1][x] = 6, draw.Xyputstr(x, y - 1, " ", 0);
					else{
						if (chcount == 1) draw.Xyputstr(x, y - 1, "○", 9);
						else if (chcount == 2) draw.Xyputstr(x, y - 1, "☆", 14);
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
						if (chcount == 1) draw.Xyputstr(x - 4, y, "●", 9);
						else if (chcount == 2) draw.Xyputstr(x - 4, y, "★", 14);
					}
					else if (stage[y][x - 4] == 6){
						stage[y][x - 2] = 6, stage[y][x - 4] = 2;
						if (chcount == 1) draw.Xyputstr(x - 4, y, "♥", 4);
						else if (chcount == 2) draw.Xyputstr(x - 4, y, "♠", 9);
					}
				}
				if (stage[y][x - 2] == 4){
					if (stage[y][x - 4] == 1 || stage[y][x - 4] == 2 || stage[y][x - 4] == 4){
						count.count += 10;
						break;
					}
					else if (stage[y][x - 4] == 3){
						stage[y][x - 2] = 3, stage[y][x - 4] = 4;
						if (chcount == 1) draw.Xyputstr(x - 4, y, "●", 9);
						else if (chcount == 2) draw.Xyputstr(x - 4, y, "★", 14);
					}
					else if (stage[y][x - 4] == 6){
						stage[y][x - 2] = 3, stage[y][x - 4] = 2;
						if (chcount == 1) draw.Xyputstr(x - 4, y, "♥", 4);
						else if (chcount == 2) draw.Xyputstr(x - 4, y, "♠", 9);
					}
				}
				if (stage[y][x - 2] != 1){
					x -= 2;
					if (chcount == 1) draw.Xyputstr(x, y, "†", 7);
					else if (chcount == 2) draw.Xyputstr(x, y, "§", 2);
					if (stage[y][x + 2] != 3) stage[y][x + 2] = 6, draw.Xyputstr(x + 2, y, " ", 0);
					else{
						if (chcount == 1) draw.Xyputstr(x + 2, y, "○", 9);
						else if (chcount == 2) draw.Xyputstr(x + 2, y, "☆", 14);
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
						if (chcount == 1) draw.Xyputstr(x + 4, y, "●", 9);
						else if (chcount == 2) draw.Xyputstr(x + 4, y, "★", 14);
					}
					else if (stage[y][x + 4] == 6){
						stage[y][x + 2] = 6, stage[y][x + 4] = 2;
						if (chcount == 1) draw.Xyputstr(x + 4, y, "♥", 4);
						else if (chcount == 2) draw.Xyputstr(x + 4, y, "♠", 9);
					}
				}
				if (stage[y][x + 2] == 4){
					if (stage[y][x + 4] == 1 || stage[y][x + 4] == 2 || stage[y][x + 4] == 4){
						count.count += 10;
						break;
					}
					else if (stage[y][x + 4] == 3){
						stage[y][x + 2] = 3, stage[y][x + 4] = 4;
						if (chcount == 1) draw.Xyputstr(x + 4, y, "●", 9);
						else if (chcount == 2) draw.Xyputstr(x + 4, y, "★", 14);
					}
					else if (stage[y][x + 4] == 6){
						stage[y][x + 2] = 3, stage[y][x + 4] = 2;
						if (chcount == 1) draw.Xyputstr(x + 4, y, "♥", 4);
						else if (chcount == 2) draw.Xyputstr(x + 4, y, "♠", 9);
					}
				}
				if (stage[y][x + 2] != 1){
					x += 2;
					if (chcount == 1) draw.Xyputstr(x, y, "†", 7);
					else if (chcount == 2) draw.Xyputstr(x, y, "§", 2);
					if (stage[y][x - 2] != 3) stage[y][x - 2] = 6, draw.Xyputstr(x - 2, y, " ", 0);
					else{
						if (chcount == 1) draw.Xyputstr(x - 2, y, "○", 9);
						else if (chcount == 2) draw.Xyputstr(x - 2, y, "☆", 14);
					}
				}
				else
					count.count += 10;
				break;
			}
		draw.record(count.count);//움직일때마다 SCORE의 감소를 나타내줌
		if (ClearCheck(stage)){//맵을 클리어 했는지 움직일때마다 확인
			if (stage != map.stage5){//stage가 1~4일때
				clrscr(), draw.clear();//화면을 지우고 클리어 화면을 보여줌
				if (ch == 'y'){//입력이 y일때 
					count.count = point.clearPoint(stage, count.count);//클리어 점수를 score에다 더함
					break;//클리어화면 끝
				}
			}
			else if (stage == map.stage5){//stage가 5일때
				count.count = point.clearPoint(stage, count.count);//클리어 점수를 score에다 더함
				clrscr(), draw.result(count.count);//화면을 지우고 결과창을 보여줌
			}
		}
		if (ch == 'r'){//'r'을 입력하면
			count.count = tempCount;//SCORE 저장
			clrscr();//화면 지우기
			draw.map(MapStore, chcount);//저장된 맵 그리기
			break;
		}

	}
	return 0;
}
