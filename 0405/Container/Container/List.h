#pragma once

template <typename T>
struct Node
{
	Node(T data) : data(data), next(nullptr), prev(nullptr)
	{

	}

	T data;
	Node<T>* next;
	Node<T>* prev;
};


template<typename T>
class List
{
public:
	class iterator
	{
	public:
		iterator() : ptr(nullptr) {  }
		iterator(Node<T>* ptr) : ptr(ptr) {}
		~iterator() {  }

		// 1. 대입연산자
		iterator& operator=(const iterator& other)
		{
			ptr = other.ptr;

			return *this;
		}
		// 2. 비교연산
		bool operator!=(const iterator& other) const
		{
			return ptr != other.ptr;
		}

		bool operator==(const iterator& other) const
		{
			return ptr == other.ptr;
		}

		// 3. 전위,후위 증감연산자
		iterator operator++(int)
		{
			iterator temp = *this;

			ptr = ptr->next;
			return temp;
		}

		iterator& operator++()
		{
			ptr = ptr->next;
			return *this;
		}

		// 4. 간접연산자
		T& operator*()
		{
			return ptr->data;
		}

	private:
		Node<T>* ptr;
	};

	List()
	{
		_size = 0;
		_head = new Node<T>(T());
		_head->prev = _head;
		_head->next = _head;
	}

	void push_back(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);

		Node<T>* prevNode = _head->prev;
		Node<T>* nextNode = _head;

		newNode->next = nextNode;
		newNode->prev = prevNode;

		prevNode->next = newNode;
		nextNode->prev = newNode;

		_size++;
	}

	void push_front(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);

		Node<T>* prevNode = _head;
		Node<T>* nextNode = _head->next;

		newNode->next = nextNode;
		newNode->prev = prevNode;

		prevNode->next = newNode;
		nextNode->prev = newNode;

		_size++;
	}

	void pop_back()
	{
		Node<T>* target = _head->prev;

		Node<T>* prev = target->prev;
		Node<T>* next = target->next;

		prev->next = next;
		next->prev = prev;

		delete target;
		_size--;
	}

	void pop_front()
	{
		Node<T>* target = _head->next;

		Node<T>* prev = target->prev;
		Node<T>* next = target->next;

		prev->next = next;
		next->prev = prev;

		delete target;
		_size--;
	}

	// 중간 삭제
	void erase(int index)
	{
		Node<T>* target = this->operator[](index);

		Node<T>* prev = target->prev;
		Node<T>* next = target->next;

		prev->next = next;
		next->prev = prev;

		delete target;
		_size--;
	}

	// 중간 삽입
	void insert(Node<T>* before, const T& data)
	{
		Node<T>* newNode = new Node<T>(data);

		Node<T>* prev = before;
		Node<T>* next = before->next;

		prev->next = newNode;
		next->prev = newNode;

		newNode->prev = prev;
		newNode->next = next;

		_size++;
	}

	// 임의접근
	Node<T>* operator[](unsigned int index)
	{
		if (index >= _size)
		{
			int* temp = (int*)0xDEADBEEF;
			*temp = 1;
		}

		Node<T>* start = _head->next;
		for (int i = 0; i < index; i++)
		{
			start = start->next;
		}

		return start;
	}

	int size() { return _size; }
	iterator begin() { return iterator(_head->next); }
	iterator end() { return iterator(_head); }

private:
	int _size;
	Node<T>* _head;
};