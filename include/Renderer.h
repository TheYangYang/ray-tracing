#pragma once
#include "math/Vector3.h"
#include "math/Utils.h"
#include "Ray.h"

class Renderer
{
public:
    static bool Sphere(const math::Vector3<float> &center, float radius, const Ray &r)
    {
        math::Vector3<float> origin = r.GetOrigin();
        math::Vector3<float> direction = r.GetDirection();
        math::Vector3<float> &oc = center - origin;

        float a = math::dot(direction, direction);
        float b = -2.0 * (math::dot(direction, oc));
        float c = math::dot(oc, oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;
        return (discriminant >= 0);
    }
};