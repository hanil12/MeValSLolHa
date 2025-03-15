#include <iostream>
#include <memory>

using namespace std;

struct RefCountBlock
{
	int refCount = 1;
};

template<typename T>
class Shared_Ptr
{
public:
	Shared_Ptr(T* ptr) : _block(nullptr), _ptr(ptr)
	{
		_block = new RefCountBlock();
		if (ptr == nullptr)
			_block->refCount = 0;

		cout << "RefCount : " << _block->refCount << endl;
	}

	Shared_Ptr(const Shared_Ptr<T>& other)
	: _ptr(other._ptr)
	, _block(other._block)
	{
		if (_ptr != nullptr)
		{
			_block->refCount++;
			cout << "RefCount : " << _block->refCount << endl;
		}
	}

	~Shared_Ptr()
	{
		if (_ptr != nullptr)
		{
			_block->refCount--;
			cout << "RefCount : " << _block->refCount << endl;

			if (_block->refCount == 0)
			{
				delete _block;
				delete _ptr;
				_ptr = nullptr;
			}
		}
	}

	Shared_Ptr<T>& operator=(const Shared_Ptr<T>& other)
	{
		_ptr = other->_ptr;
		_block = other->_block;

		if (_ptr != nullptr)
		{
			_block->refCount++;
			cout << "RefCount : " << _block->refCount << endl;
		}

		return *this;
	}

	T* operator->()
	{
		if (_ptr != nullptr)
			return _ptr;
		return nullptr;
	}

private:
	T* _ptr;
	RefCountBlock* _block;
};

class Player
{
public:
	Player() { cout << "�⺻������ ȣ��" << endl; }
	Player(int hp) { cout << "Ÿ�Ժ�ȯ ������ ȣ��" << endl; }
	~Player() { cout << "�Ҹ��� ȣ��" << endl; }

	void Attack()
	{
		cout << "Attack!!" << endl;

		if(target.expired() == false)
			target.lock()->hp -= atk;
	}

	// �����ִ�.
	weak_ptr<Player> target;

	int hp = 1;
	int atk = 2;
};

// shared_ptr
// - ptr
// - refCountBlock : ��ü�� ������ Ƚ���� ī��Ʈ

int main()
{
	shared_ptr<Player> ptr1 = make_shared<Player>();
	shared_ptr<Player> ptr2 = make_shared<Player>();

	// shared_ptr�� ��ȯ���� => weak_ptr�� Ǯ �� �ִ�.
	ptr1->target = ptr2;
	ptr2->target = ptr1;
	ptr1->Attack();
	ptr2->Attack();

	return 0;
}