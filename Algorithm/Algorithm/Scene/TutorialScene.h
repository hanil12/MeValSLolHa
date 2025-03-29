#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	void Update() override;
	void Render() override;

private:
	vector<vector<shared_ptr<class Block>>> _blocks;
};

