#pragma once
class Collider
{
public:
	enum Color
	{
		C_GREEN = 0,
		C_RED = 1
	};

	Collider();
	virtual ~Collider();

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	Vector2D	 center;

protected:

	Color _curColor = Color::C_GREEN;
	vector<HPEN> _pens;
};

