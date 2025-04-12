#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// 트리의 종류
// 완전이진트리
// 힙트리

template<typename T, typename Container = vector<T>, typename Pred = less<T>>
class Priority_Queue
{
public:
	void push(const T& data)
	{
		container.push_back(data);

		// 부모와 비교
		int now = static_cast<int>(container.size() - 1);
		while (true)
		{
			if (now <= 0)
				break;

			int parent = (now - 1) / 2;
			if (pred(container[now],container[parent]))
				break;

			// now가 parent보다 더 크다
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

			// 왼쪽 자식이 없는 경우 => root만 있을 때
			if (left >= container.size())
				break;


			int next = now;

			if (pred(container[next],container[left]))
			{
				next = left;
			}

			// right가 있고, next가 right보다 작고
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
	// 최대힙
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