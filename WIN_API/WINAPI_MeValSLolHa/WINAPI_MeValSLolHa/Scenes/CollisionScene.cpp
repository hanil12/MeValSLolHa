#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_movingCircle = make_shared<CircleCollider>(Vector2D(0, 0), 50);
	_circle = make_shared<CircleCollider>(Vector2D(600, 400), 70);

	_rect = make_shared<RectCollider>(Vector2D(250, 250), Vector2D(100, 60));
	_movingRect = make_shared<RectCollider>(Vector2D(700, 250), Vector2D(100, 150));
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_movingRect->center = mousePos;
	if (_movingRect->IsCollision(_circle))
		_movingRect->SetRed();
	else
		_movingRect->SetGreen();


	_movingCircle->Update();
	_rect->Update();
	_circle->Update();
	_movingRect->Update();
}

void CollisionScene::Render(HDC hdc)
{
	_movingCircle->Render(hdc);
	_rect->Render(hdc);
	_circle->Render(hdc);
	_movingRect->Render(hdc);
}
