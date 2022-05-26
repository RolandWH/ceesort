/*
 * Filename: ceesort.c
 * Author(s): Roland (r.weirhowell@gmail.com)
 * Description: Main file to handle I/O and calling fucntions
 * License: MIT (https://spdx.org/licenses/MIT.html)
*/

#include "bubble.h"
#include "bsrch.h"
#include "ccolour/colour.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


inline void quit_err(const char* msg)
{
    ChangeColour(msg, RED_FOREGROUND, DEFAULT_COLOR, true);
    exit(EXIT_FAILURE);
}


bool isint(char* s)
{
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '-' && isdigit(s[i + 1])) continue;
        if (!isdigit(s[i])) return false;
    }

    return true;
}


int main(int argc, char** argv)
{
    if (argc < 2)
        quit_err("ERROR: Must have at least one argument (number)\n");

    int* arr = malloc((argc - 1) * sizeof(int));
    for (int i = 1; i < argc; i++)
    {
        if (!isint(argv[i]))
        {
            puts("Sorry but arguments must be integers");
            return 1;
        }
        arr[i - 1] = atoi(argv[i]);
    }
    int n = argc - 1;

    char choice_str[16];
    printf(
        "1. Binary search\n"
        "2. Bubble sort\n"
        "Please pick a mode of operation: "
    );
    scanf("%s", choice_str);

    // TODO: Add checking that number is in range
    while (!isint(choice_str))
    {
        printf("Sorry but you must enter a number between 1 and 2\n");
        printf("Try again: ");
        scanf("%s", choice_str);
    }
    int choice = atoi(choice_str);

    if (choice == 1)
    {
        char target_str[16];
        printf("Enter number to search for: ");
        scanf("%s", target_str);
        while (!isint(target_str))
        {
            printf("Sorry but you must enter a whole number, try again: ");
            scanf("%s", target_str);
        }
        int target = atoi(target_str);

        int result = bsrch(target, arr, n);
        if (result == -1)
            puts("Value not found");
        else
            printf("Value found at index: %d\n", result);
    }
    else if (choice == 2)
    {
        bubblesort(arr, n);

        printf("Here is your sorted list:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d", arr[i]);
            if (i < n - 1) printf(", ");
        }
        putchar('\n');
    }
    
    free(arr);
    return 0;
}
