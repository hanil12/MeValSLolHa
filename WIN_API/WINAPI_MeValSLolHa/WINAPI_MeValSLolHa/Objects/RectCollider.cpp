#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2D center, Vector2D size)
: _halfSize(size * 0.5f)
{
	this->center = center;
	_type = Collider::RECT;
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
	if (Right() < other->Left()) return false;
	if (Left() > other->Right()) return false;
	if (Bottom() < other->Top()) return false;
	if (Top() > other->Bottom()) return false;

	return true;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	Vector2D circleCenter = other->center;
	float radius = other->Radius();
	float length = (circleCenter - center).Length();

	// 위 아래 충돌체크
	if (circleCenter.x < Right() && circleCenter.x > Left())
	{
		float result = 0.0f;
		if (circleCenter.y > center.y) // circle이 아래쪽에있다.
			result = circleCenter.y - center.y;
		else
			result = center.y - circleCenter.y;

		return result < radius + _halfSize.y;
	}

	// 좌우 충돌체크
	if (circleCenter.y < Bottom() && circleCenter.y > Top())
	{
		float result = 0.0f;
		if (circleCenter.x > center.x) // circle이 오른쪽에 있다.
			result = circleCenter.x - center.x;
		else
			result = center.x - circleCenter.x;

		return result < radius + _halfSize.x;
	}

	// 각 꼭지점 체크
	Vector2D leftTop = Vector2D(Left(), Top());
	Vector2D rightTop = Vector2D(Right(), Top());
	Vector2D leftBottom = Vector2D(Left(), Bottom());
	Vector2D rightBottom = Vector2D(Right(), Bottom());

	bool check1 = other->IsCollision(leftTop);
	bool check2 = other->IsCollision(rightTop);
	bool check3 = other->IsCollision(leftBottom);
	bool check4 = other->IsCollision(rightBottom);

	return check1 || check2 || check3 || check4;
}
