#include "framework.h"
#include "Objects/GameObjects/Arkanoid/Bar.h"
#include "Objects/GameObjects/Arkanoid/Block.h"
#include "ArkanoidBall.h"

ArkanoidBall::ArkanoidBall(shared_ptr<Bar> bar)
: _bar(bar)
{
	_speed = 7.0f;
}

ArkanoidBall::~ArkanoidBall()
{
}

void ArkanoidBall::Update()
{
	if (_bar.expired() == true)
		return;

	shared_ptr<Bar> bar = _bar.lock();

	if (_isFired == false)
	{
		BeforeFireUpdate();
		return;
	}

	// 발사됬다는 가정
	MapReflection();
	IsCollisionBar();

	_circleCollider->center += _dir * _speed;
	_circleCollider->Update();
}

void ArkanoidBall::Render(HDC hdc)
{
	if (_bar.expired() == true)
		return;

	_circleCollider->Render(hdc);
}

void ArkanoidBall::IsCollsion(shared_ptr<Block> block)
{
	if (block == nullptr) return;

	shared_ptr<RectCollider> col = block->GetCollider();

	if (_circleCollider->IsCollision(block->GetCollider()))
	{
		if (_circleCollider->center.y < col->Top() || _circleCollider->center.y > col->Bottom())
			_dir.y *= -1.0f;
		else if (_circleCollider->center.x < col->Left() || _circleCollider->center.x > col->Right())
			_dir.x *= -1.0f;

		block->isActive = false;
	}
}

void ArkanoidBall::IsCollisionBar()
{
	if (_bar.expired()) return;

	shared_ptr<Bar> bar = _bar.lock();

	if (_circleCollider->IsCollision(bar->GetCollider()))
	{
		Vector2D dir = _circleCollider->center - bar->GetCenter();
		dir.Normalize();
		SetDir(dir);
	}
}

void ArkanoidBall::BeforeFireUpdate()
{
	shared_ptr<Bar> bar = _bar.lock();

	if (_isFired == false)
	{
		_circleCollider->center = bar->GetCenter();
		_circleCollider->center.y -= 20;
	}

	_circleCollider->Update();
}

void ArkanoidBall::MapReflection()
{
	Vector2D center = _circleCollider->center;
	if (center.x > WIN_WIDTH || center.x < 0)
	{
		_dir.x *= -1;
	}

	if (center.y < 0)
	{
		_dir.y *= -1;
	}
}
