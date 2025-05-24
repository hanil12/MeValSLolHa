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
	// 1. 생성, 복사, 삭제비용이 클 수 있다.
	// 2. 메모리 파편화를 보완할 수 있다.

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