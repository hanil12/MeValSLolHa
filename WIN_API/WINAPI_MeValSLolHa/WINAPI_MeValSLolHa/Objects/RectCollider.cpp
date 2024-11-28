#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2D center, Vector2D size)
: _center(center)
, _halfSize(size * 0.5f)
{
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}
