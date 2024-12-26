#include "framework.h"
#include "Cannon.h"

#include "Barrel.h"
#include "Ball.h"

Cannon::Cannon()
{
	// 60 , 35
	_body = make_shared<RectCollider>(Vector2D(), Vector2D(120, 70));
	_barrel = make_shared<Barrel>(150);

	// Object Pooling
	for (int i = 0; i < _ballPoolCount; i++)
	{
		auto ball = make_shared<Ball>();
		_balls.push_back(ball);
	}
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	if (isActive == false) return;

	_body->Update();
	_barrel->Update();

	for (auto ball : _balls)
	{
		ball->Update();
	}
}

void Cannon::Render(HDC hdc)
{
	if (isActive == false) return;

	_barrel->Render(hdc);
	_body->Render(hdc);

	for (auto ball : _balls)
	{
		ball->Render(hdc);
	}
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

	_barrel->UpdateBody(_body->center);
}

void Cannon::RotateBarrel()
{
	if (GetAsyncKeyState('W') & 0x8001)
	{
		_angle += 0.07f;
	}

	if (GetAsyncKeyState('S') & 0x8001)
	{
		_angle -= 0.07f;
	}

	_barrel->SetDir(Vector2D(cosf(_angle), -sinf(_angle)));
}

void Cannon::Fire(bool& turn)
{
	_timer += 0.05f;

	if (_timer < _delay) return;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		auto iter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<Ball> ball) -> bool
			{
				if (ball->IsActive() == false)
					return true;
				return false;
			});

		if (iter == _balls.end()) return;

		_timer = 0.0f;
		auto ball = (*iter);

		ball->SetPos(_barrel->GetMuzzle());
		ball->SetDir(_barrel->GetDir());
		ball->SetSpeed(25.0f);
		ball->SetActive(true);
		turn = !turn;
	}
}

bool Cannon::IsCollision_Ball(shared_ptr<Ball> ball)
{
	if (ball->IsActive() == false)
		return false;

	if (isActive == false)
		return false;

	if (_body->Collider::IsCollision(ball->GetCollider()))
	{
		// TODO : 공의 데미지..?
		TakeDamage(1);
		ball->SetActive(false);

		return true;
	}

	return false;
}

void Cannon::TakeDamage(int amount)
{
	_hp -= amount;

	if (_hp <= 0)
	{
		isActive = false;
		_hp = 0;
	}
}
