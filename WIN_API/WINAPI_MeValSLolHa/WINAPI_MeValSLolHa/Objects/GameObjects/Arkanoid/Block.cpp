#include "framework.h"
#include "Block.h"

Block::Block(Vector2D halfSize)
{
	_rect = make_shared<RectCollider>(Vector2D(), halfSize * 2.0f);
}

Block::~Block()
{
}

void Block::Update()
{
	if (!isActive) return;

	_rect->Update();
}

void Block::Render(HDC hdc)
{
	if (!isActive) return;

	_rect->Render(hdc);
}
