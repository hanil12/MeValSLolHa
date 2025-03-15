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
	Player() { cout << "기본생성자 호출" << endl; }
	Player(int hp) { cout << "타입변환 생성자 호출" << endl; }
	~Player() { cout << "소멸자 호출" << endl; }

	void Attack()
	{
		cout << "Attack!!" << endl;

		if(target.expired() == false)
			target.lock()->hp -= atk;
	}

	// 물고있다.
	weak_ptr<Player> target;

	int hp = 1;
	int atk = 2;
};

// shared_ptr
// - ptr
// - refCountBlock : 객체가 참조된 횟수를 카운트

int main()
{
	shared_ptr<Player> ptr1 = make_shared<Player>();
	shared_ptr<Player> ptr2 = make_shared<Player>();

	// shared_ptr의 순환참조 => weak_ptr로 풀 수 있다.
	ptr1->target = ptr2;
	ptr2->target = ptr1;
	ptr1->Attack();
	ptr2->Attack();

	return 0;
}