/*
* File: getPrime.c
* Author: Suhani Surana
* Purpose: Defines a function to compute the smallest prime number after 
* the inputted number.
* 
*/


#include <stdio.h>
#include <math.h>

/*
*
*This main function computes the smallest prime number bigger than the input 
* value.
*/

int main()
{
    int N;
    int errorFlag = 0;
    int retval = scanf("%d", &N);

    if (N < 0)
    {
        fprintf(stderr, "This is a negative number. Cannot compute the factorial");
        errorFlag = 1;
    }

    int num = N + 1;
    int flag = 1;
    if (retval > 0)
    {
        while (flag == 1)
        {
            if (num == 1)
            {
                num += 1;
            }
            int flagNum = 0;
            for (int i = 2; i <= sqrt(num); i++)
            {
                if (num % i == 0)
                {
                    flagNum = 1;
                }
            }

            if (flagNum == 1)
            {
                num += 1;
            }
            else
            {
                flag = 0;
            }
        }

        
        printf("%d\n", num);
    }

    if (retval == 0)
    {
        fprintf(stderr, "This is not a valid input\n");
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
