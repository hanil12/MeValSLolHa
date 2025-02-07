#pragma once

class Vector
{
public:
	Vector()
	{}
	~Vector()
	{}

	void reserve(unsigned int capacity)
	{

	}

	void push_back(const int& value)
	{

	}

	void pop_back()
	{
		--_size;
	}

	int operator[](unsigned int index)
	{

	}

private:
	unsigned int _capacity;
	unsigned int _size;

	int* _data; // 배열의 첫번째 주소를 가리키는 포인터
};