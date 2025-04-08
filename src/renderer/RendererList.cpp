#include "renderer/RendererList.h"

RendererList::RendererList(std::shared_ptr<Renderer> renderer)
{
    AddRenderer(renderer);
}

void RendererList::AddRenderer(std::shared_ptr<Renderer> renderer)
{
    renderers.push_back(renderer);
}

bool RendererList::Hit(const Ray& ray, float rayTMin, float rayTMax, HitInfo& info) const 
{
    HitInfo tempHitInfo;
    bool isHitting = false;
    float closest = rayTMax;

    for(const auto& renderer: renderers)
    {
        if(renderer->Hit(ray, rayTMin, closest, tempHitInfo))
        {
            isHitting = true;
            closest = tempHitInfo.t;
            info = tempHitInfo;
        }
    }

    return isHitting;
}