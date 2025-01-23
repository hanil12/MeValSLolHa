#pragma once
class MatrixBuffer;

class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void SetVS(int slot);

	void SetPos(Vector pos) { _pos = pos; }
	void SetScale(Vector scale) { _scale = scale; }
	void SetAngle(float angle) { _angle = angle; }

	Vector GetPos() { return _pos; }
	Vector GetScale() { return _scale; }
	float GetAngle() { return _angle; }

	void AddPos(Vector pos) { _pos = _pos + pos; }
	void AddAngle(float value) { _angle += value; }

private:
	// Quad : ���
	// => vertices => ����
	// �����(Local Space) => ��Ʈ��(World Space)
	// �������� �ʰ� ��Ʈ������ ���� �� �� ����.
	// => Transform�� Component�� ���� ���� ������ World�� ������ �� ����.

	// world���
	Vector _pos;
	Vector _scale = { 1,1 };
	float _angle = 0.0f; // Z�� ȸ��

	shared_ptr<MatrixBuffer> _world;
};

