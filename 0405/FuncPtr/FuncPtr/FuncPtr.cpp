#include <iostream>

using namespace std;

// FuncPtr
// 함수도 어딘가에는 저장되어있을 것이다.
// => 함수를 이 저장되어있는 곳을 알면 호출할 수 있다.

// => 함수포인터를 선언해놓고, 다른 함수를 상황에 맞게 돌려서 쓸 수 있다.

// 콜백함수
// 함수를 인자로 전달해서 나중에 호출할 수 있는

void(*funcPtr)(void);
int(*funcPtr2)(int, int);

// 자료형 정의
class Pet;
typedef unsigned int UINT;
typedef int(*Func)(int, int);
typedef void(Pet::*PetFunc)(void);

void HelloWorld()
{
	cout << "Hello World!" << endl;
}

int Add(int a, int b)
{
	return a + b;
}

class Pet
{
public:
	void Attack() { cout << "Pet Attack!!!" << endl; }
	void Bark() { cout << "왈왈!!" << endl; }
};

class Player
{
public:
	void SetFunc(PetFunc func) { _func = func; }
	void Attack(Pet* pet)
	{
		if (_func != nullptr && pet != nullptr)
			(pet->*_func)();

		cout << "Player Attack!!" << endl;
	}
private:
	PetFunc _func;
};

int main()
{
	UINT temp = 1;
	Pet* pet = new Pet();
	Player* player = new Player();

	Func func = &Add;
	funcPtr = &HelloWorld;
	funcPtr2 = &Add;
	PetFunc myFunc = &Pet::Attack;

	funcPtr();
	cout << funcPtr2(1, 2) << endl;
	cout << func(1, 2) << endl;
	(pet->*myFunc)();

	player->SetFunc(&Pet::Attack);
	player->Attack(pet);

	player->SetFunc(&Pet::Bark);
	player->Attack(pet);

	player->SetFunc(nullptr);
	player->Attack(pet);

	delete player;
	delete pet;

	return 0;
}