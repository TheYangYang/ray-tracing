#pragma once
#include "pch.h"
#include "renderer/Renderer.h"

class RendererList : public Renderer
{
public:

    RendererList() = default;
    RendererList(Ref<Renderer> renderer);
    ~RendererList() = default;

    void AddRenderer(Ref<Renderer> renderer);
    bool Hit(const Ray &ray, Interval rayT, HitInfo &hitInfo) const override;
private:
    std::vector<Ref<Renderer>> renderers;
};