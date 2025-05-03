#pragma once

struct Node
{
	Node(int data) : data(data), next(nullptr), prev(nullptr)
	{

	}

	int data;
	Node* next;
	Node* prev;
};

class List
{
public:
	List()
	{
		_size = 0;
		_head = new Node(-1);
		_head->prev = _head;
		_head->next = _head;
	}

	void push_back(const int& data)
	{
		Node* newNode = new Node(data);

		Node* prevNode = _head->prev;
		Node* nextNode = _head;

		newNode->next = nextNode;
		newNode->prev = prevNode;

		prevNode->next = newNode;
		nextNode->prev = newNode;

		_size++;
	}

	void push_front(const int& data)
	{

	}

	void pop_back()
	{

	}

	void pop_front()
	{

	}

	// 중간 삭제
	void erase(int index)
	{

	}

	// 중간 삽입
	void insert(const int& data)
	{

	}

	// 임의접근
	Node* operator[](unsigned int index)
	{

	}

private:
	int _size;
	Node* _head;
};