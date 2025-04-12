#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// 트리
// - 계층구조를 나타내기 용이한 자료구조
// - Parent, Children
// - Root는 단 하나
// - 트리 안에 서브트리가 존재한다. => 트리는 잘라도 트리 => 재귀호출을 이용하여 트리를 순회할 수 있다.

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
	Node* rootNode = new Node("개발부");

	// 프로그래밍 부서
	{
		Node* node1 = new Node("프로그래밍팀");
		rootNode->children.push_back(node1);
		{
			Node* node1_1 = new Node("클라이언트");
			node1->children.push_back(node1_1);
		}
		{
			Node* node1_1 = new Node("서버");
			node1->children.push_back(node1_1);
		}
		{
			Node* node1_1 = new Node("엔진");
			node1->children.push_back(node1_1);
		}
	}

	// 아트 부서

	// 기획 부서

	return rootNode;
}

int main()
{
	Node* root = CreateTree();

	return 0;
}