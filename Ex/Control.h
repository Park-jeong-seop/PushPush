#ifndef CONTROL_H
#define CONTROL_H
#define M_UPKEY		0xe048
#define M_DOWNKEY	0xe050
#define M_LEFTKEY	0xe04b
#define M_RIGHTKEY	0xe04d
#define M_MINX 1
#define M_MINY 1
#define M_MAXX 41
#define M_MAXY 21

class Control{
	static int count;//SCORE 점수 저장 변수
	static int key();//화살표 입력 함수
	static int ClearCheck(int stage[M_MAXY + 1][M_MAXX + 1]);//스테이지 클리어 확인
public:
	void maincontrol(int chcount);//시작 화면에서의 캐릭터 컨트롤
	int Stagecontrol(int map[M_MAXY + 1][M_MAXX + 1], int chcount);//스테이지 에서의 캐릭터 컨트롤
};

#endif CONTROL_H