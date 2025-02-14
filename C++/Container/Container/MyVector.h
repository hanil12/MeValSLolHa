#pragma once

template<typename T>
class Vector
{
public:
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

	void clear()
	{
		_size = 0;
	}

	unsigned int size() { return _size; }
	unsigned int capacity() { return _capacity; }

private:
	unsigned int _capacity;
	unsigned int _size;

	T* _data; // 배열의 첫번째 주소를 가리키는 포인터
};