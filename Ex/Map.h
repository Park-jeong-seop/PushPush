#ifndef MAP_H
#define MAP_H
#define M_MINX 1
#define M_MINY 1
#define M_MAXX 41
#define M_MAXY 21

class Map{
public:
	static int stage1[M_MAXY+1][M_MAXX+1];//stage1의 맵 자료구조
	static int stage2[M_MAXY+1][M_MAXX+1];//stage2의 맵 자료구조
	static int stage3[M_MAXY+1][M_MAXX+1];//stage3의 맵 자료구조
	static int stage4[M_MAXY+1][M_MAXX+1];//stage4의 맵 자료구조
	static int stage5[M_MAXY+1][M_MAXX+1];//stage5의 맵 자료구조
	static int main[M_MAXY+1][M_MAXX+1];//시작화면의 맵 자료구조

};

#endif MAP_H