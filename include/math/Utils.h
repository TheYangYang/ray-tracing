#pragma once
#include "Vector3.h"
namespace math
{
    template <typename T>
    float dot(const Vector3<T> &first, const Vector3<T> &second)
    {
        return first.x * second.x + first.y * second.y + first.z * second.z;
    }

    template<typename T>
    Vector3<T> cross(const Vector3<T> &first, const Vector3<T> &second) 
    {
        return Vector3<T>(
            first.y * second.z - first.z * second.y,
            first.z * second.x - first.x * second.z,
            first.x * second.y - first.y * second.x);
    }
}