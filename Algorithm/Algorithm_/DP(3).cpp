#include <iostream>
#include <vector>

using namespace std;

// LIS (Longest Increasing Sequence)
// 최장 부분 증가 수열(길이)을 찾아라

// { 5 6 7 1 2 3 10 }
// 부분 수열, {2,3} , {7 2 10} 
// 부분 수열X {6,5}

// 증가 수열  {1 2 3} {5 6 7} { 5 6 7 10 }
// 증가 수열X {7 1 2} {5 6 7 1 2}

// { 5 6 7 1 2 3 10 } n = 7
// LIS(6) : 1
// LIS(5) : 2 LIS(6) + 1
// LIS(4) : 3 LIS(5) + 1
// LIS(3) : 4 LIS(4) + 1

// { 5 6 7 1 2 3 10 }
// { 3 5 6 7 1 2 3 10 }
// { 5 6 7 1 2 }

vector<int> v = { 5,6,7,1,2,3,5,6,10 };
vector<int> cache;

int Lis(int idx)
{
	if (idx == v.size() - 1)
		return 1;

	int& ref = cache[idx];

	ref = 1;

	for (int next = idx + 1; next < v.size(); next++)
	{
		if (v[idx] < v[next])
		{
			ref = max(ref, Lis(next) + 1);
		}
	}

	return ref;
}

int main()
{
	cache = vector<int>(v.size(), -1);

	int result = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		result = max(result, Lis(i));
	}

	cout << result << endl;

	return 0;
}