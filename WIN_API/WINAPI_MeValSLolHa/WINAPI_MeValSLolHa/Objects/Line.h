#pragma once
class Line
{
public:
	struct HitResult
	{
		bool isCollision = false;
		Vector2D point;
	};

	enum Color
	{
		C_GREEN = 0,
		C_RED = 1
	};

	Line(Vector2D start, Vector2D end);
	~Line();

	void Update();
	void Render(HDC hdc);

	void SetRed() { _curColor = Color::C_RED; }
	void SetGreen() { _curColor = Color::C_GREEN; }

	HitResult IsCollision(shared_ptr<Line> other);

public:
	Vector2D _start;
	Vector2D _end;

	vector<HPEN> _pens;
	Color _curColor;
};

