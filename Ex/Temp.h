#ifndef TEMP_H
#define TEMP_H

#define M_MINX 1
#define M_MINY 1
#define M_MAXX 41
#define M_MAXY 21

class Temp{
public:
	int charcheckX(int stage[M_MAXY + 1][M_MAXX + 1]);//캐릭터의 x좌표 저장
	int charcheckY(int stage[M_MAXY + 1][M_MAXX + 1]);//캐릭터의 y좌표 저장
	int clearPoint(int stage[M_MAXY + 1][M_MAXX + 1], int count);// 클리어시 보상 점수
	int colormap();////맵 구성을 보여주고 고르게함
};

#endif TEMP_H