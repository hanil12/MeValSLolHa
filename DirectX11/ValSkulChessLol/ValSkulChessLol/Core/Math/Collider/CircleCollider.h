#pragma once
class CircleCollider : public enable_shared_from_this<CircleCollider>
{
public:
	CircleCollider(Vector center, float radius);
	~CircleCollider();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _transform; }

	Vector GetCenter() { return _transform->GetLocalPos(); }
	Vector GetWorldCenter() { return _transform->GetWorldPos(); }

	float GetWorldRadius() { return _radius * _transform->GetWorldScale().x; }

	void SetRed() { _colorBuffer->SetData(XMFLOAT4(1, 0, 0, 1)); }
	void SetGreen() { _colorBuffer->SetData(XMFLOAT4(0, 1, 0, 1)); }

	bool IsCollision(Vector pos);
	bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(shared_ptr<class RectCollider> other);

private:
	float _radius;

	void CreateMesh();
	void CreateMaterial();

	vector<Vertex>		   _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<Transform> _transform;
	shared_ptr<ColorBuffer> _colorBuffer; // 상수버퍼
};

