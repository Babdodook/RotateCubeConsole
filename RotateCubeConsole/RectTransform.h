#pragma once
#pragma once
#include"Vector3D.h"
#include"basics.h"

class RectTransform {
public:
	RectTransform();
	~RectTransform();

	void DrawRect();

	void GetKey();

	void Rotate();
	Vector3D Viewport_Convert(Vector3D position);
	Vector3D Screen_Convert(Vector3D position);

	Vector3D position[4];
	int ScreenArray[50][50];
};