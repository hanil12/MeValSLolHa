#pragma once

template<typename T>
struct Node
{
	Node() {}
	Node(const T& data) : data(data) { }

	T data = 0;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
};

template<typename T>
class List
{
public:
	class iterator
	{
	public:
		iterator() { _ptr = nullptr; }
		iterator(Node<T>* ptr) : _ptr(ptr) {}
		~iterator() { }

		bool operator==(const iterator& other)
		{
			return _ptr == other._ptr;
		}
		bool operator!=(const iterator& other)
		{
			return _ptr != other._ptr;
		}

		iterator operator++(int)
		{
			iterator result;
			result = *this;
			_ptr = _ptr->next;

			return result;
		}
		iterator& operator++()
		{
			_ptr = _ptr->next;
			return *this;
		}
		T& operator*()
		{
			return _ptr->data;
		}

	private:
		Node<T>* _ptr;
	};

	List()
	{
		_head = new Node<T>();
		// 예외처리
		_head->next = _head;
		_head->prev = _head;
	}

	~List()
	{
		int size = _size;
		for (int i = 0; i < size; i++)
		{
			pop_back();
		}

		delete _head;
	}

	void push_back(const T& data)
	{
		// 노드가 Head밖에 없었다.
		// -> prev : head, next : head

		// 노드가 여러개 있었다
		// -> prev : head->prev, next : head

		Node<T>* newNode = new Node<T>(data);

		Node<T>* nextNode = _head;
		Node<T>* prevNode = _head->prev;

		newNode->next = nextNode;
		newNode->prev = prevNode;

		nextNode->prev = newNode;
		prevNode->next = newNode;

		_size++;
	}
	void push_front(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);

		Node<T>* nextNode = _head->next;
		Node<T>* prevNode = _head;

		newNode->next = nextNode;
		newNode->prev = prevNode;

		nextNode->prev = newNode;
		prevNode->next = newNode;

		_size++;
	}

	void pop_back()
	{
		Node<T>* targetNode = _head->prev;

		Node<T>* prev = targetNode->prev;
		Node<T>* next = _head;

		delete targetNode;

		prev->next = next;
		next->prev = prev;

		_size--;
	}

	unsigned int size() { return _size; }

	T& operator[](int index)
	{
		if (index >= size())
		{
			int* temp = (int*)(0xDEADBEEF);
			*temp = 5;
		}

		Node<T>* now = _head->next;

		for (int i = 0; i < index; i++)
		{
			now = now->next;
		}

		return now->data;
	}

	iterator begin() { return iterator(_head->next); }
	iterator end() { return iterator(_head); }

private:
	unsigned int _size = 0;
	Node<T>* _head;
};