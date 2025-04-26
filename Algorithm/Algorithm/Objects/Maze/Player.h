#pragma once

class Maze;

class Player
{
	enum Direction
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,

		DIR_COUNT
	};

	Vector frontPos[8] =
	{
		Vector(0,-1), // UP
		Vector(1,0), // RIGHT
		Vector(0,1), // DOWN
		Vector(-1,0), // LEFT
		Vector(-1,-1), // DOWN
		Vector(1,-1), // DOWN
		Vector(-1,1), // DOWN
		Vector(1,1), // DOWN
	};

	struct Vertex
	{
		Vertex(Vector pos, int g, int h) : pos(pos), g(g), h(h), f(g + h) {}

		Vector pos; // 정점 위치
		int g; // 가중치
		int h; // 휴리스틱함수
		int f; // g + h

		bool operator<(const Vertex& other) const
		{
			if (f < other.f)
				return true;
			return false;
		}

		bool operator>(const Vertex& other) const
		{
			if (f > other.f)
				return true;
			return false;
		}
	};

public:
	Player(shared_ptr<Maze> maze);
	~Player();

	void Update();

	void FindPath_RightHand();
	void BFS();
	void AStar();

	bool Cango(Vector pos);
private:
	weak_ptr<Maze> _maze;

	Vector _pos = { 1,1 };
	vector<Vector> _path;
	int _pathIndex = 0;
	float _time = 0.0f;

	vector<vector<bool>> _discovered;
	vector<vector<Vector>> _parent;
};

