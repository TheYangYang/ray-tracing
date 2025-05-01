#pragma once
#include "pch.h"
#include "renderer/Renderer.h"
#include "renderer/RendererWrapper.h"

class RendererList
{
public:
    RendererList() = default;
    RendererList(Ref<RendererWrapper> renderer);
    ~RendererList() = default;

    void AddRenderer(Ref<RendererWrapper> renderer);
    bool Hit(const Ray &ray, Interval rayT, HitInfo &hitInfo) const;
private:
    std::vector<Ref<RendererWrapper>> renderers;
};