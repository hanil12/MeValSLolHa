#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_line1 = make_shared<Line>(Vector2D(100,100), Vector2D(100,100));
	_line2 = make_shared<Line>(Vector2D(100,500), Vector2D(200,500));
	_floor = make_shared<Line>(Vector2D(0,600), Vector2D(2000,600));

	// TODO
	// _line2의 길이를 floor에 비치는 line1의 그림자 길이만큼 'floor의 방향'으로 커지게 그려주세요.

	// TODO
	//_floor = make_shared<Line>(Vector2D(0, 600), Vector2D(2000, 300));
}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	_line1->_end = mousePos;

	_line1->Update();
	_line2->Update();
	_floor->Update();
}

void LineScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_floor->Render(hdc);
}
