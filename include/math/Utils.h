#pragma once
#include "Vector3.h"
namespace math
{

    static float dot(const Vector3 &first, const Vector3 &second)
    {
        return first.x * second.x + first.y * second.y + first.z * second.z;
    }

    static Vector3 cross(const Vector3 &first, const Vector3 &second) 
    {
        return Vector3(
            first.y * second.z - first.z * second.y,
            first.z * second.x - first.x * second.z,
            first.x * second.y - first.y * second.x);
    }
}