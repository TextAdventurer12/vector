#include "vector.h"
#include <stdio.h>

int main(void)
{
    make_vec(testVector, intVector);
    for (int i = 0; i < 32; i++)
    {
        push_back(testVector, i, int);
    }
    for (int i = 0; i < 32; i++)
    {
        printf("%d", i);
    }
}