#pragma once

struct Node
{
	Node() {}
	Node(const int& data) : data(data) { }

	int data = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class List
{
public:
	List()
	{
		_head = new Node();
		// 예외처리
		_head->next = _head;
		_head->prev = _head;
	}

	~List()
	{
		// TODO
	}

	void push_back(const int& data)
	{
		// 노드가 Head밖에 없었다.
		// -> prev : head, next : head

		// 노드가 여러개 있었다
		// -> prev : head->prev, next : head

		Node* newNode = new Node(data);

		Node* nextNode = _head;
		Node* prevNode = _head->prev;

		newNode->next = nextNode;
		newNode->prev = prevNode;

		nextNode->prev = newNode;
		prevNode->next = newNode;

		_size++;
	}
	void push_front(const int& data)
	{
		Node* newNode = new Node(data);

		Node* nextNode = _head->next;
		Node* prevNode = _head;

		newNode->next = nextNode;
		newNode->prev = prevNode;

		nextNode->prev = newNode;
		prevNode->next = newNode;

		_size++;
	}

	unsigned int size() { return _size; }

	int operator[](int index)
	{
		if (index >= size())
			return -1; // ERROR

		Node* now = _head->next;

		for (int i = 0; i < index; i++)
		{
			now = now->next;
		}

		return now->data;
	}

private:
	unsigned int _size = 0;
	Node* _head;
};