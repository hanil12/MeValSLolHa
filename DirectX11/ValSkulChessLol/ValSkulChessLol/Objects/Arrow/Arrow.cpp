#include "framework.h"
#include "Arrow.h"

Arrow::Arrow()
{
	_arrow = make_shared<Quad>(L"Resource/Bullet.png");
}

Arrow::~Arrow()
{
}

void Arrow::Update()
{
	if (!_isActive) return;

	_arrow->Update();
	_arrow->GetTransform()->AddPos(_arrowDir * 5.0f * TimeManager::Instance()->DeltaTime());

	// Update�� ��ǻ�͸��� ȣ��Ǵ� �� �ٸ���
	_time += TimeManager::Instance()->DeltaTime();
	if (_time > 10.0f)
	{
		_time = 0.0f;
		_isActive = false;
	}
}

void Arrow::Render()
{
	if (!_isActive) return;

	_arrow->Render();
}

void Arrow::SetDir(Vector dir)
{
	_arrowDir = dir.UnitVector();
}

void Arrow::SetPos(Vector pos)
{
	_arrow->GetTransform()->SetPos(pos);
}
