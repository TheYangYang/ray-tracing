#pragma once
#include "pch.h"
#include "Ray.h"
#include "Interval.h"

struct HitInfo
{
    math::Vector3 point;
    math::Vector3 normal;

    double t;
    bool isFrontFace;
    const void *renderer = nullptr;
    // OutNormal should be unit vector
    void SetFaceNormal(const Ray &ray, const math::Vector3 &outNormal)
    {
        isFrontFace = dot(ray.GetDirection(), outNormal) < 0;
        normal = isFrontFace ? outNormal : -outNormal;
    }
};

template <typename Derived>
class RendererCRTP
{
public:
    bool Hit(const Ray &ray, Interval rayT, HitInfo &hitInfo) const
    {
        return static_cast<const Derived *>(this)->Hit(ray, rayT, hitInfo);
    }

    math::Vector3 GetAlbedo() const
    {
        return static_cast<const Derived *>(this)->GetAlbedo();
    }
};