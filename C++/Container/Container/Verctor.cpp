#include <iostream>
#include <vector>

using namespace std;

// vector
// - 동적배열, 가변배열

// Heap 영역에 할당
// => 수용량이 부족하면
// 1. 생성
// 2. 복사
// 3. 기존 배열을 삭제

int main()
{
	vector<int> v;

	v.reserve(1000);
	//v.resize(1000);

	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
		cout << "vector의 크기" << v.size() << " / vector의 수용량" << v.capacity() << endl;
	}

	cout << "---------" << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	v.clear();

	vector<int>().swap(v); // 임시객체


	return 0;
}