#include <stdio.h>

int main()
{
    int i, fact;
    int N;
    int retval = scanf("%d", &N);
    int errorFlag = 0;
    while (retval > 0)
    {
        if (N < 0)
        {
            fprintf(stderr, "This is a negative number. Cannot compute the factorial");
            errorFlag = 1;
        }
        else
        { 
            i = fact = 1;
            while (i<=N)
            {
                fact = fact * i;
                if (fact == N)
                {
                    printf("%d = %d!\n", N, fact);
                    i = N + 2;
                
                }
                else
                {
                    i++;
                }
            }
            if (i == (N+1) )
            {
                printf("%d not factorial\n", N);
                
            }
        }
        retval = scanf("%d", &N);

    }

    if (retval == 0)
    {
        return 1;
    }
    else if (errorFlag == 1)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
    
}