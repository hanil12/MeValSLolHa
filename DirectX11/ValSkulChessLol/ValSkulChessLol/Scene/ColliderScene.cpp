#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rect = make_shared<RectCollider>(Vector(0,0), Vector(100, 100));
	_circle = make_shared<CircleCollider>(CENTER, 100);
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_rect->Update();
	_circle->Update();
}

void ColliderScene::Render()
{
	_rect->Render();
	_circle->Render();
}
