#include <iostream>

using namespace std;

#include "MyVector.h"

// vector , list�� ����
// 1. list�� �������ٽð�(N), vector�� ��������(���)
// 2. list�� �߰�����(���),  vector�� �߰�����(N)

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