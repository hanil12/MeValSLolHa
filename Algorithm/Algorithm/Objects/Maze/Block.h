#pragma once
class Block
{
public:
	Block();
	~Block();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }

	void Update();
	void Render();

private:
	shared_ptr<Quad> _quad;
};

