#pragma once
class RectCollider : public Collider
{
public:
	RectCollider(Vector2D center, Vector2D size);
	~RectCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	int Left() { return center.x - _halfSize.x; }
	int Right() { return center.x + _halfSize.x; }
	int Top() { return center.y - _halfSize.y; }
	int Bottom() { return center.y + _halfSize.y; }

private:
	Vector2D	 _halfSize;
};
