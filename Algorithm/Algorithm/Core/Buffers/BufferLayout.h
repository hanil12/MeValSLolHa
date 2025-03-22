#pragma once
// BufferLayout

class MatrixBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMMATRIX matrix = XMMatrixIdentity();
	};

	MatrixBuffer() : ConstantBuffer(&_data, sizeof(Data)) {}
	~MatrixBuffer() {}

	void SetData(XMMATRIX value)
	{
		// DirectX는 행렬계산 때문에
		_data.matrix = XMMatrixTranspose(value);
	}

private:
	Data _data;
};

class ColorBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT4 color;
	};

	ColorBuffer() : ConstantBuffer(&_data, sizeof(Data)) {}
	~ColorBuffer() {}

	void SetData(XMFLOAT4 color)
	{
		_data.color = color;
	}

private:
	Data _data;
};

class LeftRightBuffer : public ConstantBuffer
{
public:
	// 상수버퍼로 넘길 때는 16바이트 배수
	struct Data
	{
		int leftRight = 0;
		int padding[3];
	};

	LeftRightBuffer() : ConstantBuffer(&_data, sizeof(Data)) {}
	~LeftRightBuffer() {}

	void SetData(int leftRight)
	{
		_data.leftRight = leftRight;
	}

private:
	Data _data;
};