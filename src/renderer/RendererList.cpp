#include "renderer/RendererList.h"

RendererList::RendererList(Ref<RendererWrapper> renderer)
{
    AddRenderer(renderer);
}

void RendererList::AddRenderer(Ref<RendererWrapper> renderer)
{
    renderers.push_back(renderer);
}

bool RendererList::Hit(const Ray& ray, Interval rayT, HitInfo& hitInfo) const 
{
    HitInfo tempHitInfo;
    bool isHitting = false;
    float closest = rayT.GetMax();

    for(const auto& renderer: renderers)
    {
        if(renderer->Hit(ray, Interval(rayT.GetMin(), closest), tempHitInfo))
        {
            isHitting = true;
            closest = tempHitInfo.t;
            hitInfo = tempHitInfo;
        }
    }

    return isHitting;
}