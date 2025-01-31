#include <iostream>

using namespace std;

// template : ����Ʋ => �� �ξ ���� ����� ö�ⱸ �����س��� ����

// �Լ����ø� : �Լ��� ���� ����
template<typename T = int> // template�� �⺻����
void Add(T a, T b)
{
	T c = a + b;
	cout << c << endl;
}

// template�� Ư��ȭ
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

// Ŭ���� ���ø� : ���赵�� ���� ����
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

// Ŭ���� ���ø��� Ư��ȭ
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