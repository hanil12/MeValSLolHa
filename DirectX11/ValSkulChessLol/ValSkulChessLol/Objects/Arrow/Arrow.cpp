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
	_arrow->GetTransform()->AddPos(_arrowDir * _arrowSpeed);

	// Update가 컴퓨터마다 호출되는 수 다르다
	_time += 0.001f;
	if (_time > _lifeTime)
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
