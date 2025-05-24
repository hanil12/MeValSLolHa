#pragma once

template <typename T>
class Vector
{
public:
	class iterator
	{
	public:
		iterator() : _ptr(nullptr) {}
		iterator(T* data) : _ptr(data) {}
		~iterator() = default;

		iterator& operator=(const iterator& other)
		{
			_ptr = other._ptr;

			return *this;
		}

		bool operator!=(const iterator& other) const
		{
			return _ptr != other._ptr;
		}
		bool operator==(const iterator& other) const
		{
			return _ptr == other._ptr;
		}

		// 3. 전위,후위 증감연산자
		iterator operator++(int)
		{
			iterator result;
			result = *this;

			_ptr++;

			return result;
		}

		iterator& operator++()
		{
			_ptr++;
			return *this;
		}

		// 4. 간접연산자
		T& operator*()
		{
			return *_ptr;
		}

	private:
		T* _ptr;
	};

	Vector() : _data(nullptr), _size(0), _capacity(0) { }
	~Vector()
	{
		delete _data;
	}

	void reserve(const int newCapacity)
	{
		if (newCapacity <= _capacity)
			return;

		_capacity = newCapacity;

		// 생성
		T* newData = new T[newCapacity];

		// 복사
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		// 삭제 후 _data설정
		if(_data != nullptr)
			delete[] _data;
		_data = newData;
	}

	void push_back(const T& value)
	{
		// 꽉찬 상황
		if (_size == _capacity)
		{
			int newCapacity = _capacity * 1.5f;
			if (newCapacity <= 1)
			{
				newCapacity++;
			}

			reserve(newCapacity);
		}

		_data[_size] = value;
		_size++;
	}

	void pop_back()
	{
		--_size;
	}

	void clear()
	{
		_size = 0;
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

	T& operator[](unsigned int index)
	{
		if (index >= _size)
		{
			int* temp = (int*)0xDEADBEEF;
			*temp = 1;
		}

		return _data[index];
	}

	iterator begin() { return iterator(_data); }
	iterator end() { return iterator(_data + _size); }

private:
	int _size;
	int _capacity;

	T* _data;
};