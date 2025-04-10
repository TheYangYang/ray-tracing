#pragma once
#include "pch.h"
#include "Camera.h"
#include "Ray.h"

#include "renderer/RendererList.h"
#include "renderer/Sphere.h"

class Canvas
{
public:
    static Canvas &GetInstance();
    ~Canvas();

    const uint32_t GetWidth() const { return width; }
    const uint32_t GetHeight() const { return height; }
    void Draw(std::vector<uint8_t>& framebuffer);
    const float GetAspectRatio() const { return width / static_cast<float>(height); }
    void Initialize(uint32_t width, uint32_t height, Camera camera);
public:
    Canvas() = default;
    Canvas &operator=(const Canvas &) = delete;
    Canvas(const Canvas &) = delete;

    math::Vector3 RayColor(const Ray &r, int bounces);

public:
    uint32_t width;
    uint32_t height;

    float viewportWidth;
    float viewportHeight;

    math::Vector3 viewportU;
    math::Vector3 viewportV;

    math::Vector3 pixelDeltaU;
    math::Vector3 pixelDeltaV;

    Camera camera;

    math::Vector3 pixelPosition;


    RendererList world;

    int bounces = 5;

    std::vector<uint32_t> framebufferCache;
    int frameNum = 1;

};
