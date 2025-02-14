#include "framework.h"
#include "ArrowScene.h"

#include "Objects/Arrow/Arrow.h"

ArrowScene::ArrowScene()
{
	_bow = make_shared<Quad>(L"Resource/Bow.png");
	_muzzle = make_shared<Transform>();
	
	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Arrow> arrow = make_shared<Arrow>();
		_arrows.push_back(arrow);
	}

	_bow->GetTransform()->SetPos({ 150,CENTER.y });
	_bow->GetTransform()->SetScale({ 0.5f, 0.5f });
	_muzzle->SetParent(_bow->GetTransform());
	_muzzle->SetPos(Vector(100, 0));

	_rectCollider = make_shared<RectCollider>(CENTER, Vector(100, 100));
	_temp = make_shared<CircleCollider>(CENTER, 100);
}

ArrowScene::~ArrowScene()
{
}

void ArrowScene::PreUpdate()
{
	for (int i = 0; i < 30; i++)
	{
		_arrows[i]->PreUpdate();
	}
}

void ArrowScene::Update()
{
	_temp->Update();
	_rectCollider->Update();

	_bow->Update();
	_muzzle->Update();
	
	for (int i = 0; i < 30; i++)
	{
		_arrows[i]->Update();
	}

	// bow가 마우스쪽으로 회전
	Vector dir = mousePos - _bow->GetTransform()->GetLocalPos();
	_bow->GetTransform()->SetAngle(dir.Angle());

	// 입력
	Input();
}

void ArrowScene::Render()
{
	_bow->Render();
	for (int i = 0; i < 30; i++)
	{
		_arrows[i]->Render();
	}

	_temp->Render();
	_rectCollider->Render();
}

void ArrowScene::PostRender()
{
	for (int i = 0; i < 30; i++)
	{
		_arrows[i]->PostRender();
	}
}

void ArrowScene::Input()
{
	if (InputManager::Instance()->Down(VK_LBUTTON))
	{
		Vector dir = mousePos - _bow->GetTransform()->GetWorldPos();

		// 꺼져있는 찾기
		auto noneActicveArrow = std::find_if(_arrows.begin(), _arrows.end(), [](shared_ptr<Arrow> arrow)-> bool 
			{
				if(arrow->GetActive() == false)
					return true;
				return false;
			});

		// 꺼져있는 얘가 한명도 없었다.
		if (noneActicveArrow == _arrows.end())
			return;

		shared_ptr<Arrow> arrow = *noneActicveArrow;
		arrow->SetActive(true);
		arrow->SetPos(_muzzle->GetWorldPos());
		arrow->SetDir(dir);
		arrow->SetAngle(dir.Angle());
	}
}
