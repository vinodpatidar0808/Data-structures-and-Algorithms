#ifndef RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include <time.h>

int getRandom(int minValue, int maxValue)
{
    // srand(time(0));
    return (rand() % (maxValue - minValue)) + minValue;
}

#endif