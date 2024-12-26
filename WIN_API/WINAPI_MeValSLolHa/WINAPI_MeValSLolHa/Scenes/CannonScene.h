#pragma once
class Cannon;

class CannonScene : public Scene
{
public:
	CannonScene();
	~CannonScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<Cannon> _cannon;
	shared_ptr<Cannon> _cannon2;

	bool _turn = true;

	// 1. �ٸ� ĳ�� 1�� ����
	// 2. ���� �߻��ؼ� ĳ���� ������ �������
	// - ü�� �߰�
	// - ���� �߰�
	// - �����̽��� ������ �� ���� ������
};

