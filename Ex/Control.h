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
	static int count;//SCORE ���� ���� ����
	static int key();//ȭ��ǥ �Է� �Լ�
	static int ClearCheck(int stage[M_MAXY + 1][M_MAXX + 1]);//�������� Ŭ���� Ȯ��
public:
	void maincontrol(int chcount);//���� ȭ�鿡���� ĳ���� ��Ʈ��
	int Stagecontrol(int map[M_MAXY + 1][M_MAXX + 1], int chcount);//�������� ������ ĳ���� ��Ʈ��
};

#endif CONTROL_H