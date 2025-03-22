#pragma once
// Buffer : 임시저장공간 => 잠깐 갖고있다가 다른 누군가에게 전달할 목적
class VertexBuffer
{
public:
	VertexBuffer(void* data, UINT stride, UINT count ,UINT offset = 0);
	~VertexBuffer();

	void IASet(int slot);

private:
	void CreateVertexBuffer();

	Microsoft::WRL::ComPtr<ID3D11Buffer> _vertexBuffer;

	void*		_data;
	UINT		_count;
	UINT		_stride;
	UINT		_offset;
};

