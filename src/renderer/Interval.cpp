#include "renderer/Interval.h"

const Interval Interval::s_empty = Interval(+infinity, -infinity);
const Interval Interval::s_universe = Interval(-infinity, +infinity);

Interval::Interval()
    : minValue(+infinity), maxValue(-infinity)
{
}

Interval::Interval(float min, float max)
    : minValue(min), maxValue(max)
{
}