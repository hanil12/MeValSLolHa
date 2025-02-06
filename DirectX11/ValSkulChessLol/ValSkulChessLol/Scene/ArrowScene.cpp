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
}

ArrowScene::~ArrowScene()
{
}

void ArrowScene::Update()
{
	_bow->Update();
	_muzzle->Update();
	
	for (int i = 0; i < 30; i++)
	{
		_arrows[i]->Update();
	}

	// bow�� ���콺������ ȸ��
	Vector dir = mousePos - _bow->GetTransform()->GetLocalPos();
	_bow->GetTransform()->SetAngle(dir.Angle());

	// �Է�
	Input();
}

void ArrowScene::Render()
{
	_bow->Render();
	for (int i = 0; i < 30; i++)
	{
		_arrows[i]->Render();
	}
}

void ArrowScene::Input()
{
	if (InputManager::Instance()->Down(VK_LBUTTON))
	{
		Vector dir = mousePos - _bow->GetTransform()->GetWorldPos();

		// �����ִ� ã��
		auto noneActicveArrow = std::find_if(_arrows.begin(), _arrows.end(), [](shared_ptr<Arrow> arrow)-> bool 
			{
				if(arrow->GetActive() == false)
					return true;
				return false;
			});

		// �����ִ� �갡 �Ѹ� ������.
		if (noneActicveArrow == _arrows.end())
			return;

		shared_ptr<Arrow> arrow = *noneActicveArrow;
		arrow->SetActive(true);
		arrow->SetPos(_muzzle->GetWorldPos());
		arrow->SetDir(dir);
		arrow->SetAngle(dir.Angle());
	}
}
