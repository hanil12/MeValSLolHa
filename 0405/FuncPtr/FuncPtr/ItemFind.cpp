#include <iostream>

using namespace std;

struct Item
{
	int id;   // 아이디
	int price; // 가격
	int value; // 티어

	void PrintItem() { cout << "id : " << id << ", price : " << price << ", value : " << value << endl; }
};

Item* FindItem_ID(Item* arr[], int size, int id)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->id == id)
			return arr[i];
	}
}

bool ID_Item(Item* item)
{
	if (item->id == 5)
		return true;
	return false;
}

bool IDVALUE_Item(Item* item)
{
	if (item->value == 7 && item->id == 3)
		return true;
	return false;
}

Item* FindItem_FuncPtr(Item* arr[], int size, bool(*func)(Item*)) // 함수포인터를 매개변수로 받는 함수
{
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]))
		{
			return arr[i];
		}
	}
}

struct Functor_IDVALUE
{
	bool operator()(Item* item)
	{
		if (item->id == id && item->value == value)
			return true;
		return false;
	}

	int id;
	int value;
};

struct Functor_PRICEVALUE
{
	bool operator()(Item* item)
	{
		if (item->price == price && item->value == value)
			return true;
		return false;
	}

	int price;
	int value;
};

template<typename T>
Item* FindItem_Func(Item* arr[], int size, T func) // 함수포인터를 매개변수로 받는 함수
{
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]))
		{
			return arr[i];
		}
	}
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
	Item* item = FindItem_FuncPtr(arr, 10, &ID_Item);
	cout << item->id << ", " << item->price << ", " << item->value << endl;

	// 아이템 아이디가 3이고 value가 7인 얘 찾기
	item = FindItem_FuncPtr(arr, 10, &IDVALUE_Item);
	item->PrintItem();

	// 아이템 아이디가 3이고 value가 7인 얘 찾기
	Functor_IDVALUE functor;
	functor.id = 3;
	functor.value = 7;
	item = FindItem_Func<Functor_IDVALUE>(arr, 10, functor);
	item->PrintItem();

	functor.id = 4;
	functor.value = 6;
	item = FindItem_Func<Functor_IDVALUE>(arr, 10, functor);
	item->PrintItem();

	// 아이템 price가 5000이고 value가 5인 얘 찾기
	Functor_PRICEVALUE functor2;
	functor2.price = 5000;
	functor2.value = 5;
	item = FindItem_Func<Functor_PRICEVALUE>(arr, 10, functor2);
	item->PrintItem();

	item = FindItem_Func<bool(*)(Item*)>(arr, 10, IDVALUE_Item);
	item->PrintItem();

	return 0;
}