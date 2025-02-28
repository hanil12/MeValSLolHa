#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct UserInfo
{
	int userId;
	int player;
};

int main()
{
	vector<UserInfo> users;

	users.reserve(1000);
	for (int i = 0; i < 1000; i++)
	{
		UserInfo info;
		info.userId = i;
		info.player = i + 1;
		users.push_back(info);
	}

	// 회원이 탈퇴 혹은 새로 가입

	// userId 500인 얘를 찾고 싶다.
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].userId == 500)
			break;
	}

	//////////////////////////
	map<int, UserInfo> userMap;

	for (int i = 0; i < 1000; i++)
	{
		UserInfo info;
		info.userId = i + 50;
		info.player = i + 1000;
		userMap[info.userId] = info;
	}

	if(userMap.count(51) == 0)
		userMap[51] = { 51, 123445 };

	UserInfo insertInfo;
	insertInfo.userId = 52;
	insertInfo.player = 1234123;

	pair<int, UserInfo> myPair;
	myPair.first = insertInfo.userId;
	myPair.second = insertInfo;
	pair<map<int,UserInfo>::iterator, bool> result = userMap.insert(myPair);
	
	if (result.second == false)
	{
		cout << result.first->second.player << endl;
		cout << "삽입 실패" << endl;
	}

	/*for (int i = 0; i < userMap.size(); i++)
	{
		cout << userMap[i].userId << endl;
		cout << userMap[i].player << endl;
	}*/
	map<int, UserInfo>::iterator iter;
	iter = userMap.begin();

	for (iter; iter != userMap.end(); iter++)
	{
		cout << "Key: " << (*iter).first << " , " << "Value :  " << iter->second.userId << "," << (*iter).second.player << endl;
	}

	return 0;
}