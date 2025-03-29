#include "framework.h"
#include "TutorialScene.h"

#include "Objects/Maze/Block.h"

TutorialScene::TutorialScene()
{
	_blocks.resize(25);

	Vector offset = Vector(WIN_WIDTH * 0.3f, WIN_HEIGHT * 0.5f + 200);
	Vector gap = Vector(17, 17);

	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			shared_ptr<Block> block = make_shared<Block>();
			Vector pos = offset;
			pos.x += gap.x * x;
			pos.y -= gap.y * y;
			block->GetTransform()->SetPos(pos);

			_blocks[y].push_back(block);
		}
	}
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	for(auto blocks : _blocks)
	{
		for (auto block : blocks)
			block->Update();
	}
}

void TutorialScene::Render()
{
	for (auto blocks : _blocks)
	{
		for (auto block : blocks)
			block->Render();
	}
}
