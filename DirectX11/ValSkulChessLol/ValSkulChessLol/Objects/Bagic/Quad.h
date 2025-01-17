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

private:
	// mesh
	vector<Vertex_Texture> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	// material : Shader
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	// material : Texture
	shared_ptr<SRV> _srv;
	shared_ptr<SamplerState> _samplerState;
};

