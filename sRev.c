#include <stdio.h>

int main()
{
    
    int N;
    int retval = scanf("%d", &N);
    int errorFlag = 0;
    while (retval > 0)
    {
        if (N < 0)
        {
            fprintf(stderr, "This is a negative number. Cannot compute the sum reverse");
            errorFlag = 1;
        }
        else
        {   int copy = N;
            int rev = 0;
            while (copy > 0)
            {
                int digit = copy % 10;
                rev = (rev)*10 + digit;
                copy = copy / 10;

            }

            int sum = N + rev;
            printf("%d\n", sum);
                
            
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