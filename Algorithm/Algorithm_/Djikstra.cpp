#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> adjacent; // 인접행렬
vector<int> best;
vector<int> parent;
int M = 0;

struct Vertex
{
	int v;
	int cost;

	bool operator>(const Vertex& other) const
	{
		return this->cost > other.cost;
	}

	bool operator<(const Vertex& other) const
	{
		return this->cost < other.cost;
	}
};

void CreateGraph_Matrix()
{
	adjacent = vector<vector<int>>(7, vector<int>(7, -1));

	adjacent[0][0] = 0;
	adjacent[0][1] = 10;
	adjacent[0][3] = 5;
	adjacent[0][4] = 7;

	adjacent[1][0] = 10;
	adjacent[1][1] = 0;
	adjacent[1][2] = 4;
	adjacent[1][3] = 1;

	adjacent[2][1] = 4;
	adjacent[2][2] = 0;

	adjacent[3][0] = 5;
	adjacent[3][1] = 1;
	adjacent[3][3] = 0;
	adjacent[3][5] = 3;
	adjacent[3][6] = 6;

	adjacent[4][0] = 7;
	adjacent[4][4] = 0;

	adjacent[5][3] = 3;
	adjacent[5][5] = 0;

	adjacent[6][3] = 6;
	adjacent[6][6] = 0;

}

void Djikstra(int here)
{
	priority_queue<Vertex> pq;

	Vertex startV = {here,0};
	pq.push(startV);
	parent[here] = here;
	best[here] = 0;

	while (true)
	{
		if (pq.empty())
			break;

		Vertex hereV = pq.top();
		int here = hereV.v;
		int curCost = hereV.cost;

		pq.pop();

		// pq에 미리 넣어놨었는데, 이미 좋은 길이 best에 있었다.
		if (best[here] < curCost)
		{
			continue;
		}

		for (int there = 0; there < adjacent.size(); there++)
		{
			if (here == there)
				continue;

			if (adjacent[here][there] == -1)
				continue;

			int newCost = curCost + adjacent[here][there];
			
			// pq에 넣기 전에, 이미 좋은 길을 발견 했었다.
			if (best[there] < newCost)
				continue;

			Vertex thereV = { there, newCost };
			pq.push(thereV);
			best[there] = newCost;
			parent[there] = here;
		}
	}
}

int main()
{
	CreateGraph_Matrix();
	best = vector<int>(7, INT_MAX);
	parent = vector<int>(7, -1);

	Djikstra(0);

	int check = 2;
	while (true)
	{
		cout << "Vertex : " << check << ", Best : " << best[check] << endl;

		check = parent[check];

		if (check == parent[check])
		{
			cout << check << endl;
			break;
		}
	}

	return 0;
}