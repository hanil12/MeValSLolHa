#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	CreateVertices();

	_vs = make_shared<VertexShader>(L"Shader/TutoVertexShader.hlsl");
	_ps = make_shared<PixelShader>(L"Shader/TutoPixelShader.hlsl");
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{

}

void TutorialScene::Render()
{
    _vs->IASetInputLayout();
    _vertexBuffer->IASet(0);

    _vs->VSSet();
    _ps->PSSet();

    DC->Draw(_vertices.size(), 0);
}

void TutorialScene::CreateVertices()
{
    _vertices = { {0,0.5f}, {0.5f, -0.5f}, {-0.5f, -0.5f} };
    _vertices[0].color = { 1,0,0,1 };
    _vertices[1].color = { 0,1,0,1 };
    _vertices[2].color = { 0,0,1,1 };

    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Color), _vertices.size());
}
