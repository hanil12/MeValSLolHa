#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;

private:
	// ���� ������
	shared_ptr<VertexBuffer> _vertexBuffer;
	// GPU�� ������ ������ ������� ��
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	// �ǹ��� ����� ������
	shared_ptr<SRV> _srv;
	// �ǹ��� ������ ������
	shared_ptr<SamplerState> _samplerState;
};

