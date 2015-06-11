#ifndef UTILITY
#define UTILITY

#include "audio_config.h"

sample operator+(sample a, sample b)
{
    sample16 result = a+b;
    return (sample) result/2;
}

sample operator*(sample a, sample b)
{
    sample16 result = a*b;
    return (sample) result/255;
}

#endif
