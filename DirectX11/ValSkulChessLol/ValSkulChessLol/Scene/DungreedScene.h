#pragma once
class DungreedScene : public Scene
{
public:
	DungreedScene();
	~DungreedScene();

	// Scene을(를) 통해 상속됨
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void Input();

private:
	// 1. Player 클래스화
	// 2. Arrow랑 합체
	// 3. 보스몹 만들고 10번 맞추면 보스 사망(extra)

	shared_ptr<Quad> _player;
	shared_ptr<RectCollider> _playerRect;

	float _speed = 10.0f;
};

