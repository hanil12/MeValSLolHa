#include "framework.h"
#include "SolarSystemScene.h"

SolarSystemScene::SolarSystemScene()
{
	_sun = make_shared<Quad>(L"Resource/sun.png");
	_sun->GetTransform()->SetPos(CENTER);

	// Sun�� ��ġ�� ���� ���� Ʈ������
	_sunTrans = make_shared<Transform>();

	_earth = make_shared<Quad>(L"Resource/earth.png");
	_earth->GetTransform()->AddPos(Vector(200, 0));
	_earth->GetTransform()->SetScale(Vector(0.5f, 0.5f));
	_earth->GetTransform()->SetParent(_sunTrans);
	
	_moon = make_shared<Quad>(L"Resource/moon.png");
	_moon->GetTransform()->AddPos(Vector(200, 0));
	_moon->GetTransform()->SetScale(Vector(0.2f, 0.2f));
	_moon->GetTransform()->SetParent(_earth->GetTransform());

	// �ǽ�
	// 1. ������ ����, �޵� ����

	// �ǽ�2
	// 1. ���� ��Ȳ
	// �¾��� 2PI��ŭ �������� �� ������ ������ 2PI = > �¾��� �����ֱ�� ������ �����ֱ� ��ġ�Ѵ�.
	// => �¾��� 1���� �������� �� ������ �ι��� ����
	// ... ������ 1���� �������� �� ���� 0.5���� ����
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

	// ���� Ʈ������
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
