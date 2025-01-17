#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_quad1 = make_shared<Quad>(L"Resource/SIUUUU.jpg");
	_quad2 = make_shared<Quad>(L"Resource/MeGod.jpg");

	// Çà·Ä, WVP (SRT)
	// - Çà·Ä µ¡¼À
	// - Çà·Ä °ö¼À
	// - Çà·ÄÀÇ Á¾·ù
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_quad1->Update();
	_quad2->Update();
}

void TutorialScene::Render()
{
	_quad1->Render();
	_quad2->Render();
}
