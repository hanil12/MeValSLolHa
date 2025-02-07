#pragma once
class ArrowScene : public Scene
{
public:
	ArrowScene();
	~ArrowScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;

	void Input();

private:
	shared_ptr<Quad> _bow;
	vector<shared_ptr<class Arrow>> _arrows;

	// muzzle
	shared_ptr<Transform> _muzzle;

	shared_ptr<RectCollider> _rectCollider;
};

