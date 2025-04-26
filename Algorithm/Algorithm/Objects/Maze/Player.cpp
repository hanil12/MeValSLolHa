#include "framework.h"
#include "Player.h"

#include "Objects/Maze/Block.h"
#include "Objects/Maze/Maze.h"

Player::Player(shared_ptr<Maze> maze)
: _maze(maze)
{
	_maze.lock()->SetBlockType(_pos, Block::BlockType::PLAYER);
	AStar();
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
			_maze.lock()->SetBlockType(pos, Block::BlockType::FOOTPRINT);
		}
		// 오른쪽이 막혀있고, 앞이 뚫려 있다.
		else if(Cango(oldPos))
		{
			pos = oldPos;
			_path.push_back(pos);
			_maze.lock()->SetBlockType(pos, Block::BlockType::FOOTPRINT);
		}
		// 오른쪽 막혀있음, 앞도 막혀있다.
		else
		{
			// 왼쪽 회전
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

void Player::BFS()
{
	_parent.resize(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));
	_discovered.resize(MAX_Y, vector<bool>(MAX_X, false));

	queue<Vector> q;
	Vector start = _maze.lock()->StartPos();
	Vector end = _maze.lock()->EndPos();
	_parent[start.y][start.x] = start;
	_discovered[start.y][start.x] = true;

	q.push(start);
	while (true)
	{
		Vector here = q.front();
		if (here == end)
			break;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Vector there = here + frontPos[i];

			if (Cango(there) == false)
				continue;
			if (_discovered[there.y][there.x])
				continue;

			q.push(there);
			_parent[there.y][there.x] = here;
			_discovered[there.y][there.x] = true;
			_maze.lock()->SetBlockType(there, Block::BlockType::FOOTPRINT);
		}
	}

	Vector check = end;
	_path.push_back(end);
	while (true)
	{
		if (check == start)
			break;

		check = _parent[check.y][check.x];
		_path.push_back(check);
	}

	std::reverse(_path.begin(), _path.end());
}

void Player::AStar()
{
	Vector start = _maze.lock()->StartPos();
	Vector end = _maze.lock()->EndPos();

	_parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));
	_parent[start.y][start.x] = start;
	vector<vector<int>> best = vector<vector<int>>(MAX_Y, vector<int>(MAX_X, INT_MAX));
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;

	Vertex startV(start, 0, Vector::Manhattan(start, end) * 10);
	best[start.y][start.x] = startV.f;
	pq.push(startV);

	while (true)
	{
		if (pq.empty())
			break;

		Vertex hereV = pq.top();
		Vector here = hereV.pos;
		pq.pop();

		if (here == end)
			break;

		// pq에 이미 예약이 걸려있었는데, 더 좋은게 먼저 발견된 경우
		if (hereV.f > best[here.y][here.x])
			continue;

		for (int i = 0; i < 8; i++)
		{
			Vector there = here + frontPos[i];

			if (Cango(there) == false)
				continue;

			int newG = hereV.g;
			if (i < 4)
				newG += 10;
			else
				newG += 14;

			int newH = (end - there).Length() * 10;
			int newF = newG + newH;

			if (newF > best[there.y][there.x])
				continue;

			Vertex thereV(there, newG, newH);
			pq.push(thereV);
			_parent[there.y][there.x] = here;
			best[there.y][there.x] = thereV.f;
			_maze.lock()->SetBlockType(there, Block::BlockType::FOOTPRINT);
		}
	}

	Vector check = end;
	_path.push_back(end);
	while (true)
	{
		if (check == start)
			break;

		check = _parent[check.y][check.x];
		_path.push_back(check);
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
