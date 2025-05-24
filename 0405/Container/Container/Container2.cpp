#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

// map vs unordered map
// Key와 Valuer가 쌍으로 저장된다.

struct User
{
	User() : id(0) {}
	User(int id) : id(id) {}

	int id;
};

// 인덱스 탐색에 걸리는 시간 : 상수
// 탐색 걸리는 시간 : n
void FindUser_Vector()
{
	vector<User> users;

	for (int i = 0; i < 1000; i++)
	{
		User user;
		user.id = i;

		users.push_back(user);
	}

	// UserId가 888인 얘를 찾고싶다. => 시간복잡도 상수
	// v[888]
	// ...
	// 중간에 유저가 이탈하거나, 계정삭제 등... => 인덱스와 id가 일대일 대응으로 매치가 되지 않는 경우

	// UserId가 888인 얘를 찾고싶다. =>시간복잡도 n
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].id == 888)
		{
			cout << "찾았다." << endl;
			break;
		}
	}
}

// 탐색 걸리는 시간 : log n
// => (자가 균형) 이진 탐색 트리 (레드 블랙 트리)
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
	userMap[15000] = User(15000); // insert, 중복처리 불가능

	pair<map<int, User>::iterator, bool> succeed = userMap.insert(make_pair<int, User>(1, 10000)); // 중복처리 가능
	if (succeed.second == false)
	{
		cout << "삽입 실패" << endl;
	}

	for (mapIter; mapIter != userMap.end(); mapIter++)
	{
		cout << "Key : " << mapIter->first << ", Value : " << mapIter->second.id << endl;
	}

	// 해당키가 있는지 찾기
	if (userMap.count(10) == 0)
	{
		cout << "id : 10인 유저가 없습니다." << endl;
	}
	else
	{
		cout << "ID : " << userMap[10].id << endl;
	}
}

// 탐색 걸리는 시간 : 상수
// => 해쉬 테이블
// * 해쉬 체이닝이 무엇인지
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

	// 해당키가 있는지 찾기
	if (uMap.count(10) == 0)
	{
		cout << "id : 10인 유저가 없습니다." << endl;
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