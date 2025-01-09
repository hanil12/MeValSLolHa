#pragma once
class Bar
{
public:
	Bar();
	~Bar();

	void Update();
	void Render(HDC hdc);

	void MoveInput();
	void Fire(shared_ptr<class ArkanoidBall> ball);

	Vector2D GetCenter() { return _rect->center; }
	shared_ptr<RectCollider> GetCollider() { return _rect; }

private:
	shared_ptr<RectCollider> _rect;
	float _speed;
};

