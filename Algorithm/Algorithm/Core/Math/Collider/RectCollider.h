#pragma once
class RectCollider
{
	struct OBB_DESC
	{
		Vector pos; // worldPos
		Vector halfSize;
		Vector direction[2];
	};

public:
	RectCollider(Vector center, Vector size);
	~RectCollider();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _transform; }
	Vector GetCenter() { return _transform->GetLocalPos(); }
	Vector GetWorldCenter() { return _transform->GetWorldPos(); }

	void SetRed() { _colorBuffer->SetData(XMFLOAT4(1, 0, 0, 1)); }
	void SetGreen() { _colorBuffer->SetData(XMFLOAT4(0, 1, 0, 1)); }

	OBB_DESC GetOBB();

	bool IsCollision(Vector pos);
	bool IsCollision(shared_ptr<RectCollider> other);
	bool IsCollision(shared_ptr<class CircleCollider> other);

private:
	Vector _halfSize;

	void CreateMesh();
	void CreateMaterial();

	vector<Vertex>		   _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<Transform> _transform;
	shared_ptr<ColorBuffer> _colorBuffer; // 상수버퍼
};

