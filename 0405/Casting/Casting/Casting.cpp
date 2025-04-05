#include <iostream>

using namespace std;

// 1. UP Casting, DOWN Casting
// 2. C++ 캐스팅 4총사
// - static cast
// - dynamic cast
// - const cast
// - reinterpret cast

// int -> float (안전)
// float -> int (불안전)

// Knight -> Player (업캐스팅) 안전
// Player -> Knight (다운캐스팅) 불안전

// 캐스팅
// - static cast : 논리적으로 괜찮으면 OK
// - dynamic cast : 실패하면 nullptr 반환
//  => 동적바인딩을 하기 때문에 가상함수 테이블이 없으면 쓰지못한다.


// - const cast : const를 붙히거나 뗄 때

// reinterpret cast : 재해석, 자료형을 그냥 무조건 강제로 바꾸는 cast
class Player
{
public:
	virtual void Hello() { cout << "Hello" << endl; }
};

class Knight : public Player
{
public :
	virtual void Hello() { cout << "Hello Knight";  };
	void HelloKnight() { cout << "Hello K" << endl; }
};

int main()
{
	Player* p = static_cast<Player*>( new Knight());
	Knight* p2 = reinterpret_cast<Knight*>(p);
	

	Knight* k = dynamic_cast<Knight*>(p);
	k->HelloKnight();

	return 0;
}