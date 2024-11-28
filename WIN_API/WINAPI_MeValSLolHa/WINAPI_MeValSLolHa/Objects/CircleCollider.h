#pragma once


class CircleCollider : public Collider
{
public:
	CircleCollider(Vector2D center, float radius);

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	float		 _radius;
};

