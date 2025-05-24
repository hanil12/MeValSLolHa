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

	// 1. v에서 2가 있는지 찾고 그 위치를 찾으세요.(iterator 혹은 index 위치)
	vector<int>::iterator iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		if (*iter == 2)
			break;
	}

	iter = std::find(v.begin(), v.end(), 2);
	cout << *iter << endl;


	// 2. v에서 9보다 큰 수가 있는지 찾고 위치
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter > 9)
			break;
	}

	Comparer comparer;
	comparer.compareNum = 9;
	iter = std::find_if(v.begin(), v.end(), comparer); // pred : 전역함수(함수포인터), 함수객체 => Callable 객체
	cout << *iter << endl;

	comparer.compareNum = 10;
	std::find_if(v.begin(), v.end(), comparer);

	// 3. v에서 모든 수들이 15보다 작은지 bool
	Comparer2 comparer2;
	comparer2.compareNum = 15;
	bool check1 = std::all_of(v.begin(), v.end(), comparer2);
	cout << check1 << endl;

	// 4. v에서 하나라도 2보다 작은 수 있는지 bool
	comparer2.compareNum = 2;
	check1 = std::any_of(v.begin(), v.end(), comparer2);
	cout << check1 << endl;

	// 5. v에서 원소가 2인 원소들의 개수 int
	cout << std::count(v.begin(), v.end(), 2) << endl;

	// 6. v에서 5보다 큰 원소들의 개수 int
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

	// 7. v에서 중복된 원소들 제거

	// 8. v에서 모든 원소들에 x3

	// 9. v에서 데이터가 3인 원소 삭제

	// 10. v에서 10보다 큰 원소들 삭제

	return 0;
}