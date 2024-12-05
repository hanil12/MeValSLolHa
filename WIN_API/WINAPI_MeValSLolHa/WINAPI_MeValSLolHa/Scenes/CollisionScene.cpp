#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_movingCircle = make_shared<CircleCollider>(Vector2D(0, 0), 50);
	_circle = make_shared<CircleCollider>(Vector2D(600, 600), 70);
	_rect = make_shared<RectCollider>(Vector2D(250, 250), Vector2D(100, 60));
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	//_movingCircle->center = mousePos;
	if (_circle->IsCollision(mousePos))
		_circle->SetRed();
	else
		_circle->SetGreen();

	_movingCircle->Update();
	_rect->Update();
	_circle->Update();
}

void CollisionScene::Render(HDC hdc)
{
	_movingCircle->Render(hdc);
	_rect->Render(hdc);
	_circle->Render(hdc);
}
