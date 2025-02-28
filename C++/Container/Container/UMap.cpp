#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

// 시간복잡도 : Big O 표기법
// 상수 : vector의 임의접근, list의 삽입/삭제, unordered_map의 탐색
// logN : 이진탐색, map의 탐색
// N : list의 접근, vector의 탐색
// N * logN : std::sort정렬
// N^2 : 버블정렬, 선택정렬

using namespace std;

// map vs unoreded_map
// 1. 탐색 시간복잡도
// 2. 삽입 시간복잡도
// => 데이터가 크지 않은 경우 unordered_map => 게임
// => 데이터가 매우 큰 경우 map => 데이터베이스

// 해시 함수, 해시 충돌
// 체이닝

int main()
{

	return 0;
}