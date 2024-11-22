#pragma once
class RectCollider
{
public:
	RectCollider(Vector2D center, Vector2D size);
	~RectCollider();

	int Left() { return _center.x - _halfSize.x; }
	int Right() { return _center.x + _halfSize.x; }
	int Top() { return _center.y - _halfSize.y; }
	int Bottom() { return _center.y + _halfSize.y; }

	void Update();
	void Render(HDC hdc);

private:
	Vector2D	 _center;
	Vector2D	 _halfSize;

	float		_angle;
};

