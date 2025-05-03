#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

// 조합 Combination
// ex) 5C3 : 4C3 + 4C2 => 최적부분구조

// 메모이제이션
vector<vector<int>> cache;

int Combination(int n, int r)
{
	if (r == 1)
		return n;

	if (n == 1 || n == r)
		return 1;

	int& ref = cache[n][r];

	if (ref != -1)
		return ref;

	return ref = Combination(n - 1, r) + Combination(n - 1, r - 1);
}

int main()
{
	cache = vector<vector<int>>(1000, vector<int>(999, -1));

	__int64 start = GetTickCount64();

	int result = Combination(500, 10);

	__int64 end = GetTickCount64();

	cout << end - start << "clock" << endl;
	cout << result << endl;

	return 0;
}