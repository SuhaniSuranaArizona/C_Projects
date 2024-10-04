#include <stdio.h>

int main()
{
    int base;
    int retval = scanf("%d", &base);
    if (retval == 0)
    {
        fprintf(stderr, "Invalid integer literal");
        return (1);
    }
    else if (retval == -1)
    {
        return (0);
    }
    else
    {
        if (base < 2 || base > 36)
        {
            fprintf(stderr, "Invalid integer literal");
            return (1);
        }

        char str[64];
        int flag = 0;
        
        while (scanf("%63s", str) != EOF)
        {

            int i;
            unsigned long int result = 1;
            int flag1 = 0;
            for (i = 0; str[i] != '\0'; i++)
            {
                if (!(isalnum(str[i])))
                {
                    fprintf(stderr, "Invalid string literal");
                    flag = 1;
                    flag1 = 1;
                    break;
                    
                }
                else
                {
                    if (str[i] >= 'a' && str[i] <= 'z')
                    {
                        str[i] = str[i] - 'a' + 'A';
                    }
                    int pos;
                    if (str[i] > 9)
                    {
                        pos = str[i] - 'A' + 10;
                    }
                    else
                    {
                        pos = str[i];
                    }

                    if (!(pos <= (base - 1)))
                    {
                        fprintf(stderr, "Invalid string literal, too big!");
                        flag = 1;
                        flag1 = 1;
                        break;
                        
                    }
                }

                if (flag1 == 0)
                {
                    int pos;
                    if (str[i] > 9)
                    {
                        pos = str[i] - 'A' + 10;
                    }
                    else
                    {
                        pos = str[i];
                    }
                    result = result * base + (pos - '0');
                }
            }
            printf("%d\n", result);
        }


     return(0);
    }
}

