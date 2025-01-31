#include <iostream>

using namespace std;

struct Item
{
	int id;
	int price;
	int tier;

	void PrintItem()
	{
		cout << "ID : " << id << endl;
		cout << "Price : " << price << endl;
		cout << "Tier : " << tier << endl;
	}
};

Item* FindItem_Price(Item arr[], int size, int targetPrice)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].price == targetPrice)
			return &arr[i];
	}

	return nullptr;
}

Item* FindItem_Tier(Item arr[], int size, int targetTier)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].tier == targetTier)
			return &arr[i];
	}

	return nullptr;
}

typedef bool(*FuncPtr)(Item*);

bool PriceID(Item* item)
{
	if (item->price == 6000 && item->id == 9)
		return true;
	return false;
}

bool TierID(Item* item)
{
	if (item->tier == 5 && item->id == 5)
		return true;
	return false;
}

bool TierPrice(Item* item)
{
	if (item->tier == 7 && item->price == 12000)
		return true;
	return false;
}

Item* FindItem_Funcptr(Item arr[], int size, FuncPtr funcptr)
{
	for (int i = 0; i < size; i++)
	{
		if (funcptr(&arr[i]))
		{
			return &arr[i];
		}
	}

	return nullptr;
}

struct Functor_Price
{
	bool operator()(Item* item)
	{
		if (item->price == targetPrice)
			return true;
		return false;
	}

	int targetPrice;
};

struct Functor_Tier
{
	bool operator()(Item* item)
	{
		if (item->tier == targetTier)
			return true;
		return false;
	}

	int targetTier;
};

template<typename T>
Item* FindItem_Functor(Item arr[], int size, T functor)
{
	for (int i = 0; i < size; i++)
	{
		if (functor(&arr[i]))
		{
			return &arr[i];
		}
	}

	return nullptr;
}


// Template

int main()
{
	Item items[10];

	for (int i = 0; i < 10; i++)
	{
		items[i].id = i;
		items[i].price = 15000 - i * 1000;
		items[i].tier = 10 - i;
	}

	// item의 price가 6000인 item을 찾아주세요. 그리고 PrintItem함수를 이용하여 정보 출력
	Item* findItem = FindItem_Price(items, 10, 6000);
	if(findItem != nullptr)
		findItem->PrintItem();

	// tier 5
	FindItem_Tier(items, 10, 5)->PrintItem();

	// price 6000, id 9
	FindItem_Funcptr(items, 10, &PriceID)->PrintItem();

	//tier 5, id 5
	FindItem_Funcptr(items, 10, &TierID)->PrintItem();

	// tier 7, price 12000
	FindItem_Funcptr(items, 10, &TierPrice)->PrintItem();

	// Price 12000
	Functor_Price functor;
	functor.targetPrice = 12000;
	FindItem_Functor<Functor_Price>(items, 10, functor)->PrintItem();

	// Price 10000
	functor.targetPrice = 10000;
	FindItem_Functor<Functor_Price>(items, 10, functor)->PrintItem();

	// Tier 10
	Functor_Tier functor2;
	functor2.targetTier = 10;
	FindItem_Functor<Functor_Tier>(items, 10, functor2)->PrintItem();

	return 0;
}