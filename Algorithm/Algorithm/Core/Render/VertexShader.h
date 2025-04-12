#pragma once
class VertexShader : public Shader
{
public:
	VertexShader(wstring file);
	~VertexShader();

	void IASetInputLayout();

	void VSSet();

private:
	void CreateBlob(wstring file) override;
	void CreateInputLayOut();
	void CreateVertexShader();

	Microsoft::WRL::ComPtr<ID3D11InputLayout> _inputLayOut;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> _vertexShader;
	Microsoft::WRL::ComPtr<ID3D11ShaderReflection> _reflection;

};

