#pragma once
#include "math/Vector3.h"

class Camera
{
public:
    Camera();
    ~Camera();

    const math::Vector3<float> &GetCameraCenter() const { return m_CameraCenter; }
    float GetFocalLength() const { return m_FocalLength; }

private:
    math::Vector3<float> m_CameraCenter;
    float m_FocalLength;
};