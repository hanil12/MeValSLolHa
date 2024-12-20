#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_circleCollider = make_shared<CircleCollider>(Vector2D(), 10);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if (_isActive == false) return;

	//if(½Ã°£ÀÌ Áö³µ´Ù)
	//	SetActive(false)

	//if(¹Ù´Ú¿¡ ºÎ‹HÇû´Ù)
	//	SetActive(false)

	_circleCollider->center += _dir * _speed;
	_circleCollider->center.y += _fallingSpeed;

	_fallingSpeed += _G;
	
	_circleCollider->Update();
}

void Ball::Render(HDC hdc)
{
	if (_isActive == false) return;

	_circleCollider->Render(hdc);
}
