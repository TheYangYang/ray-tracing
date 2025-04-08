#pragma once
#include "pch.h"
#include "Ray.h"

struct HitInfo
{
    math::Vector3 point;
    math::Vector3 normal;
    double t;
    bool isFrontFace;

    // OutNormal should be unit vector
    void SetFaceNormal(const Ray& ray, const math::Vector3& outNormal)
    {
        isFrontFace = dot(ray.GetDirection(), outNormal) < 0;
        normal = isFrontFace ? outNormal : -outNormal;
    }
};

class Renderer
{
public:
    Renderer() = default;
    virtual ~Renderer() = default;
    virtual bool Hit(const Ray& ray, float rayTMin, float rayTMax, HitInfo& hitInfo) const = 0;
};