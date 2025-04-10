#pragma once
#include "math/Vector3.h"

class Ray
{
public:
    Ray();
    Ray(const math::Vector3 &origin, const math::Vector3 &direction);
    ~Ray() = default;

    Ray(const Ray &) = default;
    Ray &operator=(const Ray &) = default;

    math::Vector3 GetDirection() const { return direction; }
    math::Vector3 GetOrigin() const { return origin; }

    math::Vector3 At(float t) const { return origin + t * direction; }

private:
    math::Vector3 origin;
    math::Vector3 direction;
};