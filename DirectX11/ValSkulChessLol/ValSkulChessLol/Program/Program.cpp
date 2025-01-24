#include "framework.h"
#include "Program.h"

#include "Scene/TutorialScene.h"
#include "Scene/SolarSystemScene.h"

Program::Program()
{
    _scene = make_shared<SolarSystemScene>();

    _view = make_shared<MatrixBuffer>();
    _projection = make_shared<MatrixBuffer>();

    XMMATRIX projectionM = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, 0, 1.0f);
    _projection->SetData(projectionM);

    _view->Update();
    _projection->Update();
}

Program::~Program()
{
}

void Program::Update()
{
    _scene->Update();
}

void Program::Render()
{
    FLOAT myColorR = 0.0f;
    FLOAT myColorG = 0.0f;
    FLOAT myColorB = 0.0f;

    FLOAT clearColor[4] = { myColorR, myColorG, myColorB, 1.0f };

    DC->ClearRenderTargetView(Device::Instance()->GetRTV().Get(), clearColor);

    
    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    // �츮�� �׸� ��� ��
    _view->SetVS(1);
    _projection->SetVS(2);

    _scene->Render();

    Device::Instance()->GetSwapChain()->Present(0, 0);
}
