#pragma once
#include "pch.h"

class Interval
{
public:
    Interval();
    Interval(float min, float max);

    float Size() const { return maxValue - minValue; }
    float Contains(float x) const { return minValue <= x && x <= maxValue; }
    float Surrounds(float x) const { return minValue < x && x < maxValue; }

    static const Interval s_empty, s_universe;

    float GetMin() const { return minValue; }
    float GetMax() const { return maxValue; }

private:
    float minValue, maxValue;
};