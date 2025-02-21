#pragma once
class Player
{
public:
	Player();
	~Player();

	void PreUpdate();
	void Update();
	void Render();
	void PostRender();

	void Input();

	// Bible
	void CreateBible();
	void AddBible();
	void RotateBible();

private:
	shared_ptr<Quad> _player;
	shared_ptr<RectCollider> _playerRect;

	shared_ptr<Transform> _bibleParent;
	vector<shared_ptr<class Bible>> _bibles;
	int _bibleCount = 0;
	float _bibleRadius = 100.0f;

	float _speed = 300.0f;
};

