#pragma once

#define MAX_X 25
#define MAX_Y 25

#include "Block.h"

class Maze
{
public:
	Maze();
	~Maze();

	void CreateMaze();

	void Update();
	void Render();

	Vector StartPos() { return Vector(1, 1); }
	Vector EndPos() { return {MAX_X - 2, MAX_Y - 2}; }

	void SetBlockType(Vector pos, Block::BlockType type) { _blocks[pos.y][pos.x]->SetType(type); }
	Block::BlockType GetBlockType(Vector pos) { return _blocks[pos.y][pos.x]->GetType(); }

private:
	vector<vector<shared_ptr<class Block>>> _blocks;
};

