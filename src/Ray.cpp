#include "Ray.h"

Ray::Ray()
    : m_Origin(math::Vector3<float>()), m_Direction(math::Vector3<float>())
{

}

Ray::Ray(const math::Vector3<float>& origin, const math::Vector3<float>& direction)
    :m_Origin(origin), m_Direction(direction)
{

}