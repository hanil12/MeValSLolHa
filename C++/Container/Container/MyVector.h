#pragma once

template<typename T>
class Vector
{
public:
	class iterator
	{
	public:
		iterator() { _ptr = nullptr; }
		iterator(T* ptr) : _ptr(ptr) {}
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
			_ptr++;

			return result;
		}
		iterator& operator++()
		{
			_ptr++;
			return *this;
		}
		T& operator*()
		{
			return *_ptr;
		}

	private:
		T* _ptr;
	};

	Vector()
	{}
	~Vector()
	{
		_capacity = 0;
		_size = 0;
		delete[] _data;
	}

	void reserve(unsigned int capacity)
	{
		_capacity = capacity;

		T* oldData = _data;

		// 새롭게 재할당
		_data = new T[_capacity];

		// 복사
		for (int i = 0; i < _size; i++)
		{
			_data[i] = oldData[i];
		}

		// 전 데이터 삭제
		if(oldData != nullptr)
			delete[] oldData;
	}
	void push_back(const T& value)
	{
		// 꽉 차 있었다
		if (_capacity == _size)
		{
			int newCapacity = 1.5f * _capacity;

			if (newCapacity <= 1)
				newCapacity++;

			reserve(newCapacity);
		}

		// 꽉 안차있는 상황
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

	T& operator[](unsigned int index)
	{
		if (index >= _size)
		{
			int* temp = (int*)(0xDEADBEEF);
			*temp = 5;

			T t;
			return t;
		}

		return _data[index];
	}
	unsigned int size() { return _size; }
	unsigned int capacity() { return _capacity; }

	iterator begin() { return iterator(_data); }
	iterator end() { return iterator(&_data[_size]); }

private:
	unsigned int _capacity;
	unsigned int _size;

	T* _data; // 배열의 첫번째 주소를 가리키는 포인터
};