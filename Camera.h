#pragma once
#include "DEF.h"
class Camera
{
	XMVECTOR Eye;
	XMVECTOR At;
	XMVECTOR Up;
public:
	Camera();
	Camera(XMVECTOR _Eye, XMVECTOR _At, XMVECTOR _Up);
	void Move(XMVECTOR _Eye, XMVECTOR _At, XMVECTOR _Up);
	XMVECTOR getEye() { return Eye; }
	XMVECTOR getAt() { return At; }
	XMVECTOR getUp() { return Up; }
};

