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

public:
	Player(shared_ptr<Maze> maze);
	~Player();

	void Update();

	void FindPath_RightHand();

	bool Cango(Vector pos);
private:
	weak_ptr<Maze> _maze;

	Vector _pos = { 1,1 };
	vector<Vector> _path;
	int _pathIndex = 0;
	float _time = 0.0f;
};

