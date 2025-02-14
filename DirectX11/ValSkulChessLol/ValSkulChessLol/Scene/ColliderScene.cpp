#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_standRect = make_shared<RectCollider>(Vector(0,0), Vector(100, 100));
	_circle = make_shared<CircleCollider>(CENTER, 100);
	_movingCircle = make_shared<CircleCollider>(Vector(0, 0), 50);
	_movingRect = make_shared<RectCollider>(CENTER, Vector(120, 70));


	_circle->GetTransform()->SetParent(_standRect->GetTransform());
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_standRect->Update();
	_circle->Update();
	_movingCircle->Update();
	_movingRect->Update();

	Input();

	if (_circle->IsCollision(_movingRect))
	{
		_circle->SetRed();
	}
	else
	{
		_circle->SetGreen();
	}
}

void ColliderScene::Render()
{
	_standRect->Render();
	_movingRect->Render();
	_circle->Render();
	_movingCircle->Render();
}

void ColliderScene::Input()
{
	if (KEY_PRESS('W'))
	{
		_standRect->GetTransform()->AddScale(Vector(1, 1) * DELTA_TIME);
	}
	if (KEY_PRESS('S'))
	{
		_standRect->GetTransform()->AddScale(Vector(-1, -1) * DELTA_TIME);
	}

	if (KEY_PRESS('A'))
	{
		_standRect->GetTransform()->AddAngle(DELTA_TIME);
	}
	if (KEY_PRESS('D'))
	{
		_standRect->GetTransform()->AddAngle(-DELTA_TIME);
	}
	
	_movingCircle->GetTransform()->SetPos(mousePos);
	_movingRect->GetTransform()->SetPos(mousePos);
}
