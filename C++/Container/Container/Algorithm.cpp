#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool FindFunc(int value)
{
	if (value > 15)
		return true;
	return false;
}

int main()
{
	vector<int> v;

	v = { 5, 1, 3, 112, 10, 9, 50, 30 };

	// 1.  1�� �ִ��� ã���ּ���. �׸��� index�� Ȥ�� iterator�ڸ��� ã���ּ���
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter == 1)
			break;
	}

	iter = std::find(v.begin(), v.end(), 0);
	if (iter == v.end())
	{
		cout << "��ã�ҽ��ϴ�." << endl;
	}
	else
	{
		cout << *iter << endl;
	}

	// 2.  15���� ū ���� �ִ��� ã���ּ���. �׸��� iterator �ڸ��� ã���ּ���.(iter, algorithm)
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter > 15)
			break;
	}

	// pred : bool <vector�� ���� �ڷ���>

	struct FindFunctor
	{
		bool operator()(int value)
		{
			if (value > compareNum)
				return true;
			return false;
		}

		int compareNum = 0;
	};

	FindFunctor functor;
	functor.compareNum = 20;
	iter = std::find_if(v.begin(), v.end(), functor); // �Լ���ü, Ȥ�� �Լ������� ... Callable ��ü
	if (iter != v.end())
		cout << *iter << endl;

	// 3. ��� ���� 50���� ������ bool���� �˷��ּ���. (iter, algorithm)

	// 4. �ϳ��� 30���� ū ���� �ִ��� bool���� �˷��ּ���. (iter, algorithm)

	// 5. ���Ұ� 3�� ���ҵ��� ������ �˷��ּ���. algorithm

	// 6. ���Ұ� 5���� ū ���ҵ��� ������ �˷��ּ���. algorithm

	// 7. ��� ���ҿ� 3�� �����ּ���. algorithm

	// 8. �ߺ��� ���ҵ��� '����'���ּ���. algorithm

	// 9. ���Ұ� 11�� ���Ҹ� �����ּ���. iter, algorithm

	// 10. ���Ұ� 10���� ���� ���ҵ��� �����ּ���. algorithm
}