/*
 * Filename: bsrch.c
 * Author(s): Roland (r.weirhowell@gmail.com)
 * Description: Perform binary search on an integer array
 * License: MIT (https://spdx.org/licenses/MIT.html)
*/

#include "bsrch.h"

#include <stdbool.h>
#include <stddef.h>


int bsrch(int target, int* arr, int n)
{
    // TODO: Find a way to error if list is out of order
    int start = 0, end = n - 1;
    if (arr[start] > target || arr[end] < target) return -1;
    int mid = (start + end) / 2;

    while (true)
    {
        if (arr[mid] == target) break;
        if (start == end) return -1;
        if (mid == end) return -1;
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
