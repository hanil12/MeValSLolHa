#include "framework.h"
#include "SolarSystemScene.h"

SolarSystemScene::SolarSystemScene()
{
	_sun = make_shared<Quad>(L"Resource/sun.png");
	_sun->GetTransform()->SetPos(CENTER);

	// Sun과 위치만 같고 깡통 트랜스폼
	_sunTrans = make_shared<Transform>();

	_earth = make_shared<Quad>(L"Resource/earth.png");
	_earth->GetTransform()->AddPos(Vector(200, 0));
	_earth->GetTransform()->SetScale(Vector(0.5f, 0.5f));
	_earth->GetTransform()->SetParent(_sunTrans);
	
	_moon = make_shared<Quad>(L"Resource/moon.png");
	_moon->GetTransform()->AddPos(Vector(200, 0));
	_moon->GetTransform()->SetScale(Vector(0.2f, 0.2f));
	_moon->GetTransform()->SetParent(_earth->GetTransform());

	// 실습
	// 1. 지구도 자전, 달도 자전

	// 실습2
	// 1. 현재 상황
	// 태양이 2PI만큼 자전했을 때 지구의 공전도 2PI = > 태양의 자전주기와 지구의 공전주기 일치한다.
	// => 태양이 1바퀴 자전했을 때 지구는 두바퀴 공전
	// ... 지구가 1바퀴 자전했을 때 달은 0.5바퀴 공전
}

SolarSystemScene::~SolarSystemScene()
{
}

void SolarSystemScene::Update()
{
	_sun->Update();
	_earth->Update();
	_moon->Update();
	_sunTrans->Update();

	// 깡통 트랜스폼
	_sunTrans->SetPos(_sun->GetTransform()->GetPos());

	_sun->GetTransform()->AddAngle(0.0001f);
	_sunTrans->AddAngle(0.00005f);
	_earth->GetTransform()->AddAngle(0.0001f);
}

void SolarSystemScene::Render()
{
	_sun->Render();
	_earth->Render();
	_moon->Render();
}
