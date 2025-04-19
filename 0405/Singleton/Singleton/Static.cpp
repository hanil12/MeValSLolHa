#include <iostream>

using namespace std;

// static 변수
// 스타에서 마린의 공업
// 모든 객체가 atk를 공유하고 있어도 되지않을까?
class Marine
{
public:
	// 멤버함수 호출 조건
	// 1. 소속
	// 2. 객체

	// 정적함수 => 공용함수
	// 객체가 없어도 호출가능한 함수
	// 정적멤버함수는 멤버변수를 접근 불가
	static void Upgrade()
	{
		atk++;
	}

	int Atk()
	{
		return atk;
	}

private:
	int hp = 50;
	static int atk; // 정적멤버변수 => 
};

int Marine::atk = 1;

int main()
{
	Marine* arr[5];

	for (int i = 0; i < 5; i++)
	{
		arr[i] = new Marine();
	}

	// 공업
	Marine::Upgrade();
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i]->Atk() << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		delete arr[i];
	}

	return 0;
}