#include <iostream>

using namespace std;

struct Item
{
	int id;   // ���̵�
	int price; // ����
	int value; // Ƽ��
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

	// ������ ���̵� 5�� �� ã��

	// ������ ���̵� 3�̰� value�� 7�� �� ã��

	// ������ price�� 5000�̰� value�� 3�� �� ã��

	return 0;
}