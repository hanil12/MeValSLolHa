#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// FIFO : First Input First Out
// 1. Queue ����
// 2. Deque �����ϱ�
// 3. �׷��� �����ϱ�
// - ���� �߰��ߴ���
// - ��ǻ�� ������ �׷��� ǥ�� ���
template <typename T, typename Container = deque<T>>
class Queue
{
public:
	void push(const T& data)
	{
		container.push_back(data);
	}

	void pop()
	{
		container.pop_front();
	}

	const T& front() { return container.front(); }

	bool empty() { return container.empty(); }

private:
	Container container;
};

int main()
{
	Queue<int> q;

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