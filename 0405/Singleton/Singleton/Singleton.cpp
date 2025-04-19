#include <iostream>

using namespace std;

// Singleton
// 1. 단 하나만 존재
// 2. 모든 영역에서 접근 가능
// 3. 생성주기 프로그래머가 조절 

class SoundManager
{
private:
	SoundManager() { cout << "SoundManager!!" << endl; }
	~SoundManager() { cout << "Delet SoundManager!!" << endl; }

public:
	static void Create()
	{
		if (_instance == nullptr)
		{
			_instance = new SoundManager();
		}
	}

	static void Delete()
	{
		if (_instance)
			delete _instance;
	}

	static SoundManager* Instance()
	{
		if (_instance)
			return _instance;
		return nullptr;
	}

	void Hello() { cout << mySound << endl; }
	void PlayWarrior() { cout << warriorSound << endl; }

private:
	static SoundManager* _instance;

	string mySound = "Attack!!!";
	string warriorSound = "Warrior!!!";
};
SoundManager* SoundManager::_instance = nullptr;

int main()
{
	SoundManager::Create();

	SoundManager::Instance()->Hello();

	// 워리어가 공격하는 코드
	{
		SoundManager::Instance()->PlayWarrior();
	}

	SoundManager::Delete();

	return 0;
}