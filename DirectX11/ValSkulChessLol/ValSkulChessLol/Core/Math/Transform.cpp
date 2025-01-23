#include "framework.h"
#include "Transform.h"

Transform::Transform()
{
	_world = make_shared<MatrixBuffer>();
}

Transform::~Transform()
{
}

void Transform::Update()
{
    XMMATRIX srtMatrix = XMMatrixIdentity();
    XMMATRIX scaleM = XMMatrixScaling(_scale.x, _scale.y, 1);
    XMMATRIX rotatateM = XMMatrixRotationZ(_angle);
    XMMATRIX translateM = XMMatrixTranslation(_pos.x, _pos.y, 0);
    srtMatrix = scaleM * rotatateM * translateM;

    _world->SetData(srtMatrix);

    _world->Update();
}

void Transform::SetVS(int slot)
{
    _world->SetVS(slot);
}
