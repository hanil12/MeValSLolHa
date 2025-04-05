#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

vector<vector<bool>> adjacent; // 인접행렬
vector<bool> visited;
int M = 0;

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
	//adjacent[1][2] = true;

	//adjacent[2][1] = true;
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

void DFS(int here)
{
	cout << here << endl;

	// 방문체크
	visited[here] = true;

	// 인접한 곳을 확인
	for (int there = 0; there < 7; there++)
	{
		// 나 자신이냐?
		if (here == there)
			continue;

		// 인접해있냐?
		if (adjacent[here][there] == false)
			continue;

		// 방문여부
		if (visited[there] == true)
			continue;

		DFS(there);
	}
}

void DFS_ALL()
{
	for (int i = 0; i < 7; i++)
	{
		if (visited[i] == false)
		{
			M++;
			DFS(i);
		}
	}
}

int main()
{
	CreateGraph_Matrix();
	visited = vector<bool>(7, false);

	DFS_ALL();

	cout << M << endl;

	return 0;
}