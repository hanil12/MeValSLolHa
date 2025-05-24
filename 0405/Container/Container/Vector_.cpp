#include <iostream>
#include <vector>

using namespace std;

class Player
{
public:
	Player(int hp, int atk) : hp(hp), atk(atk) {}

	int hp;
	int atk;
};

void PrintPlayers(vector<Player*> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i]->hp << arr[i]->atk << endl;
	}

	arr[0]->hp = 111;
}

int main()
{
	vector<Player*> players;
	// 1. ����, ����, ��������� Ŭ �� �ִ�.
	// 2. �޸� ����ȭ�� ������ �� �ִ�.

	for (int i = 0; i < 10; i++)
	{
		players.push_back(new Player(i, i * 10));
	}

	PrintPlayers(players);
	PrintPlayers(players);

	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}

	return 0;
}