#include <iostream>
#include <list>

using namespace std;

// list

#include "MyList.h"
#include "MyVector.h"

int main()
{
	List l;

	l.push_back(5); // 5
	l.push_front(3); // 3 5
	l.push_back(2); // 3 5 2 
	l.push_back(14); // 3 5 2 14
	l.push_back(30);
	l.push_front(1);

	for (int i = 0; i < l.size(); i++)
	{
		cout << l[i] << endl;
	}
	

	return 0;
}