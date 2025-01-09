#include "framework.h"
#include "Objects/GameObjects/Arkanoid/ArkanoidBall.h"
#include "Bar.h"


Bar::Bar()
: _speed(10.0f)
{
	_rect = make_shared<RectCollider>(Vector2D(WIN_WIDTH * 0.5f, 600.0f), Vector2D(120, 20));
}

Bar::~Bar()
{
}

void Bar::Update()
{
	MoveInput();

	_rect->Update();
}

void Bar::Render(HDC hdc)
{
	_rect->Render(hdc);
}

void Bar::MoveInput()
{
	if (GetKeyState('A') & 0x8000)
	{
		_rect->center += Vector2D(-1, 0) * _speed;
	}

	if (GetKeyState('D') & 0x8000)
	{
		_rect->center += Vector2D(1, 0) * _speed;
	}
}

void Bar::Fire(shared_ptr<class ArkanoidBall> ball)
{
	if (ball == nullptr) return;
	if (ball->IsFired()) return;

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		ball->SetFired(true);
		ball->SetDir(Vector2D(0, -1));
	}
}
