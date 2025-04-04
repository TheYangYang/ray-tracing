#pragma once
#include <iostream>

namespace math
{
    template <typename T>
    class Vector3
    {
    public:
        T x, y, z;

        Vector3() : x(0), y(0), z(0) {};
        Vector3(T value) : x(value), y(value), z(value) {};
        Vector3(T x, T y, T z) : x(x), y(y), z(z) {};
        ~Vector3() = default;

        Vector3 &operator=(const Vector3 &) = default;
        Vector3(const Vector3 &) = default;

        Vector3 operator-() const
        {
            return Vector3(-x, -y, -z);
        }

        Vector3 operator+(const Vector3 &other) const
        {
            return Vector3(x + other.x, y + other.y, z + other.z);
        }

        Vector3 operator-(const Vector3 &other) const
        {
            return Vector3(x - other.x, y - other.y, z - other.z);
        }

        Vector3 operator/(const T scalar) const
        {
            return Vector3(x / scalar, y / scalar, z / scalar);
        }

        Vector3 operator*(const T scalar) const
        {
            return Vector3(x * scalar, y * scalar, z * scalar);
        }

        friend Vector3 operator*(const T scalar, const Vector3 &v)
        {
            return Vector3(v.x * scalar, v.y * scalar, v.z * scalar);
        }

        Vector3 &operator+=(const Vector3 &other)
        {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            return *this;
        }

        Vector3 &operator-=(const Vector3 &other)
        {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
            return *this;
        }

        Vector3 &operator*=(const Vector3 &other)
        {
            this->x *= other.x;
            this->y *= other.y;
            this->z *= other.z;
            return *this;
        }

        Vector3 &operator/=(float scalar)
        {
            this->x /= scalar;
            this->y /= scalar;
            this->z /= scalar;
            return *this;
        }

        T Magnitude() const
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        Vector3 Normalized() const
        {
            T mag = Magnitude();
            return *this / mag;
        }

        friend std::ostream &operator<<(std::ostream &os, const Vector3 &v)
        {
            os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
            return os;
        }
    };

}