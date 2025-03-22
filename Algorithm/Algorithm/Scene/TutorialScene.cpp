#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_quad = make_shared<Quad>(Vector(100,100));
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	Vector temp = { 300,0 };

	_quad->GetTransform()->AddPos(temp * DELTA_TIME);
	_quad->Update();
}

void TutorialScene::Render()
{
	_quad->Render();
}
