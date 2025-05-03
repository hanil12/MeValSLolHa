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

// ----------------------------------------------------
// vector의 장점
// 1. 임의접근,인덱스 연산[]이 상수(항상 같다)이다. 

// vector의 단점
// 1. 처음 삽입 삭제 혹은 중간 삽입 삭제 시 N만큼의 시간복잡도를 갖는다.
// --------------------------------------------------

// --------------------------------------------------
// list의 장점
// 1. 중간 삽입, 처음 삽입이 상수.
//
// list의 단접
// 1. 임의접근,인덱스 연산[]이 N만큼의 시간복잡도를 갖는다.
// --------------------------------------------------

int main()
{

#pragma region Vector
	//Vector v;

	//v.reserve(1000);
	////v.resize(1000, -1);
	//
	//for (int i = 0; i < 1000; i++)
	//{
	//	v.push_back(i);

	//	cout << "수용량 : " << v.capacity() << endl;
	//	cout << "사이즈 : " << v.size() << endl;
	//	cout << " ------ " << endl;
	//}

	//v.clear();
	//cout << "수용량 : " << v.capacity() << endl;
	//cout << "사이즈 : " << v.size() << endl;

	//vector<int>().swap(v); // 무명변수, 임시객체

	//cout << "수용량 : " << v.capacity() << endl;
	//cout << "사이즈 : " << v.size() << endl;
#pragma endregion

	list<int> l;
	l.push_back(0);
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.push_front(5);
	l.push_front(-1);

	

	return 0;
}