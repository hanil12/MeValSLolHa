#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector2D center, float radius)
: _radius(radius)
{
	this->center = center;
	_type = Collider::CIRCLE;
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

bool CircleCollider::IsCollision(const Vector2D& pos)
{
	return (pos - center).Length() < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	return (other->center - center).Length() < _radius + other->_radius;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	return other->IsCollision(shared_from_this());
}
