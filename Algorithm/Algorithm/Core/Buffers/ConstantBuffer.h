#pragma once
class ConstantBuffer
{
public:
	ConstantBuffer(void* data, UINT dataSize);
	virtual ~ConstantBuffer();

	void Update();

	void SetVS(UINT slot);
	void SetPS(UINT slot);

private:
	// 임시저장공간 => 누군가 한테 보낼 용도 잠깐 저장하는 곳
	Microsoft::WRL::ComPtr<ID3D11Buffer> _buffer;

	void* _data;
	UINT _dataSize;
};

