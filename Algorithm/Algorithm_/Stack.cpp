#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// FILO : First Input Last Out
// 1. Stack ����
// 2. Stack�� �̿��ؼ� RightHand �����غ���


template <typename T>
class Stack
{

};

int main()
{
	stack<int> s;

	s.push(5);
	s.push(1);
	s.push(3);
	s.push(10);
	s.push(11);

	while (true)
	{
		if (s.empty())
			break;

		cout << s.top() << endl;

		s.pop();
	}

	return 0;
}