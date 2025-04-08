#include "Ray.h"

Ray::Ray()
    : origin(math::Vector3()), direction(math::Vector3())
{

}

Ray::Ray(const math::Vector3& origin, const math::Vector3& direction)
    :origin(origin), direction(direction)
{

}