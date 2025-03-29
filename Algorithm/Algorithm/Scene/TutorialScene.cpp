#include "framework.h"
#include "TutorialScene.h"

#include "Objects/Maze/Block.h"
#include "Objects/Maze/Maze.h"
#include "Objects/Maze/Player.h"

TutorialScene::TutorialScene()
{
	_maze = make_shared<Maze>();
	_player = make_shared<Player>(_maze);
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_maze->Update();
	_player->Update();
}

void TutorialScene::Render()
{
	_maze->Render();
}
