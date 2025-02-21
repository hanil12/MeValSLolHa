#include "framework.h"
#include "Quad.h"

Quad::Quad(wstring textureFile)
{
	CreateMaterial(textureFile);
	CreateMesh();

    _transform = make_shared<Transform>();
    _leftRightBuffer = make_shared<LeftRightBuffer>();
    SetLeftRight(0);
    _colorBuffer = make_shared<ColorBuffer>();
    AddColor(XMFLOAT4(0, 0, 0, 0));
}

Quad::Quad(wstring textureFile, Vector size)
{
    _halfSize = size * 0.5f;
    CreateMaterial(textureFile);
    CreateMesh();

    _transform = make_shared<Transform>();
    _leftRightBuffer = make_shared<LeftRightBuffer>();
    SetLeftRight(0);
    _colorBuffer = make_shared<ColorBuffer>();
    AddColor(XMFLOAT4(0, 0, 0, 0));
}

Quad::~Quad()
{
}

void Quad::Update()
{
    _transform->Update();
}

void Quad::Render()
{
    _vs->IASetInputLayout();

    _vertexBuffer->IASet(0);
    _indexBuffer->IASetIndexBuffer();

    _vs->VSSet();
    _ps->PSSet();
    _transform->SetVS(0);
    _leftRightBuffer->SetPS(0);
    _colorBuffer->SetPS(1);

    _srv->PSSet_SRV(0);
    SAMPLER->PSSet_Sampler(0);

    DC->DrawIndexed(_indices.size(), 0, 0);
}

void Quad::CreateMaterial(wstring textureFile)
{
    _vs = make_shared<VertexShader>(L"Shaders/TextureVertexShader.hlsl");
    _ps = make_shared<PixelShader>(L"Shaders/TexturePixelShader.hlsl");

    _srv = make_shared<SRV>(textureFile);
}

void Quad::CreateMesh()
{
    if(_halfSize.Length() < 0.1f)
        _halfSize = _srv->GetImageSize() * 0.5f;

	_vertices =
    {
        { XMFLOAT3(-_halfSize.x, _halfSize.y, 0.0f), XMFLOAT2(0,0) }, //  ���� ���
        { XMFLOAT3(_halfSize.x, _halfSize.y, 0.0f), XMFLOAT2(1,0)}, // ���� ���
        { XMFLOAT3(_halfSize.x, -_halfSize.y, 0.0f), XMFLOAT2(1,1) }, // ���� �ϴ�
        { XMFLOAT3(-_halfSize.x, -_halfSize.y, 0.0f), XMFLOAT2(0,1)}, // ���� �ϴ�
    };

    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);

    _indices.push_back(0);
    _indices.push_back(2);
    _indices.push_back(3);

    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Texture), _vertices.size(), 0);
    _indexBuffer = make_shared<IndexBuffer>(&_indices[0], _indices.size());
}
