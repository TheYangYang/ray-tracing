#pragma once
#include "math/Vector3.h"

class Camera
{
public:
    Camera();
    ~Camera();

    const math::Vector3 &GetCameraCenter() const { return cameraCenter; }
    float GetFocalLength() const { return focalLength; }

private:
    math::Vector3 cameraCenter;
    float focalLength;
};