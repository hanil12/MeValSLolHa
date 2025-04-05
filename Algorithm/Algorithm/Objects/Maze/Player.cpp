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
			_maze.lock()->SetBlockType(_pos, Block::PLAYER);
		}
		_pathIndex++;
	}
}

void Player::FindPath_RightHand()
{
	auto maze = _maze.lock();

	// ����� �� �� �ִ� ���� Ž���ϰ� _path �ִ� �۾�
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

		// ���� �� ���� (������ ���� ����)
		int newDir = (dir + 1 + Direction::DIR_COUNT) % Direction::DIR_COUNT;
		// �� ���� ������ ��ġ
		Vector newPos = pos + frontPos[newDir];
		// �� ���� �� ��ġ
		Vector oldPos = pos + frontPos[dir];

		// �������� �� �� �ִ�.
		if (Cango(newPos))
		{
			dir = (Direction)newDir;
			pos = newPos;
			_path.push_back(pos);
			_maze.lock()->SetBlockType(pos, Block::BlockType::FOOTPRINT);
		}
		// �������� �����ְ�, ���� �շ� �ִ�.
		else if(Cango(oldPos))
		{
			pos = oldPos;
			_path.push_back(pos);
			_maze.lock()->SetBlockType(pos, Block::BlockType::FOOTPRINT);
		}
		// ������ ��������, �յ� �����ִ�.
		else
		{
			// ���� ȸ��
			dir = static_cast<Direction>((dir - 1 + DIR_COUNT) % DIR_COUNT);
		}
	}

	_path.push_back(maze->EndPos());
	stack<Vector> s;

	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
			s.pop();
		else
			s.push(_path[i]);
	}

	_path.clear();
	
	while (true)
	{
		if (s.empty() == true)
			break;
		_path.push_back(s.top());
		s.pop();
	}

	std::reverse(_path.begin(), _path.end());
}

bool Player::Cango(Vector pos)
{
	Block::BlockType blockType = _maze.lock()->GetBlockType(pos);
	if (blockType == Block::BlockType::DISABLE)
		return false;

	return true;
}
