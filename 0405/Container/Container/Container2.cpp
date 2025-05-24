#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

// map vs unordered map
// Key�� Valuer�� ������ ����ȴ�.

struct User
{
	User() : id(0) {}
	User(int id) : id(id) {}

	int id;
};

// �ε��� Ž���� �ɸ��� �ð� : ���
// Ž�� �ɸ��� �ð� : n
void FindUser_Vector()
{
	vector<User> users;

	for (int i = 0; i < 1000; i++)
	{
		User user;
		user.id = i;

		users.push_back(user);
	}

	// UserId�� 888�� �긦 ã��ʹ�. => �ð����⵵ ���
	// v[888]
	// ...
	// �߰��� ������ ��Ż�ϰų�, �������� ��... => �ε����� id�� �ϴ��� �������� ��ġ�� ���� �ʴ� ���

	// UserId�� 888�� �긦 ã��ʹ�. =>�ð����⵵ n
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].id == 888)
		{
			cout << "ã�Ҵ�." << endl;
			break;
		}
	}
}

// Ž�� �ɸ��� �ð� : log n
// => (�ڰ� ����) ���� Ž�� Ʈ�� (���� �� Ʈ��)
void FindUser_Map()
{
	map<int, User> userMap;

	for (int i = 0; i < 1000; i++)
	{
		pair<int, User> p;
		p.first = i;
		p.second = User(i);

		// userMap.insert(p);
		userMap[i] = User(i);
	}

	map<int, User>::iterator mapIter = userMap.begin();

	userMap.erase(10);
	userMap[1001] = User(1001);
	userMap[15000] = User(15000); // insert, �ߺ�ó�� �Ұ���

	pair<map<int, User>::iterator, bool> succeed = userMap.insert(make_pair<int, User>(1, 10000)); // �ߺ�ó�� ����
	if (succeed.second == false)
	{
		cout << "���� ����" << endl;
	}

	for (mapIter; mapIter != userMap.end(); mapIter++)
	{
		cout << "Key : " << mapIter->first << ", Value : " << mapIter->second.id << endl;
	}

	// �ش�Ű�� �ִ��� ã��
	if (userMap.count(10) == 0)
	{
		cout << "id : 10�� ������ �����ϴ�." << endl;
	}
	else
	{
		cout << "ID : " << userMap[10].id << endl;
	}
}

// Ž�� �ɸ��� �ð� : ���
// => �ؽ� ���̺�
// * �ؽ� ü�̴��� ��������
void FindUser_UMap()
{
	unordered_map<int, User> uMap;

	for (int i = 0; i < 1000; i++)
	{
		uMap[i] = User(i);
	}

	unordered_map<int, User>::iterator iter = uMap.begin();
	for (iter; iter != uMap.end(); iter++)
	{
		cout << "Key : " << iter->first << " , Value : " << iter->second.id << endl;
	}

	// �ش�Ű�� �ִ��� ã��
	if (uMap.count(10) == 0)
	{
		cout << "id : 10�� ������ �����ϴ�." << endl;
	}
	else
	{
		cout << "ID : " << uMap[10].id << endl;
	}
}

int main()
{


	return 0;
}