#include "Renderer.h"

class Sphere : public Renderer
{
public:
    Sphere() = delete;
    Sphere(const math::Vector3 &center, float radius);
    ~Sphere() = default;
    bool Hit(const Ray& ray, float rayTMin, float rayTMax, HitInfo& info) const override;
private:
    math::Vector3 center;
    float radius;
};