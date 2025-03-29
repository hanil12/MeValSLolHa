#include "framework.h"
#include "Block.h"

Block::Block()
{
	_quad = make_shared<Quad>(Vector(7, 7));
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
	_quad->Render();
}
