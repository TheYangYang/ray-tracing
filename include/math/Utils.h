#pragma once

namespace math
{
    static float randomFloat(float min, float max)
    {
        return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
    }

    static float linearToGamma(float linearComponent)
    {
        if (linearComponent > 0)
            return std::sqrt(linearComponent);

        return 0;
    }

}