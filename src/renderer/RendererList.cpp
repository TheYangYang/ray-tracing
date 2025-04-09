#include "renderer/RendererList.h"

RendererList::RendererList(Ref<Renderer> renderer)
{
    AddRenderer(renderer);
}

void RendererList::AddRenderer(Ref<Renderer> renderer)
{
    renderers.push_back(renderer);
}

bool RendererList::Hit(const Ray& ray, float rayTMin, float rayTMax, HitInfo& hitInfo) const 
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
            hitInfo = tempHitInfo;
        }
    }

    return isHitting;
}