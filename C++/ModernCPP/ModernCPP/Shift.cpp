#include <iostream>

using namespace std;

class Pet
{

};

// C++ 11
class Player
{
public:
	Player()
	: pet(new Pet())
	{
		cout << "기본 생성자 호출" << endl;
	}
	Player(int hp)
	: pet(new Pet())
	{
		cout << "타입 변환 생성자 호출" << endl;
	}

	Player(const Player& other)
	: pet(new Pet(*other.pet))
	{
		cout << "복사 생성자 호출" << endl;
	}

	Player(Player&& other) noexcept
	: pet(other.pet)
	{
		other.pet = nullptr;
		cout << "이동 생성자 호출" << endl;
	}

	Pet* pet;
	int hp = 1;
};

// lvalue, rvaule
// lvalue : 좌측값(참조), 수정할 수 있는 식
// rvalue : 좌측값 아닌 얘들, 상수

// 자료형&& : 우측값참조

// 매개변수(Player p)
// - 원본수정이 불가능
// - 생성자 호출이 된다.

// 매개변수(Player* p)
// - 원본수정 가능
// - 생성자 호출X
// - 쓰기 어렵다.

// 매개변수(Player& p)
// - 원본수정 가능
// - 생성자 호출X
// - 쓰기 쉽다.

void PrintPlayer(Player p)
{
	p.hp = 123;
	// p는 어차피 쓰고 버릴 얘
}

// 매개변수 p는 껍데기만 남길 얘니까 마구잡이 쓰고 버리세요.
void PrintPlayer(Player&& p)
{
	// 원본수정 가능
	// 생성자 호출 X
	// p는 어차피 쓰고 버릴 얘
}

int main()
{
	Player p;
	Player p2(std::move(p));

	unique_ptr<Player> ptr1 = make_unique<Player>();
	unique_ptr<Player> ptr2 = std::move(ptr1);

	return 0;
}