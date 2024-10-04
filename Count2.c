/*
* File: count.c
* Author: Suhani Surana
* Purpose: This program computes the count of
* numbers appearing in the array of integers
*/


#include <stdio.h>
#include <stdlib.h>

/* checkArray -- returns the index value of the place where we find that number 
*/

int checkArray(int *keys, int *values, int size, int number)
{
    for (int j = 0; j < size; j++)
    {
        if (keys[j] == number)
        {

            return j; 
        }
        else if (values[j] != 0)
        {
            continue;
        }
        else
        {
            return j;
        }
    }
    return -1;
}
/* printresults -- prints the number of times that number comes
* in the integer array.
*/
void printresults(int *keys, int *values, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (values[i] != 0)
        {
            printf("%d %d\n", keys[i], values[i]);
        }
    }
}

int main()
{
    int size;
    int retval = scanf("%d", &size);
    if (retval != 1 || size <= 0)
    {
        fprintf(stderr, "Error: The first integer value is not positive or cannot be read.\n");
        return 1;
    }

    int *keys = calloc(size, sizeof(int));
    int *values = calloc(size, sizeof(int));

    if (keys == NULL || values == NULL)
    {
        fprintf(stderr, "Out of Memory");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        int number;
        retval = scanf("%d", &number);
        if (retval != 1)
        {
            fprintf(stderr, "Invalid integer literal or lesser integers provided\n");
            return 1;
        }

        int result = checkArray(keys, values, size, number);
        keys[result] = number;
        values[result] += 1;
    }

    printresults(keys, values, size);

    return 0;
}
