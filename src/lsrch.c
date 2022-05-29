/*
 * Filename: lsrch.c
 * Author(s): Roland (r.weirhowell@gmail.com)
 * Description: Perform linear search on an integer array
 * License: MIT (https://spdx.org/licenses/MIT.html)
*/

#include "lsrch.h"

int lsrch(int* arr, int n, int target)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == target) return i;

    return -1;
}
