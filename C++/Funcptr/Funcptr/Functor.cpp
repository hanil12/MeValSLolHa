#include <iostream>

using namespace std;

struct MyFunctor
{
	void operator()()
	{
		cout << num << endl;
		cout << "Hello World" << endl;
	}

	int num;
};

// 함수포인터는 여러가지 함수를 받아서
// 같은 함수포인터를 호출했을 때 다른 결과가 나올 수 있다.

// 함수객체 속성을 바꾸면
// => 같은 함수객체를 호출했을 결과가 달라질 수 있다.

int main()
{
	MyFunctor functor;
	functor.num = 5;
	functor();

	functor.num = 3;
	functor();

	return 0;
}