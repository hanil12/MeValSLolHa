#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// 1. auto
//  - 무조건 선언과 동시에 초기화
//  - 많이 남발하면 가독성이 떨어질 수 있다.
// 
// 2. 중괄호 초기화
// 3. enum, enum class
// 4. 범위기반 for문
// 5. class의 빠른 초기화
// 6. using
//  - template이랑 호환이 가능하다.
// 
// 7. 람다식
// 
// 8. 이동생성자, std::move
// 9. 스마트포인터

struct Vector
{
	int x = 1;
	int y = 1;
};

enum class State
{
	IDLE,
	RUN,
	WALK
};

enum class PetState
{
	IDLE,
	RUN
};

typedef void(*FN)(void);
using MyFunc = void(*)(void);

int main()
{
	int aInt = static_cast<int>(State::IDLE);
	Vector v1 = { 5,10 };

	unordered_map<string, int> um;
	um["HI"] = 1;
	um["JM"] = 2;
	um["GS"] = 3;
	um["D"] = 4;

	auto iter = um.begin();

	for (iter; iter != um.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}

	for (auto& p : um)
	{
		p.second = 10100;
		cout << p.first << " " << p.second << endl;
	}

	//vector<int> v { 1,2,3,4,5,6 };
	//for (const int& element : v)
	//{
	//	cout << element << endl;
	//}

	return 0;
}