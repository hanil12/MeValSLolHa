#pragma once
class RectCollider
{
public:
	RectCollider(Vector center, Vector size);
	~RectCollider();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _transform; }

private:
	Vector _halfSize;
	Vector _center;

	void CreateMesh();
	void CreateMaterial();

	vector<Vertex>		   _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<Transform> _transform;
	shared_ptr<ColorBuffer> _colorBuffer; // 상수버퍼
};

