#include <iostream>

using namespace std;

struct Item
{
	int id;   // 아이디
	int price; // 가격
	int value; // 티어
};

void FindItem_ID(Item* arr[], int size, int id)
{

}

int main()
{
	Item* arr[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i] = new Item();
		arr[i]->id = i;
		arr[i]->price = i * 1000;
		arr[i]->value = 10 - i;
	}

	// 아이템 아이디가 5인 얘 찾기

	// 아이템 아이디가 3이고 value가 7인 얘 찾기

	// 아이템 price가 5000이고 value가 3인 얘 찾기

	return 0;
}