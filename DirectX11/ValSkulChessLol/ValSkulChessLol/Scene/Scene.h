#pragma once
class Scene
{
public:
	Scene() {}
	virtual ~Scene() {}

	// Collider
	virtual void PreUpdate() {}

	virtual void Update() abstract;
	virtual void Render() abstract;

	virtual void PostRender() {}
};

