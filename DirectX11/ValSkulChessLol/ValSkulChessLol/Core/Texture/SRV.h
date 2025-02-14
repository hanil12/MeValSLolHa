#pragma once
class SRV
{
public:
	SRV(wstring path);
	~SRV();

	void PSSet_SRV(int slot);

	Vector GetImageSize();

private:
	void CreateSRV(wstring path);

	ScratchImage image;

	// TextureMapping
	// 1. Texture(source, 포켓몬) => SIUUUU
	// 2. ShaderResourceView(판박이를 만드는 아저씨)
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> srv;
};

