#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> adjacent_list; // 인접리스트
vector<vector<bool>> adjacent; // 인접행렬

void CreateGraph()
{
	adjacent_list.resize(7);

	adjacent_list[0].push_back(0);
	adjacent_list[0].push_back(1);
	adjacent_list[0].push_back(3);
	adjacent_list[0].push_back(4);

	adjacent_list[1].push_back(0);
	adjacent_list[1].push_back(1);
	adjacent_list[1].push_back(2);

	adjacent_list[2].push_back(1);
	adjacent_list[2].push_back(2);

	adjacent_list[3] = { 0,3,5,6 };

	adjacent_list[4] = { 0,4 };
	adjacent_list[5] = { 3,5 };
	adjacent_list[6] = { 3,6 };
}
void CreateGraph_Matrix()
{
	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));

	//    0  1  2  3  4  5  6
	// 0  1  1  0  1  1  0  0
	// 1  1  1  1  0  0  0  0
	// 2  0  1  1  0  0  0  0
	// 3  1  0  0  1  0  1  1
	// 4  1  0  0  0  1  0  0
	// 5  0  0  0  1  0  1  0
	// 6  0  0  0  1  0  0  1

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[0][4] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;

	adjacent[2][1] = true;
	adjacent[2][2] = true;

	adjacent[3][0] = true;
	adjacent[3][3] = true;
	adjacent[3][5] = true;
	adjacent[3][6] = true;

	adjacent[4][0] = true;
	adjacent[4][4] = true;

	adjacent[5][3] = true;
	adjacent[5][5] = true;

	adjacent[6][3] = true;
	adjacent[6][6] = true;

}

int main()
{
	CreateGraph();

	// 0과 3이 인접되어있냐?
	for (int i = 0; i < adjacent_list[0].size(); i++)
	{
		if (adjacent_list[0][i] == 3)
			cout << "0,3 이 인접" << endl;
	}

	CreateGraph_Matrix();
	// 3과 6이 인접해있냐?
	if (adjacent[3][6])
		cout << "0,6이 인접" << endl;

	return 0;
}