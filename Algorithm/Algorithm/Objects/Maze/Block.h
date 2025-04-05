#pragma once
class Block
{
public:
	enum BlockType
	{
		NONE,
		ABLE,
		DISABLE,
		PLAYER,
		FOOTPRINT
	};

	Block();
	~Block();

	void Update();
	void Render();

	void SetPos(Vector pos) { _quad->GetTransform()->SetPos(pos); }
	void SetType(BlockType type);
	BlockType GetType() { return _type; }

private:
	BlockType _type;

	shared_ptr<Quad> _quad;
	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;
};

