#include "bsrch.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{
    int* arr = malloc((argc - 1) * sizeof(int));
    for (int i = 1; i < argc; i++)
    {
        arr[i - 1] = atoi(argv[i]);
    }

    int target;
    printf("Enter number to search for: ");
    scanf("%d", &target);
    int result = bsrch(target, arr, argc - 1);

    if (result != -1)
    {
        printf("Value found at index: %d\n", result);
    }
    else
    {
        printf("Value not found\n");
    }
    
    return 0;
}
