#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_player = make_shared<Quad>(L"Resource/Player.png");
	_playerRect = make_shared<RectCollider>(Vector(0,0), _player->GetImageSize());

	_player->GetTransform()->SetPos(CENTER);
	_playerRect->GetTransform()->SetParent(_player->GetTransform());

	_player->GetTransform()->SetScale(Vector(0.1f, 0.1f));
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::PreUpdate()
{
	_playerRect->Update();
}

void DungreedScene::Update()
{
	_player->Update();
}

void DungreedScene::Render()
{
	_player->Render();
}

void DungreedScene::PostRender()
{
	_playerRect->Render();
}

void DungreedScene::Input()
{

}
