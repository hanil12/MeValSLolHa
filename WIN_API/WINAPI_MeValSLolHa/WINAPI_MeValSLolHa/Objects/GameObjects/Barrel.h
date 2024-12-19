#pragma once
class Barrel
{
public:
	Barrel(float length);
	~Barrel();

	void Update();
	void Render(HDC hdc);

	void UpdateBody(Vector2D bodyCenter) { _line->_start = bodyCenter; }
	void SetDir(Vector2D dir) { _dir = dir; }

private:
	shared_ptr<Line> _line;
	float _barrelLength = 150;

	Vector2D _dir = Vector2D(1,0);
};

