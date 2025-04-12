#include "framework.h"
#include "Block.h"

Block::Block()
{
	_quad = make_shared<Quad>(Vector(7, 7));
	_colorBuffer = make_shared<ColorBuffer>();

	_vs = ADD_VS(L"Shader/BlockVS.hlsl");
	_ps = ADD_PS(L"Shader/BlockPS.hlsl");

	_quad->SetPS(_ps);
	_quad->SetVS(_vs);
}

Block::~Block()
{
}

void Block::Update()
{
	_quad->Update();
}

void Block::Render()
{
	_colorBuffer->SetPS(0);
	_quad->Render();
}

void Block::SetType(BlockType type)
{
	_type = type;

	switch (type)
	{
	case Block::NONE:
		_colorBuffer->SetData({ 1,1,1,1 });
		break;
	case Block::ABLE:
		_colorBuffer->SetData({ 0,1,0,1 });
		break;
	case Block::DISABLE:
		_colorBuffer->SetData({ 1,0,0,1 });
		break;
	case Block::PLAYER:
		_colorBuffer->SetData({ 0,0,1,1 });
		break;
	case Block::FOOTPRINT:
		_colorBuffer->SetData({ 1,1,0,1 });
		break;
	default:
		break;
	}

	_colorBuffer->Update();
}
