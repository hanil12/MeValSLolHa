#include <iostream>
#include <vector>

using namespace std;

// Conquer
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	vector<int> temp;
	bool leftOver = false;
	int leftIndex = left;
	int rightIndex = mid + 1;

	while (true)
	{
		// left쪽을 temp에 이미 다 넣었다.
		if (leftIndex > mid)
		{
			leftOver = true;
			break;
		}

		// right쪽을 temp에 이미 다 넣었다.
		if (rightIndex > right)
			break;


		if (v[leftIndex] <= v[rightIndex])
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
		else
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}

	// 왼쪽 혹은 오른쪽 중에 한 쪽은 temp에 다 넣은 상황

	// 왼쪽을 다 넣었다.
	if (leftOver)
	{
		while (true)
		{
			if (rightIndex > right)
				break;

			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}
	// 오른쪽을 다 넣음
	else
	{
		while (true)
		{
			if (leftIndex > mid)
				break;

			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
	}

	// temp에 올바르게 정렬된 상황
	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}

// 	MergeSort(v, left, mid); => 0 1
// 	MergeSort(v, left, mid); => 0 3
// 0 , 6
void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	// Divide
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v = { 55, 30, 15, 100, 1, 5, 70 };

	MergeSort(v, 0, v.size() - 1);


	return 0;
}