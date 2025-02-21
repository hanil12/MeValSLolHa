#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include <unordered_map>
#include <set>

using namespace std;

#include "MyVector.h"
#include "MyList.h"

// vector , list�� ����
// 1. list�� �������ٽð�(N), vector�� ��������(���)
// 2. list�� �߰�����(���),  vector�� �߰�����(N)


// iterator
// - C++���� ��� �����̳ʸ� ��ȸ�ϱ� ���ؼ� ���� Ŭ����

int main()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	Vector<int>::iterator iter;
	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	List<int> l;
	l.push_back(10);
	l.push_back(11);
	l.push_back(12);
	l.push_back(13);
	l.push_back(14);

	List<int>::iterator iter2;

	//iter2 = std::find(l.begin(), l.end(), 12);
	//l.insert(iter2, 150);

	iter2 = l.begin();
	for (iter2; iter2 != l.end(); iter2++)
	{
		cout << *iter2 << endl;
	}

	return 0;
}