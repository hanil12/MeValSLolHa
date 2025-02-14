#include "framework.h"
#include "CircleCollider.h"
#include "RectCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
: _radius(radius)
{
	CreateMesh();
	CreateMaterial();

	_transform = make_shared<Transform>();
	_transform->SetPos(center);

	_colorBuffer = make_shared<ColorBuffer>();
	SetGreen();
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
	_transform->Update();
	_colorBuffer->Update();
}

void CircleCollider::Render()
{
	_vs->IASetInputLayout();
	_transform->SetVS(0);
	_colorBuffer->SetPS(0);

	_vertexBuffer->IASet(0);

	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

	_vs->VSSet();
	_ps->PSSet();

	DC->Draw(_vertices.size(), 0);
}

bool CircleCollider::IsCollision(Vector pos)
{
	Vector v = pos - GetWorldCenter();

	return v.Length() < GetWorldRadius();
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	Vector v = other->GetWorldCenter() - GetWorldCenter();

	return v.Length() < GetWorldRadius() + other->GetWorldRadius();
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	return other->IsCollision(shared_from_this());
}

void CircleCollider::CreateMesh()
{
	int verticesCount = 36;
	float theta = 2 * PI / verticesCount;

	for (int i = 0; i < verticesCount + 1; i++)
	{
		Vertex v;
		v.pos.x = _radius * cosf(theta * i);
		v.pos.y = _radius * sinf(theta * i);
		v.pos.z = 0.0f;

		_vertices.push_back(v);
	}

    _vertexBuffer = make_shared<VertexBuffer>(&_vertices[0], sizeof(Vertex), _vertices.size(), 0);
}

void CircleCollider::CreateMaterial()
{
	_vs = make_shared<VertexShader>(L"Shaders/ColliderVertexShader.hlsl");
	_ps = make_shared<PixelShader>(L"Shaders/ColliderPixelShader.hlsl");
}
