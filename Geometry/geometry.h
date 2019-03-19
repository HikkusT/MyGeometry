#pragma once
#include <iostream>

template<class T>
class Vec3
{
public:
	T x, y, z;

	Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
	Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}

	Vec3<T>& operator += (const Vec3<T>& v);
	Vec3<T>& operator -= (const Vec3<T>& v);
	Vec3<T>& operator *= (const T& t);
	Vec3<T>& operator /= (const T& t);

	const T& operator [] (uint8_t i) const { return (&x)[i]; }
	T& operator [] (uint8_t i) { return (&x)[i]; }

	T norm() const { return dot(*this, *this); }
	T length() const { return sqrt(norm()); }
	Vec3<T> unit_vector() const;
	Vec3<T>& normalize();

	friend std::ostream& operator << (std::ostream &s, const Vec3 &v)
	{
		return s << '(' << v.x << ' ' << v.y << ' ' << v.z << ')';
	}
};

//////////////////////////////////////////////////////////////////////////////

template<class T>	
Vec3<T> Vec3<T>::unit_vector() const
{
	T n = norm();
	if (n > 0)
	{
		T inv_len = 1 / sqrt(n);
		return *this * inv_len;
	}

	return Vec3<T>(0, 0, 0);
}

template<class T>
Vec3<T>& Vec3<T>::normalize()
{
	T n = norm();
	if (n > 0)
	{
		T invLen = 1 / sqrt(n);
		x *= invLen, y *= invLen, z *= invLen;
	}

	return *this;
}

template<class T>
Vec3<T>& Vec3<T>::operator+=(const Vec3<T>& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

template<class T>
Vec3<T>& Vec3<T>::operator-=(const Vec3<T>& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

template<class T>
Vec3<T>& Vec3<T>::operator*=(const T& t)
{
	x *= t;
	y *= t;
	z *= t;
	return *this;
}

template<class T>
Vec3<T>& Vec3<T>::operator/=(const T& t)
{
	x /= t;
	y /= t;
	z /= t;
	return *this;
}

template<class T>
Vec3<T> operator + (const Vec3<T>& lhs, const Vec3<T>& rhs)
{
	return Vec3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

template<class T>
Vec3<T> operator - (const Vec3<T>& lhs, const Vec3<T>& rhs)
{
	return Vec3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

template<class T, class U>
Vec3<T> operator * (const Vec3<T>& v, const U& t)
{
	return Vec3<T>(t * v.x, t * v.y, t * v.z);
}

template<class T, class U>
Vec3<T> operator * (const U& t, const Vec3<T>& v)
{
	return Vec3<T>(t * v.x, t * v.y, t * v.z);
}

template<class T, class U>
Vec3<T> operator / (const Vec3<T>& v, const U& t)
{
	return Vec3<T>(v.x / t, v.y / t, v.z / t);
}

//////////////////////////////////////////////////////////////////////////////


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