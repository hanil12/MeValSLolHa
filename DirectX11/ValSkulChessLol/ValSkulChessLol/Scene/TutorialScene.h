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
	shared_ptr<Quad> _quad;

	// 1. Quad �ϳ� �߰��ϰ� �ٸ� �̹�����
	// 2. World View Projection �� �������� �����ϱ�
};

