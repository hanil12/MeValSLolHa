#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_movingCircle = make_shared<CircleCollider>(Vector2D(0, 0), 50);
	_rect = make_shared<RectCollider>(Vector2D(250, 250), Vector2D(100, 60));
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_movingCircle->center = mousePos;

	_movingCircle->Update();
	_rect->Update();
}

void CollisionScene::Render(HDC hdc)
{
	_movingCircle->Render(hdc);
	_rect->Render(hdc);
}
