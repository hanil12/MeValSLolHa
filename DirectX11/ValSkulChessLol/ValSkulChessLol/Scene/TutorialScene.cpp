#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_quad1 = make_shared<Quad>(L"Resource/SIUUUU.jpg");
	_quad2 = make_shared<Quad>(L"Resource/MeGod.jpg");
	// 행렬변환
	// WVP : World View Projection
	// SRT : 좌표이동 == 좌표계변환 
	// (Local Space) x (World) x (View) x (Projection) => VS : 각 정점에 대한 계산을 수행

	// SolarSystem

	_quad1->GetTransform()->SetPos(CENTER);
	_quad1->GetTransform()->SetScale(Vector(0.5f, 0.5f));
	_quad2->GetTransform()->SetScale(Vector(0.5f, 0.5f));
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_quad1->GetTransform()->AddAngle(0.001f);
	_quad2->GetTransform()->AddPos(Vector(1, 1) * 0.001);

	_quad1->Update();
	_quad2->Update();
}

void TutorialScene::Render()
{
	_quad1->Render();
	_quad2->Render();
}
