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
		// left���� temp�� �̹� �� �־���.
		if (leftIndex > mid)
		{
			leftOver = true;
			break;
		}

		// right���� temp�� �̹� �� �־���.
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

	// ���� Ȥ�� ������ �߿� �� ���� temp�� �� ���� ��Ȳ

	// ������ �� �־���.
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
	// �������� �� ����
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

	// temp�� �ùٸ��� ���ĵ� ��Ȳ
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