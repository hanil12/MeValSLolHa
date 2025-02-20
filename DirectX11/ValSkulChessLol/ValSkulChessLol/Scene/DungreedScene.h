#pragma once

class BamSurviver : public Scene
{
public:
	BamSurviver();
	~BamSurviver();

	// Scene��(��) ���� ��ӵ�
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<Quad> _backGround;

	shared_ptr<class Player> _player;
};

