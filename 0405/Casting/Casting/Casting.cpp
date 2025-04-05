#include <iostream>

using namespace std;

// 1. UP Casting, DOWN Casting
// 2. C++ ĳ���� 4�ѻ�
// - static cast
// - dynamic cast
// - const cast
// - reinterpret cast

// int -> float (����)
// float -> int (�Ҿ���)

// Knight -> Player (��ĳ����) ����
// Player -> Knight (�ٿ�ĳ����) �Ҿ���

// ĳ����
// - static cast : �������� �������� OK
// - dynamic cast : �����ϸ� nullptr ��ȯ
//  => �������ε��� �ϱ� ������ �����Լ� ���̺��� ������ �������Ѵ�.


// - const cast : const�� �����ų� �� ��

// reinterpret cast : ���ؼ�, �ڷ����� �׳� ������ ������ �ٲٴ� cast
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