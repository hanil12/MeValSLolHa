#pragma once
class Ball
{
public:
	Ball();
	virtual ~Ball();

	virtual void Update();
	virtual void Render(HDC hdc);

	void SetPos(Vector2D pos) { _circleCollider->center = pos; }
	void SetDir(Vector2D dir) { dir.Normalize(); _dir = dir; }
	void SetSpeed(float speed) { _speed = speed; }

	void SetActive(bool value) { _fallingSpeed = 0.0f; _isActive = value; }
	bool IsActive() { return _isActive; }

	shared_ptr<Collider> GetCollider() { return _circleCollider; }

protected:
	shared_ptr<CircleCollider> _circleCollider;
	Vector2D _dir = Vector2D(1,0);
	float _speed = 2.0f;

	bool _isActive = false;
	float _fallingSpeed = 0.0f;
	const float _G = 0.7;
};

