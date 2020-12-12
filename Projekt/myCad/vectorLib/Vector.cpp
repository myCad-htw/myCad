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

inline std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    os << '(' << v.x << ',' << v.y << ',' << v.z << ')';
    return os;
}

inline bool operator==(const Vector& v1, const Vector& v2)
{
    return (AreEqual(v1.x, v2.x) &&
        AreEqual(v1.y, v2.y) &&
        AreEqual(v1.z, v2.z));
}

inline bool operator!=(const Vector& v1, const Vector& v2)
{
    return (!AreEqual(v1.x, v2.x) ||
        !AreEqual(v1.y, v2.y) ||
        !AreEqual(v1.z, v2.z));
}

inline Vector operator+(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline Vector operator-(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline Vector operator*(const Vector& v, float scalar)
{
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline Vector operator*(float scalar, const Vector& v)
{
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline Vector operator/(const Vector& v, float scalar)
{
    assert(!EqualsZero(scalar));
    scalar = 1.0f / scalar;
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline Vector operator/(float scalar, const Vector& v)
{
    assert(!EqualsZero(scalar));
    scalar = 1.0f / scalar;
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline float DotProduct(const Vector& v1, const Vector& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vector CrossProduct(const Vector& v1, const Vector& v2)
{
    return Vector(v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x);
}

inline Vector Lerp(const Vector& v1, const Vector& v2, float t)
{
    return Vector(Lerp(v1.x, v2.x, t),
        Lerp(v1.y, v2.y, t),
        Lerp(v1.z, v2.z, t));
}

inline Vector Clamp(const Vector& v, float min, float max)
{
    return Vector(Clamp(v.x, min, max),
        Clamp(v.y, min, max),
        Clamp(v.z, min, max));
}

inline Vector Min(const Vector& v1, const Vector& v2)
{
    return Vector(Min(v1.x, v2.x),
        Min(v1.y, v2.y),
        Min(v1.z, v2.z));
}

inline Vector Max(const Vector& v1, const Vector& v2)
{
    return Vector(Max(v1.x, v2.x),
        Max(v1.y, v2.y),
        Max(v1.z, v2.z));
}

inline float DistanceBetween(const Vector& v1, const Vector& v2)
{
    Vector distance = v1 - v2;
    return distance.Length();
}

inline float DistanceBetweenSquared(const Vector& v1, const Vector& v2)
{
    Vector distance = v1 - v2;
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

inline float& Vector::operator[](int i)
{
    if (i == 0) {
        return x;
    }
    else if (i == 1) {
        return y;
    }
    else if (i == 2) {
        return z;
    }
    else {
        assert("[] Access error!");
    }
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
    return Sqrt(LengthSquared());
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

