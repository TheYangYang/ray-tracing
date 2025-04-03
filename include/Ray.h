#pragma once
#include "math/Vector3.h"

class Ray
{
public:
    Ray();
    Ray(const math::Vector3<float> &origin, const math::Vector3<float> &direction);
    ~Ray() = default;

    Ray(const Ray &) = default;
    Ray &operator=(const Ray &) = default;

    math::Vector3<float> GetDirection() const { return m_Direction; }
    math::Vector3<float> GetOrigin() const { return m_Origin; }

    math::Vector3<float> At(float t) const { return m_Origin + t * m_Direction; }

private:
    math::Vector3<float> m_Origin;
    math::Vector3<float> m_Direction;
};