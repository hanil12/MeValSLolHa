#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// Ʈ���� ����
// ��������Ʈ��
// ��Ʈ��

template<typename T, typename Container = vector<T>, typename Pred = less<T>>
class Priority_Queue
{
public:
	void push(const T& data)
	{
		container.push_back(data);

		// �θ�� ��
		int now = static_cast<int>(container.size() - 1);
		while (true)
		{
			if (now <= 0)
				break;

			int parent = (now - 1) / 2;
			if (pred(container[now],container[parent]))
				break;

			// now�� parent���� �� ũ��
			swap(container[now], container[parent]);
			now = parent;
		}
	}

	void pop()
	{
		container[0] = container.back();
		container.pop_back();

		int now = 0;

		while (true)
		{
			int left = now * 2 + 1;
			int right = now * 2 + 2;

			// ���� �ڽ��� ���� ��� => root�� ���� ��
			if (left >= container.size())
				break;


			int next = now;

			if (pred(container[next],container[left]))
			{
				next = left;
			}

			// right�� �ְ�, next�� right���� �۰�
			if (right < container.size() && pred(container[next],container[right]))
			{
				next = right;
			}

			if (next == now)
				break;

			swap(container[now], container[next]);
			now = next;
		}
	}

	bool empty()
	{
		return container.empty();
	}

	const T& top()
	{
		return container[0];
	}

private:
	Container container;
	Pred pred;
};

int main()
{
	// �ִ���
	Priority_Queue<int, vector<int>, greater<int>> pq;

	pq.push(100);
	pq.push(70);
	pq.push(150);
	pq.push(200);
	pq.push(5);
	pq.push(30);
	pq.push(55);

	while (true)
	{
		if (pq.empty())
			break;

		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}