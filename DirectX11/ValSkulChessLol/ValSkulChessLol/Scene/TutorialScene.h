#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;

private:
	shared_ptr<Quad> _quad1;
	shared_ptr<Quad> _quad2;

	// 1. Quad �ϳ� �߰��ϰ� �ٸ� �̹�����
	// 2. World View Projection �� �������� �����ϱ�
};

