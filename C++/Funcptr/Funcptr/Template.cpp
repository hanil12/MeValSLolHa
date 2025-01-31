#include <iostream>

using namespace std;

// template : 주조틀 => 쇳물 부어서 같은 모양의 철기구 생산해내는 도구

// 함수템플릿 : 함수를 찍어내는 도구
template<typename T = int> // template의 기본인자
void Add(T a, T b)
{
	T c = a + b;
	cout << c << endl;
}

// template의 특수화
template<>
void Add(double a, double b)
{
	double c = a + b;
	cout << c << endl;
	cout << "Double Add!!" << endl;
}

class Player
{

};

// 클래스 템플릿 : 설계도를 찍어내는 도구
template<typename T = float>
class Vector
{
public:
	Vector() : x(T()), y(T()) {}

	void PrintV()
	{
		cout << x << endl;
		cout << y << endl;
	}

	Vector<T> operator+(const Vector<T> other)
	{
		Vector<T> result;
		result.x = x + other.x;
		result.y = y + other.y;

		return result;
	}

public:
	T x;
	T y;
};

// 클래스 템플릿의 특수화
template<>
class Vector<double>
{
public:
	Vector() : x(double()), y(double()) {}

	void PrintV()
	{
		cout << x << endl;
		cout << y << endl;

		cout << "Double Class Template!!!" << endl;
	}

public:
	double x;
	double y;
};


int main()
{
	Add<float>(1.1f, 2.1f);
	Add(1, 5);
	Add<double>(1.111, 5.222);

	Vector<double> v;
	v.x = 1.4;
	v.y = 1.1;
	v.PrintV();

	return 0;
}