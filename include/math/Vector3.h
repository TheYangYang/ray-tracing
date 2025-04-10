#pragma once
#include <iostream>
#ifdef __linux__
#include <cmath>
#endif

namespace math
{
    class Vector3
    {
    public:
        union
        {
            struct
            {
                float x, y, z;
            };
            struct
            {
                float r, g, b;
            }; 
        };

        Vector3() noexcept : x(0), y(0), z(0) {};
        Vector3(float value) noexcept : x(value), y(value), z(value) {};
        Vector3(float x, float y, float z) noexcept : x(x), y(y), z(z) {};
        ~Vector3() noexcept = default;

        Vector3 &operator=(const Vector3 &) noexcept = default;
        Vector3(const Vector3 &) noexcept = default;

        Vector3 operator-() const noexcept
        {
            return Vector3(-x, -y, -z);
        }

        Vector3 operator+(const Vector3 &other) const noexcept
        {
            return Vector3(x + other.x, y + other.y, z + other.z);
        }

        Vector3 operator-(const Vector3 &other) const noexcept
        {
            return Vector3(x - other.x, y - other.y, z - other.z);
        }

        Vector3 operator/(const float scalar) const noexcept
        {
            return Vector3(x / scalar, y / scalar, z / scalar);
        }

        Vector3 operator*(const float scalar) const noexcept
        {
            return Vector3(x * scalar, y * scalar, z * scalar);
        }

        friend Vector3 operator*(const float scalar, const Vector3 &v) noexcept
        {
            return Vector3(v.x * scalar, v.y * scalar, v.z * scalar);
        }

        Vector3 &operator+=(const Vector3 &other) noexcept
        {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            return *this;
        }

        Vector3 &operator-=(const Vector3 &other) noexcept
        {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
            return *this;
        }

        Vector3 &operator*=(const Vector3 &other) noexcept
        {
            this->x *= other.x;
            this->y *= other.y;
            this->z *= other.z;
            return *this;
        }

        Vector3 &operator/=(float scalar) noexcept
        {
            this->x /= scalar;
            this->y /= scalar;
            this->z /= scalar;
            return *this;
        }

        float Magnitude() const noexcept
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        Vector3 Normalized() const noexcept
        {
            float mag = Magnitude();
            if (mag == 0)
                return Vector3(0);
            return *this / mag;
        }

        friend std::ostream &operator<<(std::ostream &os, const Vector3 &v) noexcept
        {
            os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
            return os;
        }
    };
}