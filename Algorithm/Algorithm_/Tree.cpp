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
	{
		Node* node1 = new Node("��Ʈ��");
		rootNode->children.push_back(node1);
		{
			Node* node1_1 = new Node("�Ϸ���Ʈ");
			node1->children.push_back(node1_1);
		}
		{
			Node* node1_1 = new Node("���");
			node1->children.push_back(node1_1);
		}
		{
			Node* node1_1 = new Node("��");
			node1->children.push_back(node1_1);
		}
	}

	// ��ȹ �μ�
	{
		Node* node1 = new Node("��ȹ��");
		rootNode->children.push_back(node1);
		{
			Node* node1_1 = new Node("���丮");
			node1->children.push_back(node1_1);
		}
		{
			Node* node1_1 = new Node("����������");
			node1->children.push_back(node1_1);
		}
		{
			Node* node1_1 = new Node("�뷱��");
			node1->children.push_back(node1_1);
		}
	}

	return rootNode;
}

void PrintTree(Node* node, int depth = 0)
{
	for (int i = 0; i < depth; i++)
		cout << "-";

	cout << node->data << endl;

	for (auto child : node->children)
	{
		PrintTree(child, depth + 1);
	}
}

int main()
{
	Node* root = CreateTree();
	PrintTree(root);

	return 0;
}