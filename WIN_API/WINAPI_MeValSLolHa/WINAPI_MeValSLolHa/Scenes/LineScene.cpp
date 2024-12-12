#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_line1 = make_shared<Line>(Vector2D(100,100), Vector2D(100,100));
	_line2 = make_shared<Line>(Vector2D(100,500), Vector2D(200,500));
	_floor = make_shared<Line>(Vector2D(0,600), Vector2D(2000,100));

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

	// L
	Vector2D L = _line1->_end - _line1->_start;
	// Q
	Vector2D Q = _floor->_end - _floor->_start;
	float shadowLength = Q.NormalVector().DotProduct(L);
	_line2->_end = _line2->_start + Q.NormalVector() * shadowLength;

	// 내적
	// A Dot (B의 단위벡터) => A를 B벡터에 투영한 길이 => Dot Projection
}

void LineScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_floor->Render(hdc);
}
