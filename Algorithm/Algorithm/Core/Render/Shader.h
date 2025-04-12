#pragma once
class Shader
{
public:
	Shader(wstring file);

protected:
	virtual void CreateBlob(wstring file) abstract;

	Microsoft::WRL::ComPtr<ID3DBlob> _blob;
};

