#include "Camera.h"

Camera::Camera() : 
	Eye(XMVectorSet(0.0f, 3.0f, -6.0f, 0.0f)),
	At(XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f)),
	Up(XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f)){}

Camera::Camera(XMVECTOR _Eye, XMVECTOR _At, XMVECTOR _Up) :
	Eye(_Eye),
	At(_At),
	Up(_Up){}

void Camera::Move(XMVECTOR _Eye, XMVECTOR _At, XMVECTOR _Up) {
	Eye = _Eye;
	At = _At;
	Up = _Up;
}