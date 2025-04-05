#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// FIFO : First Input First Out
// 1. Queue ����
// 2. Deque �����ϱ�
// 3. �׷��� �����ϱ�
// - ���� �߰��ߴ���
// - ��ǻ�� ������ �׷��� ǥ�� ���

int main()
{
	queue<int> q;

	q.push(5);
	q.push(1);
	q.push(3);
	q.push(10);
	q.push(11);

	while (true)
	{
		if (q.empty())
			break;

		cout << q.front() << endl;

		q.pop();
	}

	return 0;
}