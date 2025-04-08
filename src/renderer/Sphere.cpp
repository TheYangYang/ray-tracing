#include "renderer/Sphere.h"

Sphere::Sphere(const math::Vector3 &center, float radius)
    : center(center), radius(radius)
{
}

bool Sphere::Hit(const Ray &ray, float rayTMin, float rayTMax, HitInfo &info) const
{
    math::Vector3 oc = center - ray.GetOrigin();
    float a = math::dot(ray.GetDirection(), ray.GetDirection());
    float h = math::dot(ray.GetDirection(), oc);
    float c = math::dot(oc, oc) - radius * radius;

    float discriminant = h * h - a * c;
    if (discriminant < 0)
    {
        return false;
    }

    float sqrtDiscriminant = std::sqrt(discriminant);

    // Calculate nearest root that lies in the acceptable range
    float root = (h - sqrtDiscriminant) / a;
    if (root <= rayTMin || root >= rayTMax)
    {
        root = (h + sqrtDiscriminant) / a;
        if (root <= rayTMin || rayTMax <= root)
        {
            return false;
        }
    }


    info.t = root;
    info.point = ray.At(info.t); // Get hit point
    math::Vector3 outNormal = (info.point - center) / radius;
    info.SetFaceNormal(ray, outNormal);

    return true;
}