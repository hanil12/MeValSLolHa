#pragma once
class Collider
{
public:
	enum Color
	{
		C_GREEN = 0,
		C_RED = 1
	};

	enum Type
	{
		NONE,
		CIRCLE,
		RECT
	};

	Collider();
	virtual ~Collider();

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	void SetRed() { _curColor = Color::C_RED; }
	void SetGreen() { _curColor = Color::C_GREEN; }

	bool IsCollision(shared_ptr<Collider> other);

	virtual bool IsCollision(const Vector2D& pos) abstract;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) abstract;
	virtual bool IsCollision(shared_ptr<class RectCollider> other) abstract;

	Vector2D	 center;

protected:
	Type _type = NONE;

	Color _curColor = Color::C_GREEN;
	vector<HPEN> _pens;
};

