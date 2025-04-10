#pragma once
#include "math/Vector3.h"
#include "math/Utils.h"
#include "Ray.h"

class Renderer
{
public:
    static float Sphere(const math::Vector3 &center, float radius, const Ray &r)
    {
        math::Vector3 origin = r.GetOrigin();
        math::Vector3 direction = r.GetDirection();
        math::Vector3 oc = center - origin;

        float a = math::dot(direction, direction);
        float b = -2.0 * (math::dot(direction, oc));
        float c = math::dot(oc, oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
        {
            return -1.0;
        }
        else
        {
            return (-b - std::sqrt(discriminant)) / (2.0 * a);
        }
    }
};