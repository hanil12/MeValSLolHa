#include "framework.h"
#include "Program.h"

#include "Scenes/PaintScene.h"
#include "Scenes/CollisionScene.h"
#include "Scenes/LineScene.h"
#include "Scenes/CannonScene.h"
#include "Scenes/ArkanoidScene.h"

Program::Program()
{
	_sceneTable["PaintScene"] = make_shared<PaintScene>();
	_sceneTable["CollisionScene"] = make_shared<CollisionScene>();
	_sceneTable["LineScene"] = make_shared<LineScene>();
	_sceneTable["CannonScene"] = make_shared<CannonScene>();
	_sceneTable["ArkanoidScene"] = make_shared<ArkanoidScene>();

	_curScene = "ArkanoidScene";
}

Program::~Program()
{
}

void Program::Update()
{
	_sceneTable[_curScene]->Update();
}

void Program::Render(HDC hdc)
{
	_sceneTable[_curScene]->Render(hdc);
}
