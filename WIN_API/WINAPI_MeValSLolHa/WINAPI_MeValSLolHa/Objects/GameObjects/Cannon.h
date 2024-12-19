#pragma once

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
	void Fire();

	void SetPos(Vector2D pos) { _body->center = pos; }

	void AddPos(Vector2D vec) { _body->center += vec;  }

private:
	shared_ptr<RectCollider> _body; // 컴포넌트 패턴 ... 유니티
	float _speed = 5.f;
	float _angle = 0.0f;

	shared_ptr<class Barrel> _barrel;
};

