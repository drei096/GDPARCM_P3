#include "Utils.h"
#include <stdlib.h>

float Utils::randomFloat(float a, float b)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

int Utils::randomInt(int a, int b)
{
    int random = rand() / RAND_MAX;
    int diff = b - a;
    int r = random * diff;
    return a + r;
}
