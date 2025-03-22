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

	Vector GetLocalPos() { return _pos; }
	Vector GetWorldPos(); // World상에 좌표
	Vector GetScale() { return _scale; }
	Vector GetWorldScale();
	float GetAngle() { return _angle; }

	void AddPos(Vector pos) { _pos = _pos + pos; }
	void AddScale(Vector scale) { _scale = _scale + scale; }
	void AddAngle(float value) { _angle += value; }

	void SetParent(shared_ptr<Transform> parent) { _parent = parent; }
	XMMATRIX GetMatrix() { return _srtMatrix;  }

private:
	// Quad : 배우
	// => vertices => 분장
	// 분장실(Local Space) => 세트장(World Space)
	// 분장하지 않고서 세트장으로 절대 올 수 없다.
	// => Transform을 Component로 갖고 있지 않으면 World에 등장할 수 없다.

	// world행렬
	Vector _pos;
	Vector _scale = { 1,1 };
	float _angle = 0.0f; // Z축 회전
	XMMATRIX _srtMatrix;

	shared_ptr<MatrixBuffer> _world;
	
	weak_ptr<Transform> _parent;
};

