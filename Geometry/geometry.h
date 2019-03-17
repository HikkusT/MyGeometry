#pragma once
#include <iostream>

template<class T>
class Vec3
{
public:
	T x, y, z;

	Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
	Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}

	Vec3<T> operator + (const Vec3<T> &v) const
	{
		return Vec3<T>(x + v.x, y + v.y, z + v.z);
	}
	Vec3<T> operator - (const Vec3<T> &v) const
	{
		return Vec3<T>(x - v.x, y - v.y, z - v.z);
	}
	Vec3<T> operator * (const T &r) const
	{
		return Vec3<T>(x * r, y * r, z * r);
	}
	T dotProduct(const Vec3<T> &v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}
	Vec3<T> crossProduct(const Vec3<T> &v) const
	{
		return Vec3<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}
	T norm() const
	{
		return dot(*this);
	}
	T length() const
	{
		return sqrt(norm());
	}
	const T& operator [] (uint8_t i) const { return (&x)[i]; }
	T& operator [] (uint8_t i) { return (&x)[i]; }

	Vec3& normalize()
	{
		T norm = norm();
		if (norm > 0)
		{
			T invLen = 1 / sqrt(norm);
			x *= invLen, y *= invLen, z *= invLen;
		}

		return *this;
	}

	friend std::ostream& operator << (std::ostream &s, const Vec3 &v)
	{
		return s << '(' << v.x << ' ' << v.y << ' ' << v.z << ')';
	}
};

template<class T>
class Matrix4x4
{
public:
	T m[4][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1} };

	Matrix4x4() {}

	const T* operator [] (uint8_t i) const { return m[i]; }
	T* operator [] (uint8_t i) { return m[i]; }

};

template<class T>
T dot(const Vec3<T> &a, const Vec3<T> &b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

template<class T>
T length(const Vec3<T> &v)
{
	return sqrt(dot(v, v));
}

template<class T>
Vec3<T> cross(const Vec3<T> a, const Vec3<T> b)
{
	return Vec3<T>(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}

typedef Vec3<float> Vec3f;
typedef Matrix4x4<float> Matrix4x4f;