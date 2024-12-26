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

#pragma region ȭ������� ������ isActive false
	// ȭ������� ������ isActive false
	//if (_circleCollider->center.y > WIN_HEIGHT || _circleCollider->center.x > WIN_WIDTH
	//	|| _circleCollider->center.y < 0 || _circleCollider->center.x < 0)
	//{
	//	_isActive = false;
	//}
#pragma endregion

#pragma region �߷�
	//_circleCollider->center.y += _fallingSpeed;
	//_fallingSpeed += _G;
#pragma endregion

	Vector2D center = _circleCollider->center;
	if (center.x > WIN_WIDTH || center.x < 0)
	{
		_dir.x *= -1;
	}

	if (center.y > WIN_HEIGHT || center.y < 0)
	{
		_dir.y *= -1;
	}
	
	_circleCollider->center += _dir * _speed;
	_circleCollider->Update();
}

void Ball::Render(HDC hdc)
{
	if (_isActive == false) return;

	_circleCollider->Render(hdc);
}
