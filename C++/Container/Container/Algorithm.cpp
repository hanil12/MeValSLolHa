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

	// 1.  1이 있는지 찾아주세요. 그리고 index나 혹은 iterator자리를 찾아주세요
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter == 1)
			break;
	}

	iter = std::find(v.begin(), v.end(), 0);
	if (iter == v.end())
	{
		cout << "못찾았습니다." << endl;
	}
	else
	{
		cout << *iter << endl;
	}

	// 2.  15보다 큰 수가 있는지 찾아주세요. 그리고 iterator 자리를 찾아주세요.(iter, algorithm)
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter > 15)
			break;
	}

	// pred : bool <vector의 원소 자료형>

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
	iter = std::find_if(v.begin(), v.end(), functor); // 함수객체, 혹은 함수포인터 ... Callable 객체
	if (iter != v.end())
		cout << *iter << endl;

	// 3. 모든 수가 50보다 작은지 bool으로 알려주세요. (iter, algorithm)

	// 4. 하나라도 30보다 큰 수가 있는지 bool으로 알려주세요. (iter, algorithm)

	// 5. 원소가 3인 원소들의 개수를 알려주세요. algorithm

	// 6. 원소가 5보다 큰 원소들의 개수를 알려주세요. algorithm

	// 7. 모든 원소에 3을 곱해주세요. algorithm

	// 8. 중복된 원소들을 '제거'해주세요. algorithm

	// 9. 원소가 11인 원소를 지워주세요. iter, algorithm

	// 10. 원소가 10보다 작은 원소들을 지워주세요. algorithm
}