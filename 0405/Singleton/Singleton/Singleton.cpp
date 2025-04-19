#include <iostream>

using namespace std;

// Singleton
// 1. �� �ϳ��� ����
// 2. ��� �������� ���� ����
// 3. �����ֱ� ���α׷��Ӱ� ���� 

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

	// ����� �����ϴ� �ڵ�
	{
		SoundManager::Instance()->PlayWarrior();
	}

	SoundManager::Delete();

	return 0;
}