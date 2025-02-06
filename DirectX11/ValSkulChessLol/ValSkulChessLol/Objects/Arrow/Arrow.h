#pragma once
class Arrow
{
public:
	Arrow();
	~Arrow();

	void Update();
	void Render();

	void SetDir(Vector dir);
	void SetPos(Vector pos);
	void SetAngle(float angle) { _arrow->GetTransform()->SetAngle(angle); }
	void SetActive(bool active) { _isActive = active; }
	bool GetActive() { return _isActive; }

;private:
	float _lifeTime = 3.0f;
	float _time = 0.0f;

	bool _isActive = false;
	Vector _arrowDir = Vector(0, 0);
	float _arrowSpeed = 0.1f;
	shared_ptr<Quad> _arrow;
};

