#pragma once

class Quad
{
public:
	Quad(wstring textureFile);
	~Quad();

	void Update();
	void Render();

	void CreateMaterial(wstring textureFile);
	void CreateMesh();

	shared_ptr<Transform> GetTransform() { return _transform; }
	Vector GetImageSize() { return _srv->GetImageSize(); }

private:
	// mesh
	vector<Vertex_Texture> _vertices;
	vector<UINT>		   _indices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer>	 _indexBuffer;

	// material : Shader
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	// material : Texture
	shared_ptr<SRV> _srv;

	shared_ptr<Transform> _transform;
};

