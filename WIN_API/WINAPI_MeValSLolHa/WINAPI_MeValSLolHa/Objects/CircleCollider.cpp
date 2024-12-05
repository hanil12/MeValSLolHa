#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector2D center, float radius)
: _radius(radius)
{
	this->center = center;
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curColor]);

	int left = center.x - _radius;
	int right = center.x + _radius;
	int top = center.y - _radius;
	int bottom = center.y + _radius;
	Ellipse(hdc, left, top, right, bottom);
}
