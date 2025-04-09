#pragma once
#include "pch.h"
#include "renderer/Renderer.h"

class RendererList : public Renderer
{
public:
    std::vector<Ref<Renderer>> renderers;

    RendererList() = default;
    RendererList(Ref<Renderer> renderer);
    ~RendererList() = default;

    void AddRenderer(Ref<Renderer> renderer);
    bool Hit(const Ray &ray, float rayTMin, float rayTMax, HitInfo &hitInfo) const override;
};