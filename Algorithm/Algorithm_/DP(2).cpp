#include <iostream>
#include <vector>

using namespace std;

// 백준의 신나는 함수 실행
// N = 1 ... 1 (1)
// N = 2 ... 2 (00, 11)
// N = 3 ... 3 (100, 111, 001)
// N = 4 ... 5 (0011, 0000, 1001, 1100, 1111)
// N = 5 ... 8 (00001, 10000, 00100, 00111, 10011, 11001, 11100, 11111)
// F(N) = F(N-2) + F(N-1)

int n = 0;
vector<long long> cache;

void Input()
{
	cin >> n;
}

int DP(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;

	long long& ref = cache[n];
	if (ref != -1)
		return ref;

	return ref = (DP(n - 1) + DP(n - 2)) % 15746;
}

int main()
{
	cache = vector<long long> (1000001, -1);

	Input();

	int result = DP(n);
	cout << result << endl;

	return 0;
}