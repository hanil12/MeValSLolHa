#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

// FIFO : First Input First Out
// 1. Queue 구현
// 2. Deque 조사하기
// 3. 그래프 조사하기
// - 누가 발견했는지
// - 컴퓨터 공학의 그래프 표현 방법
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