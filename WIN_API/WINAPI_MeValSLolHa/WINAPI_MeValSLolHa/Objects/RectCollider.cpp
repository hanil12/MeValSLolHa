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

bool RectCollider::IsCollision(const Vector2D& pos)
{
	if (pos.x > Right()) return false;
	if (pos.x < Left()) return false;
	if (pos.y > Bottom()) return false;
	if (pos.y < Top()) return false;

	return true;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	//if (Right() < other->Left()) return false;
	//if (Left() > other->Right()) return false;
	//

	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	return false;
}
