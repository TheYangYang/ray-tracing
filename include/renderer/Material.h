#pragma once
#include "Ray.h"
#include "Renderer.h"

class Material
{
public:
    virtual ~Material() = default;

    virtual bool Scatter(const Ray& rayIn, const HitInfo& hitInfo, math::Vector3& attenuation, Ray& scattered) const 
    {
        return false;
    }
};