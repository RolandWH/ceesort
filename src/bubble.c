#include "bubble.h"

#include <stdbool.h>


void bubblesort(int* arr, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        for (int elem = 0; elem < n - 1 - i; elem++)
        {
            if (arr[elem] > arr[elem + 1])
            {
                int temp = arr[elem];
                arr[elem] = arr[elem + 1];
                arr[elem + 1] = temp;
            }
        }
    }
}
