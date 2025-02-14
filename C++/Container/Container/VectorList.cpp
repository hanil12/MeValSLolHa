#include <iostream>

using namespace std;

#include "MyVector.h"

// vector , list의 차이
// 1. list의 임의접근시간(N), vector의 임의접근(상수)
// 2. list의 중간삽입(상수),  vector의 중간삽입(N)

int main()
{
	Vector<int> v;
	// iterator

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}