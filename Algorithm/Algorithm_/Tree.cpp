#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// Ʈ��
// - ���������� ��Ÿ���� ������ �ڷᱸ��
// - Parent, Children
// - Root�� �� �ϳ�
// - Ʈ�� �ȿ� ����Ʈ���� �����Ѵ�. => Ʈ���� �߶� Ʈ�� => ���ȣ���� �̿��Ͽ� Ʈ���� ��ȸ�� �� �ִ�.

struct Node
{
	Node(string data) : data(data)
	{}

	string data;
	//Node* parent
	vector<Node*> children;
};

Node* CreateTree()
{
	Node* rootNode = new Node("���ߺ�");

	// ���α׷��� �μ�
	{
		Node* node1 = new Node("���α׷�����");
		rootNode->children.push_back(node1);
		{
			Node* node1_1 = new Node("Ŭ���̾�Ʈ");
			node1->children.push_back(node1_1);
		}
		{
			Node* node1_1 = new Node("����");
			node1->children.push_back(node1_1);
		}
		{
			Node* node1_1 = new Node("����");
			node1->children.push_back(node1_1);
		}
	}

	// ��Ʈ �μ�

	// ��ȹ �μ�

	return rootNode;
}

int main()
{
	Node* root = CreateTree();

	return 0;
}