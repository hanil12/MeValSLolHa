#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

// �Ǻ���ġ ����
// f(0), f(1) = 1
// f(n) = f(n-1) + f(n-2)

// f(2) = f(1) + f(0)
// f(3) = f(2) + f(1)
// f(4) = f(3) + f(2)

// Dynamic Programming : ������ȹ��
// �����κб����� ã��, �׸� �̿��ؼ� ������ �̸� �ذ���� ������ ��򰡿� �޸��س��� ������� �ʴ� ���
// => ����ȭ

// �޸������̼�
vector<int> cache;
// ����غô� ������ cache�� �ְڴ�.

int countN = 0;

int Fibonacci(int n)
{
	// ��������
	if (n == 0 || n == 1)
		return 1;

	if (n == 2)
		countN++;

	// �޸������̼�
	int& ref = cache[n];
	if (ref != -1)
		return ref;

	// ���ϱ�
	ref = Fibonacci(n - 1) + Fibonacci(n - 2);

	return ref;
}

int main()
{
	cache = vector<int>(100, -1);

	cout << Fibonacci(99) << endl;
	cout << countN << endl;

	return 0;
}
