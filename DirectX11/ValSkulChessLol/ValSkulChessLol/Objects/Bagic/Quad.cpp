#include "framework.h"
#include "Quad.h"

Quad::Quad(wstring textureFile)
{
	CreateMesh();
	CreateMaterial(textureFile);

    _transform = make_shared<Transform>();
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

    _vs->VSSet();
    _ps->PSSet();
    _transform->SetVS(0);

    _srv->PSSet_SRV(0);
    _samplerState->PSSet_Sampler(0);

    DC->Draw(6, 0);
}

void Quad::CreateMaterial(wstring textureFile)
{
    _vs = make_shared<VertexShader>(L"Shaders/TutorialShader.hlsl");
    _ps = make_shared<PixelShader>(L"Shaders/TutorialShader.hlsl");

    _srv = make_shared<SRV>(textureFile);
    _samplerState = make_shared<SamplerState>();
}

void Quad::CreateMesh()
{
	_vertices =
    {
        { XMFLOAT3(-300.0f, 300.0f, 0.0f), XMFLOAT2(0,0) }, //  좌측 상단
        { XMFLOAT3(300.0f, -300.0f, 0.0f), XMFLOAT2(1,1) }, // 우측 하단
        { XMFLOAT3(-300.0f, -300.0f, 0.0f), XMFLOAT2(0,1)}, // 좌측 하단

        { XMFLOAT3(-300.0f, 300.0f, 0.0f), XMFLOAT2(0,0)}, // 좌측 상단
        { XMFLOAT3(300.0f, 300.0f, 0.0f), XMFLOAT2(1,0)}, // 우측 상단
        { XMFLOAT3(300.0f, -300.0f, 0.0f), XMFLOAT2(1,1)} // 우측 하단
    };

    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Texture), _vertices.size(), 0);
}
