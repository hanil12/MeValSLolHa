#include <iostream>

using namespace std;

// template : 주형, 찍어내는 용도로 쓰이는 것

// 함수 템플릿
template <typename T = int> // 기본인자 설정
T Add(T a, T b)
{
	return a + b;
}

template<> // 템플릿의 특수화
double Add(double a, double b)
{
	cout << "템플릿 특수화" << endl;
	return a + b;
}

// 클래스 템플릿
template<typename T = float>
class Vector
{
public:

	void PrintVector()
	{
		cout << "x : " << x << ", y: " << y << endl;
	}

	T x;
	T y;
};

template<>
class Vector<double>
{
public:
	void PrintVector()
	{
		cout << "특수화!!" << endl;
		cout << "x : " << x << ", y: " << y << endl;
	}

	double x;
	double y;
};

int main()
{
	cout << Add<double>(1, 2) << endl;

	Vector<double> v;
	v.x = 1.1;
	v.y = 3.5;

	v.PrintVector();

	return 0;
}