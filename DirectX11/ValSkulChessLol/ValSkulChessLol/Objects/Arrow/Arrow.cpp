#include "framework.h"
#include "Arrow.h"

Arrow::Arrow()
{
	_arrow = make_shared<Quad>(L"Resource/Bullet.png");
	_circleCollider = make_shared<CircleCollider>(Vector(0, 0), _arrow->GetImageSize().x);
	_circleCollider->GetTransform()->SetParent(_arrow->GetTransform());

	_arrow->GetTransform()->SetScale(Vector(0.2f, 0.2f));
	_circleCollider->GetTransform()->SetScale(Vector(0.1f, 0.1f));
	_circleCollider->GetTransform()->SetPos(Vector(250, 0));
}

Arrow::~Arrow()
{
}

void Arrow::PreUpdate()
{
	if (!_isActive) return;

	_circleCollider->Update();
}

void Arrow::Update()
{
	if (!_isActive) return;

	_arrow->Update();
	_arrow->GetTransform()->AddPos(_arrowDir * 5.0f * TimeManager::Instance()->DeltaTime());

	// Update가 컴퓨터마다 호출되는 수 다르다
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

void Arrow::PostRender()
{
	if (!_isActive) return;

	_circleCollider->Render();
}

void Arrow::SetDir(Vector dir)
{
	_arrowDir = dir.UnitVector();
}

void Arrow::SetPos(Vector pos)
{
	_arrow->GetTransform()->SetPos(pos);
}
