#pragma once

template<typename T = float>
class Vector2
{
public:
	Vector2() : x(0), y(0) {}
	Vector2(const T& x, const T& y) : x(x), y(y) {}

	Vector2<T> operator+(const Vector2<T>& other) const
	{
		Vector2<T> result;
		result.x = x + other.x;
		result.y = y + other.y;

		return result;
	}
	Vector2<T> operator-(const Vector2& other) const
	{
		Vector2 result;
		result.x = x - other.x;
		result.y = y - other.y;

		return result;
	}
	Vector2<T> operator*(const float& value) const
	{
		Vector2<T> result;
		result.x = x * value;
		result.y = y * value;

		return result;
	}
	Vector2<T>& operator=(const Vector2<T>& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}
	Vector2<T>& operator+=(const Vector2<T>& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}
	Vector2<T>& operator-=(const Vector2<T>& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	float DotProduct(const Vector2<T>& other) const
	{
		return x * other.x + y * other.y;
	}
	float Cross(const Vector2<T>& other) const
	{
		return x * other.y - y * other.x;
	}
	float Length() const { return sqrtf(x * x + y * y); }
	Vector2<T> NormalVector()
	{
		float length = Length();

		Vector2<T> result;
		result.x = x / length;
		result.y = y / length;

		return result;
	}

	T x;
	T y;
};
