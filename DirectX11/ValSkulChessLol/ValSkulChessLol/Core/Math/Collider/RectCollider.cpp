#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
: _center(center), _halfSize(size * 0.5f)
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
