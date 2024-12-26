#include "framework.h"

#include "Objects/GameObjects/Cannon.h"

#include "CannonScene.h"

CannonScene::CannonScene()
{
	_cannon = make_shared<Cannon>();
	_cannon->SetPos(Vector2D(300, 500));

	_cannon2 = make_shared<Cannon>();
	_cannon2->SetPos(Vector2D(600, 500));

	_cannon->Update();
	_cannon->RotateBarrel();
	_cannon->Move();
	_cannon2->Update();
	_cannon2->RotateBarrel();
	_cannon2->Move();
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	if (_turn)
	{
		_cannon->Fire(_turn);
		_cannon->Move();
		_cannon->RotateBarrel();
	}
	else
	{
		_cannon2->Fire(_turn);
		_cannon2->Move();
		_cannon2->RotateBarrel();
	}

	_cannon->Update();
	_cannon2->Update();

	// cannon狼 balls客 cannon2狼 面倒贸府
	for (auto ball : _cannon->GetBalls())
	{
		_cannon2->IsCollision_Ball(ball);
	}
}

void CannonScene::Render(HDC hdc)
{
	_cannon->Render(hdc);
	_cannon2->Render(hdc);
}
