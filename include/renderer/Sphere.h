#pragma once
#include "Renderer.h"

class Sphere : public RendererCRTP<Sphere>
{
public:
    Sphere() = delete;
    Sphere(const math::Vector3 &center, float radius, const math::Vector3& albedo);
    ~Sphere() = default;
    bool Hit(const Ray& ray, Interval rayT, HitInfo& info) const;
private:
    math::Vector3 center;
    float radius;
    math::Vector3 albedo = math::Vector3(0.5f);
};