#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	void Update() override;
	void Render() override;

	void CreateVertices();

private:
	// Á¤Á¡
	vector<Vertex_Color> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	// vs
	shared_ptr<VertexShader> _vs;
	// ps
	shared_ptr<PixelShader> _ps;
};

