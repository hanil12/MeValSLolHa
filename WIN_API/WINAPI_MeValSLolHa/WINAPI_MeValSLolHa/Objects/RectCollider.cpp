#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2D center, Vector2D size)
: _center(center)
, _halfSize(size * 0.5f)
{
	_angle = 0;
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
	_angle += 0.1f;

	_center.x = 500 + 130 * cos(_angle);
	_center.y = 500 + 130 * sin(-_angle);
}

void RectCollider::Render(HDC hdc)
{
	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}
