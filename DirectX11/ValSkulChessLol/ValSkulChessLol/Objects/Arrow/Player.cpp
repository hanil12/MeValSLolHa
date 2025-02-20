#include "framework.h"
#include "Player.h"

Player::Player()
{
	_player = make_shared<Quad>(L"Resource/Player.png");
	_playerRect = make_shared<RectCollider>(Vector(0, 0), _player->GetImageSize());

	_playerRect->GetTransform()->SetPos(CENTER);
	_player->GetTransform()->SetParent(_playerRect->GetTransform());
	// playerRect : ÃÖ»óÀ§ => RootComponent

	_playerRect->GetTransform()->SetScale(Vector(0.1f, 0.1f));
}

Player::~Player()
{
}

void Player::PreUpdate()
{
	_playerRect->Update();
}

void Player::Update()
{
	Input();

	_player->Update();
}

void Player::Render()
{
	_player->Render();
}

void Player::PostRender()
{
	_playerRect->Render();
}

void Player::Input()
{
	if (KEY_PRESS('A'))
	{
		_playerRect->GetTransform()->AddPos(Vector(-1, 0) * DELTA_TIME * _speed);
		_player->SetLeftRight(1);
	}
	if (KEY_PRESS('D'))
	{
		_playerRect->GetTransform()->AddPos(Vector(1, 0) * DELTA_TIME * _speed);
		_player->SetLeftRight(0);
	}
	if (KEY_PRESS('W'))
	{
		_playerRect->GetTransform()->AddPos(Vector(0, 1) * DELTA_TIME * _speed);
	}
	if (KEY_PRESS('S'))
	{
		_playerRect->GetTransform()->AddPos(Vector(0, -1) * DELTA_TIME * _speed);
	}

}
