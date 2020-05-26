#pragma once
#include"basics.h"
#include"RectTransform.h"

int main()
{
	//system("mode con: cols=100 lines=50");

	
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	
	RectTransform* rect = new RectTransform();


	//rect->DrawRect();
	while (1)
	{
		rect->GetKey();
	}


	/*
	for (int i = 0; i < 4; i++)
		printf("%d // %d,%d\n", i, (int)rect->position[i].x, (int)rect->position[i].y);

	rect->Rotate();
	printf("\nAfter Rotate\n\n");

	for (int i = 0; i < 4; i++)
		printf("%d // %d,%d\n", i, (int)rect->position[i].x, (int)rect->position[i].y);

	system("pause");
	*/

	delete rect;
	rect = nullptr;
	return 0;
}
