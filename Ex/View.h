#ifndef VIEW_H
#define VIEW_H
#define M_MINX 1
#define M_MINY 1
#define M_MAXX 41
#define M_MAXY 21

class View{
public:
	void explain();//게임 인터페이스 화면
	void result(int count);//게임 결과 화면
	void clear();//스테이지 클리어화면
	void record(int count);//점수 화면
	void Xyputstr(int x, int y, char str[], int color);//(x,y) 좌표에 색상 문자열 출력
	void mainScreen(int chcount);//시작 화면 그리기
	void map(int map[M_MAXY + 1][M_MAXX + 1], int chcount);//스테이지 인터페이스 그리기
	int Draw(int map[M_MAXY + 1][M_MAXX + 1],int chcount);//스테이지 그리기
};

#endif VIEW_H