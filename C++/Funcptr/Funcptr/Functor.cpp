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

// �Լ������ʹ� �������� �Լ��� �޾Ƽ�
// ���� �Լ������͸� ȣ������ �� �ٸ� ����� ���� �� �ִ�.

// �Լ���ü �Ӽ��� �ٲٸ�
// => ���� �Լ���ü�� ȣ������ ����� �޶��� �� �ִ�.

int main()
{
	MyFunctor functor;
	functor.num = 5;
	functor();

	functor.num = 3;
	functor();

	return 0;
}