#pragma once
class ArrowScene : public Scene
{
public:
	ArrowScene();
	~ArrowScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;

private:
	shared_ptr<Quad> _bow;
	shared_ptr<Quad> _arrow;
};

