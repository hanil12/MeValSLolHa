#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool Compare(int value)
{
	if (value > 9)
		return true;
	return false;
}

struct Comparer
{
	bool operator()(int value)
	{
		if (value > compareNum)
			return true;
		return false;
	}

	int compareNum;
};

struct Comparer2
{
	bool operator()(int value)
	{
		if (value < compareNum)
			return true;
		return false;
	}

	int compareNum;
};

int main()
{
	vector<int> v = { 10, 1, 2, 4, 3 , 5, 7, 2 };

	// 1. v���� 2�� �ִ��� ã�� �� ��ġ�� ã������.(iterator Ȥ�� index ��ġ)
	vector<int>::iterator iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		if (*iter == 2)
			break;
	}

	iter = std::find(v.begin(), v.end(), 2);
	cout << *iter << endl;


	// 2. v���� 9���� ū ���� �ִ��� ã�� ��ġ
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter > 9)
			break;
	}

	Comparer comparer;
	comparer.compareNum = 9;
	iter = std::find_if(v.begin(), v.end(), comparer); // pred : �����Լ�(�Լ�������), �Լ���ü => Callable ��ü
	cout << *iter << endl;

	comparer.compareNum = 10;
	std::find_if(v.begin(), v.end(), comparer);

	// 3. v���� ��� ������ 15���� ������ bool
	Comparer2 comparer2;
	comparer2.compareNum = 15;
	bool check1 = std::all_of(v.begin(), v.end(), comparer2);
	cout << check1 << endl;

	// 4. v���� �ϳ��� 2���� ���� �� �ִ��� bool
	comparer2.compareNum = 2;
	check1 = std::any_of(v.begin(), v.end(), comparer2);
	cout << check1 << endl;

	// 5. v���� ���Ұ� 2�� ���ҵ��� ���� int
	cout << std::count(v.begin(), v.end(), 2) << endl;

	// 6. v���� 5���� ū ���ҵ��� ���� int
	struct Count_If
	{
		bool operator()(int element)
		{
			if (element > compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	Count_If comparer3;
	comparer3.compareNum = 5;
	cout << std::count_if(v.begin(), v.end(), comparer3) << endl;

	// 7. v���� �ߺ��� ���ҵ� ����

	// 8. v���� ��� ���ҵ鿡 x3

	// 9. v���� �����Ͱ� 3�� ���� ����

	// 10. v���� 10���� ū ���ҵ� ����

	return 0;
}