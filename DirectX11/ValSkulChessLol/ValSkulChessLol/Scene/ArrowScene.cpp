#include "framework.h"
#include "ArrowScene.h"

ArrowScene::ArrowScene()
{
	_bow = make_shared<Quad>(L"Resource/Bow.png");
	_arrow = make_shared<Quad>(L"Resource/Bullet.png");

	_bow->GetTransform()->SetPos({ 50,50 });
	_bow->GetTransform()->SetScale({ 0.5f, 0.5f });
}

ArrowScene::~ArrowScene()
{
}

void ArrowScene::Update()
{
	_bow->Update();

	// bow�� ���콺������ ȸ��
}

void ArrowScene::Render()
{
	_bow->Render();
}
