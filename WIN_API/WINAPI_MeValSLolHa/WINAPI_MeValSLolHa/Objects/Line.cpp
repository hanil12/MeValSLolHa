#include "framework.h"
#include "Line.h"

Line::Line(Vector2D start, Vector2D end)
: _start(start)
, _end(end)
{
	_pens.push_back(CreatePen(3, 3, GREEN));
	_pens.push_back(CreatePen(3, 3, RED));

	SetGreen();
}

Line::~Line()
{
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curColor]);
	MoveToEx(hdc, _start.x, _start.y, nullptr);
	LineTo(hdc, _end.x, _end.y);
}

Line::HitResult Line::IsCollision(shared_ptr<Line> other)
{
	// 삼각형넓이 a,b
	float a, b = 0.0f;

	// 위치벡터, 방향벡터, 단위벡터, 기저벡터

	// Line1 기준에서 Line2의 양쪽끝으로 향하는 벡터 사이에 있는지
	bool isBetween1 = false;
	{
		Vector2D line1V = _end - _start;
		Vector2D line1_2Start = other->_start - _start;
		Vector2D line1_2End = other->_end - _start;

		float cross1 = line1V.Cross(line1_2Start);
		a = abs(cross1);
		float cross2 = line1V.Cross(line1_2End);
		b = abs(cross2);
		// 만약에 사이에 없다면... cross1과 cross2가 부호가 같다.
		// 사이에 있으면 부호가 다르기 때문에 곱했을 때 0보다 작다.
		isBetween1 = (cross1 * cross2) < 0;
	}

	bool isBetween2 = false;
	{
		Vector2D line2V = other->_end - other->_start;
		Vector2D line2_1Start = _start - other->_start;
		Vector2D line2_1End = _end - other->_start;

		float cross1 = line2V.Cross(line2_1Start);
		float cross2 = line2V.Cross(line2_1End);

		isBetween2 = (cross1 * cross2) < 0;
	}

	Vector2D dir = (other->_end - other->_start).NormalVector();
	float ratio = a / (a + b);
	Vector2D point = LERP(other->_start, other->_end, ratio);
	
	HitResult result;
	result.isCollision = isBetween1 && isBetween2;
	result.point = point;

	return result;
}
