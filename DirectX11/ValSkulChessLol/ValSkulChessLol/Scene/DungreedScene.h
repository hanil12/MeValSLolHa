#pragma once
class DungreedScene : public Scene
{
public:
	DungreedScene();
	~DungreedScene();

	// Scene��(��) ���� ��ӵ�
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void Input();

private:
	// 1. Player Ŭ����ȭ
	// 2. Arrow�� ��ü
	// 3. ������ ����� 10�� ���߸� ���� ���(extra)

	shared_ptr<Quad> _player;
	shared_ptr<RectCollider> _playerRect;

	float _speed = 10.0f;
};

