#pragma once
class Block
{
public:
	Block(Vector2D halfSize);
	~Block();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector2D pos) { _rect->center = pos; }

private:
	shared_ptr<RectCollider> _rect;
};

