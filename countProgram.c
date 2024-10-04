#include <stdio.h>
int checkArray (int *keys, int size, int number)
{
    int i = 0;
    int j;
    for (j = 0; j<size; j++)
    {
        if (keys[i] == number)
        {
            return(i);
        }
    }
    return (i);
}

void printresults (int *keys, int *values, int size)
{
    int i;
    for(int i = 0; i<size; i++)
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
    if (retval == 0)
    {
        fprintf(stderr, "Invalid integer literal\n");
        return 1;
    }
    else if (retval == -1)
    {
        return 0;
    }

    int *num;
    num = malloc(size * sizeof(int));

    if (num == NULL)
    {
        fprintf(stderr, "Out of Memory");
        return (1);
    }
    // read in the array
    int i;
    int *keys;
    int *values;

    keys = calloc(size * sizeof(int));
    values = calloc(size * sizeof(int));
    int flag = 0;

    for (i = 0; i < size; i++)
    {   
        int number;
        int retval = scanf("%d", &number);
        if (retval == 0)
        {
            fprintf(stderr, "Invalid integer literal\n");
            flag = 1;
        }
        else if (retval == -1)
        {
            fprintf(stderr, "Lesser Integers Provided\n");
            return 1;
        }
        else
        {
            int result = checkArray(*keys, size, number);
            keys[result] = number;
            values[result]+=1;
        }

    }
    printresults(*keys, *values, size);
    return (flag);
}

