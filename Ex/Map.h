#ifndef MAP_H
#define MAP_H
#define M_MINX 1
#define M_MINY 1
#define M_MAXX 41
#define M_MAXY 21

class Map{
public:
	static int stage1[M_MAXY+1][M_MAXX+1];//stage1�� �� �ڷᱸ��
	static int stage2[M_MAXY+1][M_MAXX+1];//stage2�� �� �ڷᱸ��
	static int stage3[M_MAXY+1][M_MAXX+1];//stage3�� �� �ڷᱸ��
	static int stage4[M_MAXY+1][M_MAXX+1];//stage4�� �� �ڷᱸ��
	static int stage5[M_MAXY+1][M_MAXX+1];//stage5�� �� �ڷᱸ��
	static int main[M_MAXY+1][M_MAXX+1];//����ȭ���� �� �ڷᱸ��

};

#endif MAP_H