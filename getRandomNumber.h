#ifndef RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include <time.h>

// return a random number between range [minValue, maxValue)
int getRandom(int minValue, int maxValue)
{
    // srand(time(0));
    return (rand() % (maxValue - minValue)) + minValue;
}

// return a random even number between range [minValue, maxValue
int getRandomEven(int minValue, int maxValue)
{
    int val = (rand() % (maxValue - minValue)) + minValue;
    if (val & 1 )
        return val -1;
    return val;
}

// return a random odd number between range [minValue, maxValue
int getRandomOdd(int minValue, int maxValue)
{
    int val = (rand() % (maxValue - minValue)) + minValue;
    if (val & 1 == 0)
        return val -1;
    return val;
}

#endif