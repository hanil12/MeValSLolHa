#include "framework.h"
#include "Transform.h"

Transform::Transform()
{
	_world = make_shared<MatrixBuffer>();
    _srtMatrix = XMMatrixIdentity();
}

Transform::~Transform()
{
}

void Transform::Update()
{
    XMMATRIX scaleM = XMMatrixScaling(_scale.x, _scale.y, 1);
    XMMATRIX rotatateM = XMMatrixRotationZ(_angle);
    XMMATRIX translateM = XMMatrixTranslation(_pos.x, _pos.y, 0);
    _srtMatrix = scaleM * rotatateM * translateM;

    if (_parent.expired() == false)
    {
        // 부모가 설정되어있다면 부모의 행렬 뒤에 곱해준다.
        // => 부모의 좌표계로 이동된다.
        _srtMatrix *= _parent.lock()->GetMatrix();
    }

    _world->SetData(_srtMatrix);

    _world->Update();
}

void Transform::SetVS(int slot)
{
    _world->SetVS(slot);
}

Vector Transform::GetWorldPos()
{
    Vector result;
    result.x = _srtMatrix.r[3].m128_f32[0];
    result.y = _srtMatrix.r[3].m128_f32[1];

    return result;
}

Vector Transform::GetWorldScale()
{
    if (_parent.expired() == true)
        return _scale;

    Vector parentScale = _parent.lock()->GetWorldScale();

    return Vector(_scale.x * parentScale.x, _scale.y * parentScale.y);
}
