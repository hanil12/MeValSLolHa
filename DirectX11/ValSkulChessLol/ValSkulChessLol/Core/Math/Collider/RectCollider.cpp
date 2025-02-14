#include "framework.h"
#include "RectCollider.h"
#include "CircleCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
: _halfSize(size * 0.5f)
{
	CreateMesh();
	CreateMaterial();

    _transform = make_shared<Transform>();
    _transform->SetPos(center);

    _colorBuffer = make_shared<ColorBuffer>();
    SetGreen();
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
    _transform->Update();
    _colorBuffer->Update();
}

void RectCollider::Render()
{
    _vs->IASetInputLayout();
    _vertexBuffer->IASet(0);

    _transform->SetVS(0);
    _colorBuffer->SetPS(0);

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    _vs->VSSet();
    _ps->PSSet();

    DC->Draw(_vertices.size(), 0);
}

RectCollider::OBB_DESC RectCollider::GetOBB()
{
    OBB_DESC result;
    result.pos = GetWorldCenter();
    result.halfSize.x = _halfSize.x * _transform->GetWorldScale().x;
    result.halfSize.y = _halfSize.y * _transform->GetWorldScale().y;
    XMMATRIX m = _transform->GetMatrix();
    result.direction[0] = Vector(m.r[0].m128_f32[0], m.r[0].m128_f32[1]).UnitVector();
    result.direction[1] = Vector(m.r[1].m128_f32[0], m.r[1].m128_f32[1]).UnitVector();

    return result;
}

bool RectCollider::IsCollision(Vector pos)
{
    OBB_DESC desc = GetOBB();

    Vector aTob = pos - desc.pos;
    Vector nea1 = desc.direction[0];
    float length1 = abs(nea1.Dot(aTob));

    if (length1 > desc.halfSize.x)
        return false;

    Vector nea2 = desc.direction[1];
    float length2 = abs(nea2.Dot(aTob));

    if (length2 > desc.halfSize.y)
        return false;

    return true;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
    return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
    OBB_DESC desc = GetOBB();
    Vector aTob = other->GetWorldCenter() - desc.pos;
    float circleRaidus = other->GetWorldRadius();

    float longest = desc.halfSize.Length();
    if (longest + circleRaidus < aTob.Length())
        return false;

    Vector uea1 = desc.direction[0];
    float lengthA = abs(uea1.Dot(aTob));
    if (lengthA > circleRaidus + desc.halfSize.x)
        return false;

    Vector uea2 = desc.direction[1];
    float lengthB = abs(uea2.Dot(aTob));
    if (lengthB > circleRaidus + desc.halfSize.y)
        return false;

    return true;
}

void RectCollider::CreateMesh()
{
    _vertices =
    {
        { XMFLOAT3(-_halfSize.x, _halfSize.y, 0.0f) }, //  좌측 상단
        { XMFLOAT3(_halfSize.x, _halfSize.y, 0.0f)}, // 우측 상단
        { XMFLOAT3(_halfSize.x, -_halfSize.y, 0.0f) }, // 우측 하단
        { XMFLOAT3(-_halfSize.x, -_halfSize.y, 0.0f)}, // 좌측 하단
        { XMFLOAT3(-_halfSize.x, _halfSize.y, 0.0f) }, // 좌측 상단
    };

    _vertexBuffer = make_shared<VertexBuffer>(&_vertices[0], sizeof(Vertex), _vertices.size(), 0);
}

void RectCollider::CreateMaterial()
{
    _vs = make_shared<VertexShader>(L"Shaders/ColliderVertexShader.hlsl");
    _ps = make_shared<PixelShader>(L"Shaders/ColliderPixelShader.hlsl");
}
