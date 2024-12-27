#pragma once
class Block;

class Map
{
public:
	Map();
	~Map();

	void Update();
	void Render(HDC hdc);

private:
	int _blockCount_X = 7;
	int _blockCount_Y = 3;


	vector<shared_ptr<Block>> _blocks;
};

