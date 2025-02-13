#pragma once
class ColliderScene : public Scene
{
public:
	ColliderScene();
	~ColliderScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	void Input();

private:
	shared_ptr<RectCollider> _rect;
	shared_ptr<CircleCollider> _circle;
	shared_ptr<CircleCollider> _movingCircle;
};

