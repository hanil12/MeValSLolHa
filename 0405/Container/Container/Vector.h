#pragma once

class Vector
{
public:
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
		int* newData = new int[newCapacity];

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

	void push_back(const int& value)
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

	int& operator[](unsigned int index)
	{
		if (index >= _size)
		{
			int* temp = (int*)0xDEADBEEF;
			*temp = 1;
		}

		return _data[index];
	}

private:
	int _size;
	int _capacity;

	int* _data;
};