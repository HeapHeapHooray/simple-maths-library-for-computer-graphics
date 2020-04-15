#ifndef COMMONS_H
#define COMMONS_H
#include <math.h>

inline float convertToRadians(const float degrees)
{
    return degrees * (M_PI/180.0f);
}

#endif