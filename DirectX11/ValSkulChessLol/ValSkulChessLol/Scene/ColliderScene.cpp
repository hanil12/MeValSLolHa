#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rect = make_shared<RectCollider>(Vector(0,0), Vector(100, 100));
	_circle = make_shared<CircleCollider>(CENTER, 100);
	_movingCircle = make_shared<CircleCollider>(Vector(0, 0), 50);


	_circle->GetTransform()->SetParent(_rect->GetTransform());
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_rect->Update();
	_circle->Update();
	_movingCircle->Update();

	Input();

	if (_circle->IsCollision(mousePos))
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
	_rect->Render();
	_circle->Render();
	_movingCircle->Render();
}

void ColliderScene::Input()
{
	if (KEY_PRESS('W'))
	{
		_rect->GetTransform()->AddScale(Vector(1, 1) * DELTA_TIME);
	}
	if (KEY_PRESS('S'))
	{
		_rect->GetTransform()->AddScale(Vector(-1, -1) * DELTA_TIME);
	}
	
	_movingCircle->GetTransform()->SetPos(mousePos);
}
