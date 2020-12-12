#pragma once
#include "Vector.h"
#include "Point.h"
#include <assert.h>
#include <iostream> 
#include<cmath>
#include <cassert>


using namespace std;
using namespace Base;


inline Vector::Vector() : x(0.0f), y(0.0f), z(0.0f) {}

inline Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

inline Vector::Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}

inline bool Base::AreEqual(float n1, float n2)
{
    if (n1 == n2)
        return true;
    else
        return false;
}
inline bool Base:: EqualsZero(float v1)
{
    if (v1 == 0)
        return true;
    else
        return false;
}
inline bool Base::operator==(const Vector& v1, const Vector& v2)
{
    return (AreEqual(v1.x, v2.x) &&
        AreEqual(v1.y, v2.y) &&
        AreEqual(v1.z, v2.z));
}

inline bool Base::operator!=(const Vector& v1, const Vector& v2)
{
    return (!AreEqual(v1.x, v2.x) ||
        !AreEqual(v1.y, v2.y) ||
        !AreEqual(v1.z, v2.z));
}

inline Vector Base::operator+(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline Vector Base::operator-(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline Vector Base::operator*(const Vector& v, float scalar)
{
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline Vector Base::operator*(float scalar, const Vector& v)
{
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline Vector Base::operator/(const Vector& v, float scalar)
{
    assert(!EqualsZero(scalar));
    scalar = 1.0f / scalar;
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline Vector Base::operator/(float scalar, const Vector& v)
{
    assert(!EqualsZero(scalar));
    scalar = 1.0f / scalar;
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline float Base::DotProduct(const Vector& v1, const Vector& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vector Base::CrossProduct(const Vector& v1, const Vector& v2)
{
    return Vector(v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x);
}

inline float Base::DistanceBetween(const Vector& v1, const Vector& v2)
{
    Vector distance = v1 - v2;
    return distance.Length();
}

inline float Base::DistanceBetweenSquared(const Vector& v1, const Vector& v2)
{
    Vector distance = v1- v2;
    return distance.LengthSquared();
}

inline Vector& Vector::operator=(const Vector& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

inline Vector& Vector::operator+=(const Vector& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline Vector& Vector::operator-=(const Vector& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline Vector& Vector::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

inline Vector& Vector::operator/=(float scalar)
{
    assert(!EqualsZero(scalar));
    scalar = 1.0f / scalar;
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

inline Vector& Vector::operator-()
{
    x = -x;
    y = -y;
    z = -z;
    return *this;
}


inline float Vector::X()
{
    return x;
}

inline float Vector::Y()
{
    return y;
}

inline float Vector::Z()
{
    return z;
}

inline void Vector::Set(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

inline void Vector::MakeZero()
{
    x = y = z = 0.0f;
}

inline bool Vector::IsZero()
{
    return EqualsZero(x) &&
        EqualsZero(y) &&
        EqualsZero(z);
}

inline float Vector::LengthSquared()
{
    return x * x + y * y + z * z;
}

inline float Vector::Length()
{
    return sqrt(LengthSquared());
}

inline void Vector::Normalize()
{
    float magnitude = Length();
    assert(!EqualsZero(magnitude));

    magnitude = 1.0f / magnitude;

    x *= magnitude;
    y *= magnitude;
    z *= magnitude;
}

inline bool Vector::IsNormalized()
{
    return AreEqual(Length(), 1.0f);
}


