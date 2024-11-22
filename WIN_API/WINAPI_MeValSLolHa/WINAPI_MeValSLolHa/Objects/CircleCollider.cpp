#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector2D center, float radius)
: _center(center), _radius(radius)
{
}

void CircleCollider::Update()
{
	//_center = mousePos;

	// ���콺�����͸� ���ؼ� ��ӿ�ϴ� ���
	//Vector2D direction = (mousePos - _center);
	//if (direction.Length() < 10) return;
	//direction = direction.NormalVector();
	//_center = _center + direction * 10;

	// ������ �̿��ؼ� �ε巴�� �����̴� ���
	// Linear Interporation
	_center = (mousePos - _center) * 0.5f + _center;
}

void CircleCollider::Render(HDC hdc)
{
	int left = _center.x - _radius;
	int right = _center.x + _radius;
	int top = _center.y - _radius;
	int bottom = _center.y + _radius;
	Ellipse(hdc, left, top, right, bottom);
}
