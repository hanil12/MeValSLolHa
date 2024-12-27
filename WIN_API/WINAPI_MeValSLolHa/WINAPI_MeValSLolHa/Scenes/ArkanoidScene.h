#pragma once
class Block;
class Map;

class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;
private:
	shared_ptr<Map> _arkanoidMap;
};

