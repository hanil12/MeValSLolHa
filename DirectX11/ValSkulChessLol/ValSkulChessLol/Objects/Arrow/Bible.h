#pragma once

class Bible
{
public:
	Bible();
	~Bible();

	void PreUpdate();
	void Update();

	void Render();
	void PostRender();

	shared_ptr<Transform> GetTransform();

	bool isActive = false;
private:
	shared_ptr<Quad> _quad;
	shared_ptr<CircleCollider> _col;
};

