#include "Ray.h"

Ray::Ray()
    : m_Origin(math::Vector3()), m_Direction(math::Vector3())
{

}

Ray::Ray(const math::Vector3& origin, const math::Vector3& direction)
    :m_Origin(origin), m_Direction(direction)
{

}