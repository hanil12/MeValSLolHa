#include <iostream>

using namespace std;

// template : ����, ���� �뵵�� ���̴� ��

// �Լ� ���ø�
template <typename T = int> // �⺻���� ����
T Add(T a, T b)
{
	return a + b;
}

template<> // ���ø��� Ư��ȭ
double Add(double a, double b)
{
	cout << "���ø� Ư��ȭ" << endl;
	return a + b;
}

// Ŭ���� ���ø�
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
		cout << "Ư��ȭ!!" << endl;
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