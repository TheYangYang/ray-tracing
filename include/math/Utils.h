#pragma once

namespace math
{
    static float randomFloat(float min, float max)
    {
        return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
    }

}