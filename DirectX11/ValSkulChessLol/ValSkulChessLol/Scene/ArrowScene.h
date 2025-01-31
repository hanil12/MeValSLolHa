#pragma once
class ArrowScene : public Scene
{
public:
	ArrowScene();
	~ArrowScene();

	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render() override;

private:
	shared_ptr<Quad> _bow;
	shared_ptr<Quad> _arrow;
};

