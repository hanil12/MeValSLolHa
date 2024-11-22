#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector2D center, float radius)
: _center(center), _radius(radius)
{
}

void CircleCollider::Update()
{
	_center.x += 1;
}

void CircleCollider::Render(HDC hdc)
{
	int left = _center.x - _radius;
	int right = _center.x + _radius;
	int top = _center.y - _radius;
	int bottom = _center.y + _radius;
	Ellipse(hdc, left, top, right, bottom);
}
