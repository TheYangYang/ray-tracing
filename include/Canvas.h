#pragma once
#include "pch.h"
#include <iostream>
#include "math/Vector3.h"
#include "Camera.h"
#include "Ray.h"

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

    math::Vector3<float> RayColor(const Ray &r);

public:
    uint32_t width;
    uint32_t height;

    float viewportWidth;
    float viewportHeight;

    math::Vector3<float> viewportU;
    math::Vector3<float> viewportV;

    math::Vector3<float> pixelDeltaU;
    math::Vector3<float> pixelDeltaV;

    Camera camera;

    math::Vector3<float> pixelPosition;
};
