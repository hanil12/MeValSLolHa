#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	void Update() override;
	void Render() override;

private:
	shared_ptr<class Maze> _maze;
	shared_ptr<class Player> _player;
};

