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

private:
	shared_ptr<Quad> _player;
	shared_ptr<RectCollider> _playerRect;

	float _speed = 300.0f;
};

