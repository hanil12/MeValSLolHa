#include "framework.h"
#include "Player.h"

#include "Bible.h"

Player::Player()
{
	_player = make_shared<Quad>(L"Resource/Player.png");
	_playerRect = make_shared<RectCollider>(Vector(0, 0), _player->GetImageSize());

	_playerRect->GetTransform()->SetPos(CENTER);
	_player->GetTransform()->SetParent(_playerRect->GetTransform());
	// playerRect : ÃÖ»óÀ§ => RootComponent

	_playerRect->GetTransform()->SetScale(Vector(0.1f, 0.1f));

	CreateBible();
}

Player::~Player()
{
}

void Player::PreUpdate()
{
	_playerRect->Update();

	for (auto bible : _bibles)
		bible->PreUpdate();
}

void Player::Update()
{
	Input();
	RotateBible();

	_player->Update();

	for (auto bible : _bibles)
		bible->Update();
}

void Player::Render()
{
	_player->Render();

	for (auto bible : _bibles)
		bible->Render();
}

void Player::PostRender()
{
	_playerRect->Render();
	for (auto bible : _bibles)
		bible->PostRender();
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

void Player::CreateBible()
{
	_bibleParent = make_shared<Transform>();
	_bibleParent->SetParent(_playerRect->GetTransform());
	_bibleParent->SetScale({ 10,10 });

	for (int i = 0; i < 10; i++)
	{
		shared_ptr<Bible> _bible = make_shared<Bible>();
		_bible->GetTransform()->SetParent(_bibleParent);
		_bible->GetTransform()->SetPos({ _bibleRadius,0 });
		_bibles.push_back(_bible);
	}
}

void Player::AddBible()
{
	auto iter = std::find_if(_bibles.begin(), _bibles.end(), [](shared_ptr<Bible> bible)-> bool
		{
			if (bible->isActive == false)
				return true;
			return false;
		});

	if (iter == _bibles.end())
		return;

	(*iter)->isActive = true;
	_bibleCount++;

	float deltaAngle = 2 * PI / (float)_bibleCount;
	for (int i = 0; i < _bibleCount; i++)
	{
		Vector pos = Vector(cos(deltaAngle * i), sin(deltaAngle * i));
		_bibles[i]->GetTransform()->SetPos(pos * _bibleRadius);
	}
}

void Player::RotateBible()
{
	_bibleParent->AddAngle(PI * DELTA_TIME);
	_bibleParent->Update();
}
