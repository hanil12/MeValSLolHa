#include "framework.h"
#include "Map.h"

#include "Objects/GameObjects/Arkanoid/Bar.h"
#include "Objects/GameObjects/Arkanoid/Block.h"
#include "Objects/GameObjects/Arkanoid/ArkanoidBall.h"

Map::Map()
{
	_bar = make_shared<Bar>();
	_ball = make_shared<ArkanoidBall>(_bar);

	Vector2D blockHalf = { 50.0f,20.0f };
	Vector2D gap(blockHalf.x * 2 + 3, blockHalf.y * 2 + 1);
	Vector2D offset = Vector2D(250, 150);

	for (int y = 0; y < _blockCount_Y; y++)
	{
		for (int x = 0; x < _blockCount_X; x++)
		{
			shared_ptr<Block> block = make_shared<Block>(blockHalf);

			float gapX = gap.x * x;
			float gapY = gap.y * y;

			Vector2D pos = Vector2D(gapX, gapY) + offset;
			block->SetPos(pos);
			_blocks.push_back(block);
		}
	}
}

Map::~Map()
{
}

void Map::Update()
{
	_bar->Update();
	_ball->Update();

	// 게임 로직
	_bar->Fire(_ball);

	for(auto block : _blocks)
	{
		if (!block->isActive)
			continue;

		_ball->IsCollsion(block);
	}

	for (auto block : _blocks)
		block->Update();
}

void Map::Render(HDC hdc)
{
	_bar->Render(hdc);
	_ball->Render(hdc);

	for (auto block : _blocks)
		block->Render(hdc);
}
