#include <iostream>

using namespace std;

// Functor : 함수객체
// => 멤버변수, 멤버함수를 가질 수 있는 함수
// 콜백함수로써 동작할 수 있다.

struct Functor
{
	void operator()()
	{
		cout << s1 << endl;
	}

	void operator()(int a)
	{
		cout << a << endl;
	}

	string s1 = "Hello World!";
};

void Temp(Functor* func)
{
	(*func).s1 = "tttt";
	(*func)();
}

int main()
{
	Functor functor;
	functor(); // 객체가 함수처럼 동작할 수 있다.

	functor.s1 = "Hell World!";
	functor();

	functor(1);

	Temp(&functor);

	return 0;
}