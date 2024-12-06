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

	virtual bool IsCollision(const Vector2D& pos) override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) override;

private:
	Vector2D	 _halfSize;
};

