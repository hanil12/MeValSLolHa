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
	Vector2D GetDir() { return _dir; }
	Vector2D GetMuzzle() { return _line->_end; }
	float BarrelLength() { return _barrelLength; }

private:
	shared_ptr<Line> _line;
	float _barrelLength = 150;

	Vector2D _dir = Vector2D(1,0);
};

