#include "framework.h"
#include "PixelShader.h"

PixelShader::PixelShader(wstring file)
: Shader(file)
{
	CreateBlob(file);
	CreatePixelShader();
}

PixelShader::~PixelShader()
{
}

void PixelShader::PSSet()
{
	DC->PSSetShader(pixelShader.Get(), nullptr, 0);
}

void PixelShader::CreateBlob(wstring file)
{
	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	D3DCompileFromFile(file.c_str(), nullptr, nullptr, "PS", "ps_5_0", flags, 0, pixelBlob.GetAddressOf(), nullptr);
}

void PixelShader::CreatePixelShader()
{
	DEVICE->CreatePixelShader(pixelBlob->GetBufferPointer(), pixelBlob->GetBufferSize(), nullptr, IN pixelShader.GetAddressOf());
}
