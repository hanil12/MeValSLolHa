#include <iostream>
#include <vector>

using namespace std;


void MergeResult(vector<int>& v, int left, int mid, int right)
{
	vector<int> temp;
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


	return 0;
}