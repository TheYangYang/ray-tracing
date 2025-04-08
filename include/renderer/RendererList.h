#pragma once
#include "pch.h"
#include "renderer/Renderer.h"

class RendererList : public Renderer
{
public:
    using RendererVector = std::vector<std::shared_ptr<Renderer>>;
    RendererVector renderers;

    RendererList() = default;
    RendererList(std::shared_ptr<Renderer> renderer);
    ~RendererList() = default;

    void AddRenderer(std::shared_ptr<Renderer> renderer);
    bool Hit(const Ray &ray, float rayTMin, float rayTMax, HitInfo &info) const override;
};