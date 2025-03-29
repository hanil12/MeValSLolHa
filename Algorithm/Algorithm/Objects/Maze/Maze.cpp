#include "framework.h"
#include "Maze.h"

#include "Objects/Maze/Block.h"

Maze::Maze()
{
	_blocks.resize(MAX_Y);

	Vector offset = Vector(WIN_WIDTH * 0.3f, WIN_HEIGHT * 0.5f + 200);
	Vector gap = Vector(17, 17);

	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			shared_ptr<Block> block = make_shared<Block>();
			Vector pos = offset;
			pos.x += gap.x * x;
			pos.y -= gap.y * y;
			block->SetPos(pos);

			_blocks[y].push_back(block);
		}
	}

	CreateMaze();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto blocks : _blocks)
	{
		for (auto block : blocks)
			block->Update();
	}
}

void Maze::Render()
{
	for (auto blocks : _blocks)
	{
		for (auto block : blocks)
			block->Render();
	}
}

void Maze::CreateMaze()
{
	// 노드 만들기
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			_blocks[y][x]->SetType(Block::BlockType::DISABLE);


			if ((x % 2 != 0) && (y % 2 != 0))
			{
				_blocks[y][x]->SetType(Block::BlockType::ABLE);
			}
		}
	}

	// 오른쪽 혹은 위아래 뚫기
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			int randNum = rand() % 2;

			if (x < 1 || y < 1 || x > MAX_X - 2 || y > MAX_Y - 2)
				continue;

			// 아래길, 오른쪽길 다 뚫어주기
			if (x == MAX_X - 2 || y == MAX_Y - 2)
			{
				_blocks[y][x]->SetType(Block::BlockType::ABLE);
				continue;
			}

			// 현재 노드가 아니면 continue
			if ((x % 2 == 0) || (y % 2 == 0))
			{
				continue;
			}

			// 아래 뚫기
			if (randNum == 0)
			{
				_blocks[y + 1][x]->SetType(Block::BlockType::ABLE);
			}

			// 오른쪽 뚫기
			else
			{
				_blocks[y][x + 1]->SetType(Block::BlockType::ABLE);
			}
		}
	}
}
