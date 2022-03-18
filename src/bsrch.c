#include "bsrch.h"

#include <stddef.h>
#include <stdbool.h>
#include <math.h>


int bsrch(int target, int* arr, size_t n)
{
    bool found = false;
    int start = 0, end = n - 1;
    if (arr[start] > target || arr[end] < target) return -1;
    int mid = round((start + end) / (double)2);

    while (!found)
    {
        if (arr[mid] == target) found = true;
        if (start == end && !found) return -1;
        else if (arr[mid] < target)
        {
            start = mid + 1;
            mid = roundf((start + end) / (float)2);
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
            mid = roundf((start + end) / (float)2);
        }
    }

    return mid;
}
