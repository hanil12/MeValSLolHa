#pragma once
class Ball;

// 상속 기반 클래스 : 디자인패턴
class Cannon // : public RectCollider
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void RotateBarrel();
	void Fire(bool& turn);

	void SetPos(Vector2D pos) { _body->center = pos; }
	void AddPos(Vector2D vec) { _body->center += vec;  }

	vector<shared_ptr<Ball>> GetBalls() { return _balls; }

	bool IsCollision_Ball(shared_ptr<Ball> ball);
	void TakeDamage(int amount);

	bool isActive;

private:
	shared_ptr<RectCollider> _body; // 컴포넌트 패턴 ... 유니티
	float _speed = 5.f;
	float _angle = 0.0f;

	float _timer = 0.0f;
	float _delay = 2.0f;

	shared_ptr<class Barrel> _barrel;

	int _ballPoolCount = 30;
	vector<shared_ptr<class Ball>> _balls;

	int _hp = 5;
};

