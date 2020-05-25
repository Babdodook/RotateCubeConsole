#include"basics.h"

void DrawLine(int Array[][50], float x0, float y0, float x1, float y1)
{
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy;

	while (true)
	{
		//pos(x0, y0); printf("*");
		Array[(int)y0][(int)x0] = 1;
		if (x0 == x1 && y0 == y1)
			break;
		float e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
		//printf("y0: %d, x0: %d\n");
	}
}


void pos(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
