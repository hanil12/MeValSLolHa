#pragma once
#include "framework.h"

class Vector : public XMFLOAT2
{
public:
	Vector() : XMFLOAT2() {}
	Vector(float x, float y) : XMFLOAT2(x,y) {}

	Vector operator+(const Vector& other)
	{
		Vector result;
		result.x = x + other.x;
		result.y = y + other.y;

		return result;
	}
	Vector operator-(const Vector& other)
	{
		Vector result;
		result.x = x - other.x;
		result.y = y - other.y;

		return result;
	}
	Vector operator*(const float& value)
	{
		Vector result;
		result.x = x * value;
		result.y = y * value;

		return result;
	}
	bool operator==(const Vector& other) const
	{
		if (x == other.x)
		{
			if (y == other.y)
				return true;
		}

		return false;
	}
	bool operator!=(const Vector& other) const
	{
		return !this->operator==(other);
	}


	float Length()
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}
	void Normalize()
	{
		float length = Length();
		x /= length;
		y /= length;
	}
	Vector UnitVector()
	{
		Vector result = *this;
		result.Normalize();

		return result;
	}
	float Dot(const Vector& other)
	{
		return x * other.x + y * other.y;
	}
	float Cross(const Vector& other)
	{
		return x * other.y - y * other.x;
	}

	float Angle() { return atan2(y, x); }
};