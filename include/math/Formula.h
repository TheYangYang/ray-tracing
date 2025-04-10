#pragma once
#include "Vector3.h"
namespace math
{
 
    static float dot(const Vector3 &first, const Vector3 &second) noexcept
    {
        return first.x * second.x + first.y * second.y + first.z * second.z;
    }

    static Vector3 cross(const Vector3 &first, const Vector3 &second) noexcept
    {
        return Vector3(
            first.y * second.z - first.z * second.y,
            first.z * second.x - first.x * second.z,
            first.x * second.y - first.y * second.x);
    }

    static Vector3 randomUnitVec3()
    {
        while (true) {
            auto p = Vector3::random(-1,1);
            auto lensq = p.Magnitude() * p.Magnitude();
            if (1e-160 < lensq && lensq <= 1)
                return p / sqrt(lensq);
        }
    }

    static Vector3 random_on_hemisphere(const Vector3& normal) {
        Vector3 on_unit_sphere = randomUnitVec3();
        if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
            return on_unit_sphere;
        else
            return -on_unit_sphere;
    }
}