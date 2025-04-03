#pragma once
#include <iostream>
#include "math/Vector3.h"
#include "Camera.h"
#include "Ray.h"

class Canvas
{
public:
    static Canvas &GetInstance(uint32_t width, uint32_t height, Camera& camera);
    ~Canvas();

    const uint32_t GetWidth() const { return m_Width; }
    const uint32_t GetHeight() const { return m_Height; }
    void Draw();
    const float GetAspectRatio() const { return m_Width / static_cast<float>(m_Height); }

private:
    Canvas() = delete;
    Canvas(uint32_t width, uint32_t height, Camera& camera);
    Canvas &operator=(const Canvas &) = delete;
    Canvas(const Canvas &) = delete;
    void writeColor(std::ofstream& file, const math::Vector3<float>& color);
    math::Vector3<float> RayColor(const Ray& r);

private:
    uint32_t m_Width;
    uint32_t m_Height;

    float m_ViewportWidth;
    float m_ViewportHeight;

    math::Vector3<float> m_ViewportU;
    math::Vector3<float> m_ViewportV;

    math::Vector3<float> m_PixelDeltaU;
    math::Vector3<float> m_PixelDeltaV;

    Camera& m_Camera;

    math::Vector3<float> m_PixelPosition;
};