#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    int retval = scanf("%d", &size);
    if (retval != 1)
    {
        fprintf(stderr, "Invalid integer literal\n");
        return 1;
    }

    int *A = calloc(size, sizeof(int));

    if (A == NULL)
    {
        fprintf(stderr, "Out of Memory");
        return 1;
    }

    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        int number;
        retval = scanf("%d", &number);

        if (retval != 1)
        {
            fprintf(stderr, "Invalid integer literal or lesser integers provided\n");
            flag = 1;
        }
        else
        {

            A[i] = number;
        }
    }

    int move;
    int retval = scanf("%d", &move);
    if (retval != 1)
    {
        fprintf(stderr, "Invalid integer literal\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        int *B = calloc(size, sizeof(int));
        if (B == NULL)
        {
            fprintf(stderr, "Out of Memory");
            return 1;
        }

        for (int j = 1; j < move; j++)
        {

        }

        
        {
            int j;
            for (j = 1; j < number)
                moveArrayNegative(*A, *B, )
        }
    }
}

return flag;
