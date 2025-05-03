#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

// 피보나치 수열
// f(0), f(1) = 1
// f(n) = f(n-1) + f(n-2)

// f(2) = f(1) + f(0)
// f(3) = f(2) + f(1)
// f(4) = f(3) + f(2)

// Dynamic Programming : 동적계획법
// 최적부분구조를 찾고, 그를 이용해서 이전의 미리 해결놓은 값들을 어딘가에 메모해놓고 계산하지 않는 방법
// => 최적화

// 메모이제이션
vector<int> cache;
// 계산해봤던 값들을 cache에 넣겠다.

int countN = 0;

int Fibonacci(int n)
{
	// 기저사항
	if (n == 0 || n == 1)
		return 1;

	if (n == 2)
		countN++;

	// 메모이제이션
	int& ref = cache[n];
	if (ref != -1)
		return ref;

	// 구하기
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
