/*
 * Filename: bubble.c
 * Author(s): Roland (r.weirhowell@gmail.com)
 * Description: Perform bubble sort on an array of integers
 * License: MIT (https://spdx.org/licenses/MIT.html)
*/

#include "bubble.h"

#include <stdbool.h>


void bubblesort(int* arr, size_t n)
{
    bool swapped = true;

    for (int i = 0; i < n && swapped; i++)
    {
        for (int elem = 0; elem < n - 1 - i; elem++)
        {
            swapped = false;
            if (arr[elem] > arr[elem + 1])
            {
                swapped = true;
                int temp = arr[elem];
                arr[elem] = arr[elem + 1];
                arr[elem + 1] = temp;
            }
        }
    }
}
