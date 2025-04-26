#pragma once

class Vector
{
public:
	void reserve(int capacity)
	{

	}

	void push_back(const int& value)
	{

	}

	int size() { return _size; }
	int capacity() { return _capacity; }

	int& operator[](unsigned int index)
	{
		return _data[index];
	}

private:
	int _size;
	int _capacity;

	int* _data;
};