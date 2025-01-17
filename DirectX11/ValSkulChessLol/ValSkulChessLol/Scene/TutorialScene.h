#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render() override;

private:
	shared_ptr<Quad> _quad1;
	shared_ptr<Quad> _quad2;

	// 1. Quad 하나 추가하고 다른 이미지로
	// 2. World View Projection 가 무엇인지 조사하기
};

