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
		cout << "�⺻ ������ ȣ��" << endl;
	}
	Player(int hp)
	: pet(new Pet())
	{
		cout << "Ÿ�� ��ȯ ������ ȣ��" << endl;
	}

	Player(const Player& other)
	: pet(new Pet(*other.pet))
	{
		cout << "���� ������ ȣ��" << endl;
	}

	Player(Player&& other) noexcept
	: pet(other.pet)
	{
		other.pet = nullptr;
		cout << "�̵� ������ ȣ��" << endl;
	}

	Pet* pet;
	int hp = 1;
};

// lvalue, rvaule
// lvalue : ������(����), ������ �� �ִ� ��
// rvalue : ������ �ƴ� ���, ���

// �ڷ���&& : ����������

// �Ű�����(Player p)
// - ���������� �Ұ���
// - ������ ȣ���� �ȴ�.

// �Ű�����(Player* p)
// - �������� ����
// - ������ ȣ��X
// - ���� ��ƴ�.

// �Ű�����(Player& p)
// - �������� ����
// - ������ ȣ��X
// - ���� ����.

void PrintPlayer(Player p)
{
	p.hp = 123;
	// p�� ������ ���� ���� ��
}

// �Ű����� p�� �����⸸ ���� ��ϱ� �������� ���� ��������.
void PrintPlayer(Player&& p)
{
	// �������� ����
	// ������ ȣ�� X
	// p�� ������ ���� ���� ��
}

int main()
{
	Player p;
	Player p2(std::move(p));

	unique_ptr<Player> ptr1 = make_unique<Player>();
	unique_ptr<Player> ptr2 = std::move(ptr1);

	return 0;
}