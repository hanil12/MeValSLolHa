#pragma once

class Quad
{
public:
	Quad();
	Quad(Vector halfSize);
	~Quad();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _transform; }

	void SetVS(shared_ptr<VertexShader> vs) { _vs = vs; }
	void SetPS(shared_ptr<PixelShader> ps) { _ps = ps; }

private:
	void CreateVertices();
	void CreateVertices(Vector halfSize);

	vector<Vertex_Color> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<Transform> _transform; // world
};

