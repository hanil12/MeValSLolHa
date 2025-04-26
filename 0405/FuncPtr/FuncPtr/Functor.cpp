#include <iostream>

using namespace std;

// Functor : �Լ���ü
// => �������, ����Լ��� ���� �� �ִ� �Լ�
// �ݹ��Լ��ν� ������ �� �ִ�.

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
	functor(); // ��ü�� �Լ�ó�� ������ �� �ִ�.

	functor.s1 = "Hell World!";
	functor();

	functor(1);

	Temp(&functor);

	return 0;
}