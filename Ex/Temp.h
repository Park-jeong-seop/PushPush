#ifndef TEMP_H
#define TEMP_H

#define M_MINX 1
#define M_MINY 1
#define M_MAXX 41
#define M_MAXY 21

class Temp{
public:
	int charcheckX(int stage[M_MAXY + 1][M_MAXX + 1]);//ĳ������ x��ǥ ����
	int charcheckY(int stage[M_MAXY + 1][M_MAXX + 1]);//ĳ������ y��ǥ ����
	int clearPoint(int stage[M_MAXY + 1][M_MAXX + 1], int count);// Ŭ����� ���� ����
	int colormap();////�� ������ �����ְ� ������
};

#endif TEMP_H