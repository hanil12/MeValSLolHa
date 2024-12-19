#pragma once

// ��� ��� Ŭ���� : ����������
class Cannon // : public RectCollider
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();

	void SetPos(Vector2D pos) { _body->center = pos; }
	void AddPos(Vector2D vec) { _body->center += vec;  }

private:
	shared_ptr<RectCollider> _body; // ������Ʈ ���� ... ����Ƽ
	shared_ptr<Line> _barrel;

	float _speed = 5.f;
};

