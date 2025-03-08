#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Finder
{
	bool operator()(const int& element)
	{
		if (element > 30)
			return true;
		return false;
	}
};

int main()
{
	// Callable 객체
	// 함수포인터, 함수객체, 람다식(무명함수)

	// 람다함수
	// [캡쳐](원소) ->(반환자료형) { 함수식 }

	vector<int> v{ 21, 32, 13, 1, 2, 5 };

	// 30보다 큰 수를 찾으시오
	Finder finder;

	int compareNum = 30;
	auto iter = std::find_if(v.begin(), v.end(), [&compareNum](const int& element) -> bool
		{
			if (element > compareNum)
				return true;
			return false;
		});


	return 0;
}