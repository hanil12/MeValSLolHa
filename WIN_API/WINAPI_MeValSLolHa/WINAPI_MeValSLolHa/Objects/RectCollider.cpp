#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2D center, Vector2D size)
: _halfSize(size * 0.5f)
{
	this->center = center;
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curColor]);

	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}
