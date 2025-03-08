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
	// Callable ��ü
	// �Լ�������, �Լ���ü, ���ٽ�(�����Լ�)

	// �����Լ�
	// [ĸ��](����) ->(��ȯ�ڷ���) { �Լ��� }

	vector<int> v{ 21, 32, 13, 1, 2, 5 };

	// 30���� ū ���� ã���ÿ�
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