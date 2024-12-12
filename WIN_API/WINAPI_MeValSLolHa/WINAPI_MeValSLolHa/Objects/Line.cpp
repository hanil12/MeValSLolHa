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
