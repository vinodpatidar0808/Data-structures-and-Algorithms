#ifndef _GENERATE_ARRAY_H_
#define _GENERATE_ARRAY_H_

#include <iostream>
#include <vector>
#include "getRandomNumber.h"

void generateRandomArray(int arr[], int n, int minValue, int maxValue)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = getRandom(minValue, maxValue);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif