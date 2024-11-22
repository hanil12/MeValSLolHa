#pragma once


class CircleCollider
{
public:
	CircleCollider(Vector2D center, float radius);

	void Update();
	void Render(HDC hdc);

private:
	Vector2D	 _center;
	float		 _radius;
};

