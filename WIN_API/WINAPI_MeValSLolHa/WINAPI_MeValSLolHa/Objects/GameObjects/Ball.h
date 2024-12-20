#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector2D pos) { _circleCollider->center = pos; }
	void SetDir(Vector2D dir) { dir.Normalize(); _dir = dir; }
	void SetSpeed(float speed) { _speed = speed; }

private:
	shared_ptr<CircleCollider> _circleCollider;
	Vector2D _dir = Vector2D(1,0);
	float _speed = 2.0f;
};

