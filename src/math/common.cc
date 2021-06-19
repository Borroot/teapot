#include <cstdarg>
#include "math/common.hh"

double min(unsigned int count, ...)
{
    va_list list;
    va_start(list, count);

    double min;
    for (unsigned int i = 0; i < count; i++)
    {
        double current = va_arg(list, double);
        if (current < min)
            min = current;
    }

    va_end(list);
    return min;
}

double max(unsigned int count, ...)
{
    va_list list;
    va_start(list, count);

    double max;
    for (unsigned int i = 0; i < count; i++)
    {
        double current = va_arg(list, double);
        if (current > max)
            max = current;
    }

    va_end(list);
    return max;
}

int abs(int n) {
    return n >= 0 ? n : -n;
}