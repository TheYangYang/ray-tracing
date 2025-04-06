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

    math::Vector3 GetDirection() const { return m_Direction; }
    math::Vector3 GetOrigin() const { return m_Origin; }

    math::Vector3 At(float t) const { return m_Origin + t * m_Direction; }

private:
    math::Vector3 m_Origin;
    math::Vector3 m_Direction;
};