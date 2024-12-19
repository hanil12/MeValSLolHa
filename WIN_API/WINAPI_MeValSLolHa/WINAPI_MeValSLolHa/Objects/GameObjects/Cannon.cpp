#include "framework.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<RectCollider>(Vector2D(), Vector2D(120, 70));
	_barrel = make_shared<Line>(Vector2D(), Vector2D());
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	Move();

	_body->Update();
	_barrel->Update();
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
}

void Cannon::Move()
{
	if (GetAsyncKeyState('A') & 0x8001)
	{
		Vector2D left = Vector2D(-1, 0);
		AddPos(left * _speed);
	}

	if (GetAsyncKeyState('D') & 0x8001)
	{
		Vector2D right = Vector2D(1, 0);
		AddPos(right * _speed);
	}
}
