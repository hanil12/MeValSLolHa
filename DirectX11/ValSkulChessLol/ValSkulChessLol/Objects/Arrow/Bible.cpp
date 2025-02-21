#include "framework.h"
#include "Bible.h"

Bible::Bible()
{
    _col = make_shared<CircleCollider>(CENTER, 30);
    _quad = make_shared<Quad>(L"Resource/SIUUUU.jpg", Vector(_col->GetWorldRadius() * 2, _col->GetWorldRadius() * 2));
}

Bible::~Bible()
{
}

void Bible::PreUpdate()
{
    if (isActive == false)
        return;

    _col->Update();
}

void Bible::Update()
{
    if (isActive == false)
        return;

    _quad->GetTransform()->SetPos(_col->GetWorldCenter());

    _quad->Update();
}

void Bible::Render()
{
    if (isActive == false)
        return;

    _quad->Render();
}

void Bible::PostRender()
{
    if (isActive == false)
        return;

    _col->Render();
}

shared_ptr<Transform> Bible::GetTransform()
{
    return _col->GetTransform();
}
