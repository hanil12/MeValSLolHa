#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int lowIndex = left + 1;
	int highIndex = right;

	while (true)
	{
		if (lowIndex > highIndex) // ����
			break;

		while (lowIndex <= right && pivot >= v[lowIndex])
		{
			lowIndex++;
		}

		while (highIndex >= left + 1 && pivot <= v[highIndex])
		{
			highIndex--;
		}

		if (lowIndex < highIndex)
			std::swap(v[lowIndex], v[highIndex]);
	}

	std::swap(pivot, v[highIndex]);

	return highIndex;
}

void QuickSort(vector<int>& v, int left, int right)
{
	// ��������
	if (left > right)
		return;

	int pivotIndex = Partition(v, left, right); // �ڸ� ���ϱ�
	cout << left << " ~ " << right << endl;

	QuickSort(v, left, pivotIndex - 1);
	QuickSort(v, pivotIndex + 1, right);
}

int main()
{
	vector<int> v = { 55, 30, 15, 100, 1, 5, 70 };
	QuickSort(v, 0, v.size() - 1);

	return 0;
}