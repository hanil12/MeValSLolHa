#pragma once
class SamplerState
{
public:
	SamplerState();
	~SamplerState();

	void PSSet_Sampler(int slot);
private:
	void CreateSamplerState();

	// 3. SamplerState(판박이를 붙히는 아저씨)
	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState;
};

