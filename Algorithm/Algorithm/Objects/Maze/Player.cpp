#include "framework.h"
#include "Player.h"

#include "Objects/Maze/Block.h"
#include "Objects/Maze/Maze.h"

Player::Player(shared_ptr<Maze> maze)
: _maze(maze)
{
	_maze.lock()->SetBlockType(_pos, Block::BlockType::PLAYER);
	FindPath_RightHand();
}

Player::~Player()
{
}

void Player::Update()
{
	if (_pathIndex >= _path.size())
		return;

	_time += DELTA_TIME;

	if (_time > 0.1f)
	{
		_time = 0.0f;
		_pos = _path[_pathIndex];

		if (_pathIndex != 0)
		{
			// TODO : 발자취
		}
		_pathIndex++;
	}

	// 미로에서 Player 색을 칠하기
	_maze.lock()->SetBlockType(_pos, Block::BlockType::PLAYER);
}

void Player::FindPath_RightHand()
{
	auto maze = _maze.lock();

	// 우수법 갈 수 있는 길을 탐색하고 _path 넣는 작업
	Direction dir = Direction::UP;
	Vector start = { 1,1 };
	Vector end = maze->EndPos();

	Vector frontPos[4] =
	{
		Vector(0,-1), // UP
		Vector(1,0), // RIGHT
		Vector(0,1), // DOWN
		Vector(-1,0) // LEFT
	};

	Vector pos = start;
	_path.push_back(pos);
	while(true)
	{
		if (pos == end)
			break;

		// 새로 갈 방향 (오른쪽 도는 방향)
		int newDir = (dir + 1 + Direction::DIR_COUNT) % Direction::DIR_COUNT;
		// 내 현재 오른쪽 위치
		Vector newPos = pos + frontPos[newDir];
		// 내 현재 앞 위치
		Vector oldPos = pos + frontPos[dir];

		// 오른쪽이 갈 수 있다.
		if (Cango(newPos))
		{
			dir = (Direction)newDir;
			pos = newPos;
			_path.push_back(pos);
		}
		// 오른쪽이 막혀있고, 앞이 뚫려 있다.
		else if(Cango(oldPos))
		{
			pos = oldPos;
			_path.push_back(pos);
		}
		// 오른쪽 막혀있음, 앞도 막혀있다.
		else
		{
			// 왼쪽 회전
			dir = static_cast<Direction>((dir - 1 + DIR_COUNT) % DIR_COUNT);
		}
	}
}

bool Player::Cango(Vector pos)
{
	Block::BlockType blockType = _maze.lock()->GetBlockType(pos);
	if (blockType == Block::BlockType::DISABLE)
		return false;

	return true;
}
