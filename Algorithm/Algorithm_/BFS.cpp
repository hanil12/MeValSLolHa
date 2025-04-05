#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

vector<vector<bool>> adjacent; // 인접행렬
vector<bool> discoverd;
vector<int> parent;
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
	adjacent[1][2] = true;

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

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	discoverd[start] = true;
	parent[start] = start;

	while (true)
	{
		if (q.empty())
			break;

		int here = q.front();
		q.pop();
		cout << here << endl;

		for (int there = 0; there < 7; there++)
		{
			// 자기 자신이냐
			if (there == here)
				continue;

			// 인접해있냐?
			if (adjacent[here][there] == false)
				continue;

			// 방문되어있냐?
			if (discoverd[there] == true)
				continue;

			q.push(there);
			discoverd[there] = true;
			parent[there] = here;
		}
	}
}

int main()
{
	CreateGraph_Matrix();
	discoverd = vector<bool>(7, false);
	parent = vector<int>(7, -1);

	BFS(0);

	int distance = 0;
	int check = 6;
	while (true)
	{
		check = parent[check];
		distance++;

		if (check == 0)
			break;
	}

	cout << "Distance 0 - 6  : " << distance << endl;

	return 0;
}