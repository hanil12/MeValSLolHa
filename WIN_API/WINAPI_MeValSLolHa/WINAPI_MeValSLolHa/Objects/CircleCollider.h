#pragma once


class CircleCollider : public Collider
{
public:
	CircleCollider(Vector2D center, float radius);

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	bool IsCollision(const Vector2D& pos);
	bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(shared_ptr<class RectCollider> other);

private:
	float		 _radius;
};

