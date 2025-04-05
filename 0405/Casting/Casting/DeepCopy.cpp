#include <iostream>

using namespace std;

class Pet
{
public:
	Pet() { cout << "Pet 생성" << endl; }
	Pet(const Pet& other) { cout << "Pet의 복사 생성" << endl; }
	~Pet() { cout << "Pet 소멸" << endl; }
};

class Player
{
public:
	// 기본생성자 : 암묵적으로 만들어줌
	Player()
	{
		_pet = new Pet();
	}

	// 복사생성자 : 암묵적으로 만들어줌 => 얕은 복사 생성자
	// 깊은 복사 : 내부에서 생성하고 지울 때, 복사생성자도 같이 생성해줘야한다.
	Player(const Player& other)
	{
		_pet = new Pet(*other._pet); // 깊은 복사
	}

	~Player()
	{
		delete _pet;
	}

private:
	Pet* _pet;
};


int main()
{
	Player* p = new Player();
	Player* p2 = new Player(*p);

	delete p;
	delete p2;

	return 0;
}