#pragma once
#include"RectTransform.h"
#include<conio.h>

RectTransform::RectTransform()
{
	position[0].SetPosition(15, 15, 10);
	position[1].SetPosition(35, 15, 10);
	position[2].SetPosition(15, 35, 10);
	position[3].SetPosition(35, 35, 10);


	ZeroMemory(ScreenArray, sizeof(ScreenArray));
	/*
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			ScreenArray[i][j] = 0;
		}
	}
	*/



	//ScreenArray[49][49] = 1;
}

RectTransform::~RectTransform()
{

}

void RectTransform::DrawRect()
{
	ZeroMemory(ScreenArray, sizeof(ScreenArray));

	for (int i = 0; i < 4; i++)
		//[round(position[i].y)][position[i].x] = 1;

	DrawLine(ScreenArray, position[0].x, position[0].y, position[1].x, position[1].y);
	DrawLine(ScreenArray, position[0].x, position[0].y, position[2].x, position[2].y);
	DrawLine(ScreenArray, position[1].x, position[1].y, position[3].x, position[3].y);
	DrawLine(ScreenArray, position[2].x, position[2].y, position[3].x, position[3].y);

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (ScreenArray[i][j] == 0)
				printf("  ");
			if (ScreenArray[i][j] == 1)
				printf("■");
		}
		printf("\n");
	}
}

void RectTransform::GetKey()
{
	if (_kbhit())
	{
		int key = _getch();
		if (key == 224 || key == 0)
		{
			key = _getch();
			switch (key)
			{
			case 75:
				Rotate();
				//system("cls");
				//DrawRect();
				break;
			}
		}
	}
}

int castFloatToInt(float num)
{
	float tempnum = (int)num - num;
	if (tempnum >= 0.5f)
		num += 1;

	return (int)num;
}

void RectTransform::Rotate()
{
	int degree = 30;
	Vector3D origin[4];

	for (int i = 0; i < 4; i++)
		origin[i] = position[i];

	for (int i = 0; i < 4; i++)
		ScreenArray[position[i].y][position[i].x] = 0;

	/*
	for (int i = 0; i < 4; i++)
	{
		position[i] = Viewport_Convert(position[i]);

		origin[i].x = (position[i].x * cos(degree * DEG2RAD) - position[i].y * sin(degree * DEG2RAD));
		origin[i].y = (position[i].x * sin(degree * DEG2RAD) + position[i].y * cos(degree * DEG2RAD));

		//printf("회전변환행렬 적용\n");
		//printf("x: %d y: %d\n", (int)origin[i].x, (int)origin[i].y);

		position[i] = Screen_Convert(origin[i]);
	}
	*/

	
	for (int i = 0; i < 1; i++)
	{
		//position[i] = Viewport_Convert(position[i]);
		printf("%d번째\n", i);
		printf("원점 이동 전: x: %d z: %d\n\n", position[i].x, position[i].z);

		position[i].x = position[i].x - 25;
		//position[i].z = 1;
		//position[i].z *= -1;
		printf("원점 이동 후: x: %d z: %d\n\n", (int)position[i].x, (int)position[i].z);

		float x;
		float y;
		float z;
		x = ((cos(degree * DEG2RAD))*position[i].x) + ((sin(degree * DEG2RAD))*position[i].z);
		y = position[i].y;
		z = ((-sin(degree * DEG2RAD))*position[i].x) + ((cos(degree * DEG2RAD))*position[i].z);
		
		origin[i].x = round(x);
		origin[i].y = round(y);
		origin[i].z = round(z);

		printf("x: %f cos : %f\n", x, cos(degree * DEG2RAD));
		printf("z: %f sin : %f\n", z, sin(degree * DEG2RAD));

		printf("원점 이동 후 회전 적용\n");
		printf("%d + %d = x : %d\n", (int)(position[i].x * cos(degree * DEG2RAD)), (int)(position[i].z * sin(degree * DEG2RAD)), origin[i].x);
		printf("%d + %d = z : %d\n\n", (int)(position[i].x * (-sin(degree * DEG2RAD))), (int)(position[i].z * cos(degree * DEG2RAD)), origin[i].z);
		
		origin[i].x += 25;
		//origin[i].z *= -1;
		origin[i].z = 10;
		printf("스크린 좌표로\n");
		printf("x: %d z: %d\n\n", origin[i].x, origin[i].z);
		
		position[i] = origin[i];
		//position[i] = Screen_Convert(origin[i]);
		//system("pause");
	}
	

	/*
	for (int i = 0; i < 4; i++)
	{
		position[i] = Viewport_Convert(position[i]);

		origin[i].x = position[i].x;
		origin[i].y = (position[i].y * cos(degree * DEG2RAD) - sin(degree * DEG2RAD));

		position[i] = Screen_Convert(origin[i]);
	}
	*/

	//system("cls");
}



Vector3D RectTransform::Viewport_Convert(Vector3D position)
{
	position.x -= 25;
	position.y -= 25;
	position.y *= -1;

	//printf("Viewport Convert\n");
	//printf("x: %d y: %d\n", (int)position.x, (int)position.y);

	return position;
}

Vector3D RectTransform::Screen_Convert(Vector3D position)
{
	position.x += 25;
	position.y *= -1;
	position.y += 25;

	//printf("Screen Convert\n");
	//printf("x: %d y: %d\n", (int)position.x, (int)position.y);

	return position;
}

void RectTransform::Translate(float px, float py, float pz)
{
	for (int i = 0; i < 4; i++)
	{
		position[i].x += px;
		position[i].y += py;
		position[i].z += pz;
	}
}

void RectTransform::Scale()
{

}