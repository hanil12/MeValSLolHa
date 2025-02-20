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
	void SetLeftRight(int value) { _leftRightBuffer->SetData(value); _leftRightBuffer->Update(); }
	void AddColor(XMFLOAT4 color) { _colorBuffer->SetData(color); _colorBuffer->Update(); }

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
	shared_ptr<LeftRightBuffer> _leftRightBuffer;
	shared_ptr<ColorBuffer> _colorBuffer;
};

