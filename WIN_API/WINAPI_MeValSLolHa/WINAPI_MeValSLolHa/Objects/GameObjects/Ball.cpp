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
	_circleCollider->center += _dir * _speed;
	
	_circleCollider->Update();
}

void Ball::Render(HDC hdc)
{
	_circleCollider->Render(hdc);
}
