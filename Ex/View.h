#ifndef VIEW_H
#define VIEW_H
#define M_MINX 1
#define M_MINY 1
#define M_MAXX 41
#define M_MAXY 21

class View{
public:
	void explain();//���� �������̽� ȭ��
	void result(int count);//���� ��� ȭ��
	void clear();//�������� Ŭ����ȭ��
	void record(int count);//���� ȭ��
	void Xyputstr(int x, int y, char str[], int color);//(x,y) ��ǥ�� ���� ���ڿ� ���
	void mainScreen(int chcount);//���� ȭ�� �׸���
	void map(int map[M_MAXY + 1][M_MAXX + 1], int chcount);//�������� �������̽� �׸���
	int Draw(int map[M_MAXY + 1][M_MAXX + 1],int chcount);//�������� �׸���
};

#endif VIEW_H