/*
 * Filename: bsrch.c
 * Author(s): Roland (r.weirhowell@gmail.com)
 * Description: Perform binary search on an integer array
 * License: MIT (https://spdx.org/licenses/MIT.html)
*/

#include "bsrch.h"

#include <stdbool.h>
#include <stddef.h>


int bsrch(int target, int* arr, size_t n)
{
    // TODO: Find a way to error if list is out of order
    bool found = false;
    int start = 0, end = n - 1;
    if (arr[start] > target || arr[end] < target) return -1;
    int mid = (start + end) / 2;

    while (!found)
    {
        if (arr[mid] == target) found = true;
        if (start == end && !found) return -1;
        if (mid == end && !found) return -1;
        else if (arr[mid] < target)
        {
            start = mid + 1;
            mid = (start + end) / 2;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
            mid = (start + end) / 2;
        }
    }

    return mid;
}
