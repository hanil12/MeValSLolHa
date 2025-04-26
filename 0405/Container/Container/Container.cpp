#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "Vector.h"

// 정적배열 vs 동적배열
// 정적배열
// - 선언 후 사이즈 변경 불가
// 동적배열
// - 실행 중 재할당(새로 배열을 만들고 -> 복사하고 -> 삭제) 하면서 크기 변경 가능

// vector와 list에 대해서 조사해보고 비교

int main()
{
	Vector v;

	v.reserve(1000);
	//v.resize(1000, -1);
	
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);

		cout << "수용량 : " << v.capacity() << endl;
		cout << "사이즈 : " << v.size() << endl;
		cout << " ------ " << endl;

	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}


	return 0;
}