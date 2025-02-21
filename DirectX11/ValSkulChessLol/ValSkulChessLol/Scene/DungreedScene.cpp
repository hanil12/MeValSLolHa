#include "framework.h"
#include "DungreedScene.h"

#include "Objects/Arrow/Player.h"

BamSurviver::BamSurviver()
{
	_backGround = make_shared<Quad>(L"Resource/Map.png");
	_player = make_shared<Player>();

	_backGround->GetTransform()->SetPos(CENTER);
	_backGround->GetTransform()->SetScale(Vector(1.5f, 1.5f));
	_backGround->AddColor(XMFLOAT4(0.2f, 0.2f, 0.2f, 0.0f));
	_backGround->Update();
}

BamSurviver::~BamSurviver()
{
}

void BamSurviver::PreUpdate()
{
	_player->PreUpdate();
}

void BamSurviver::Update()
{
	_time += DELTA_TIME;
	if (_time > 1.0f)
	{
		_player->AddBible();
		_time = 0.0f;
	}

	_player->Update();
}

void BamSurviver::Render()
{
	_backGround->Render();

	_player->Render();
}

void BamSurviver::PostRender()
{
	_player->PostRender();
}

