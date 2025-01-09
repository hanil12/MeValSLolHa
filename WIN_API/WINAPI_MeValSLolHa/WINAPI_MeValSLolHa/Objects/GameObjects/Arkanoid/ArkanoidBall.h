#pragma once
#include "Objects/GameObjects/Ball.h"
class Bar;
class Block;

class ArkanoidBall : public Ball
{
public:
	ArkanoidBall(shared_ptr<Bar> bar);
	~ArkanoidBall();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	// Ãæµ¹
	void IsCollsion(shared_ptr<Block> block);
	void IsCollisionBar();

	void BeforeFireUpdate();
	void MapReflection();

	bool IsFired() { return _isFired; }
	void SetFired(bool isFired) { _isFired = isFired; }

private:
	bool _isFired = false;
	weak_ptr<Bar> _bar;
};

