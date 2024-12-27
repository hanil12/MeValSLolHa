#include "framework.h"
#include "ArkanoidScene.h"

#include "Objects/GameObjects/Arkanoid/Block.h"
#include "Objects/GameObjects/Arkanoid/Map.h"

ArkanoidScene::ArkanoidScene()
{
	_arkanoidMap = make_shared<Map>();
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_arkanoidMap->Update();
}

void ArkanoidScene::Render(HDC hdc)
{
	_arkanoidMap->Render(hdc);
}
