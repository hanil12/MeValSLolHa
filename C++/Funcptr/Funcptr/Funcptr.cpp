#include <iostream>

using namespace std;

// 함수 포인터
void HelloWorld()
{
	cout << "Hello World!" << endl;
}

void HelloCPP()
{
	cout << "Hello CPP" << endl;
}

void PrintInt(int a)
{
	cout << a << endl;
}

void(*funcPtr)(void);
void(*funcPtr2)(int);

typedef unsigned int MYINT;
typedef void(*FUNC)(void);

class Pet
{
public:
	// 멤버함수 호출 조건
	// 1. 어디 산하에 있는지
	// 2. 객체
	void Attack() { cout << "멍멍!!" << endl; }
	void Attack2() { cout << "왈왈!!" << endl; }
};

typedef void(Pet::* PetFunc)(void);
void(Pet::* petFunc)(void);

class Player
{
public:
	void Attack(Pet* pet)
	{
		if (_petFunc != nullptr)
			((*pet).*_petFunc)();

		cout << "Player Attack!!!" << endl;
	}

	void SetPetFunc(PetFunc func) { _petFunc = func; } // 콜백함수 설정

private:
	PetFunc _petFunc;
};

int main()
{
	FUNC myFunc = &HelloWorld;

	funcPtr = &HelloWorld;
	funcPtr();

	funcPtr = &HelloCPP;
	funcPtr();

	funcPtr2 = &PrintInt;
	funcPtr2(5);

	Pet pet;
	Player p;

	p.SetPetFunc(&Pet::Attack);
	p.SetPetFunc(&Pet::Attack10000);
	p.Attack(&pet);

	// 변심 => 나중에 다른 함수로 바꿀수도 있다.
	// => 나중에 다른 함수를 호출할 수 있다.
	// ==> 콜백함수 : 나중에 다른 함수를 호출하는게 가능하다.
	// C++ : 인자(매개변수)로 함수포인터를 넘겨서 다른 함수로 설정할 수 있도록 하는 것.
	p.SetPetFunc(&Pet::Attack2);
	p.Attack(&pet);

	return 0;
}