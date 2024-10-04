#include <stdio.h>
#include <ctype.h> 

int validate_base(int base)
{
    if (base < 2 || base > 36)
    {
        fprintf(stderr, "Invalid integer literal\n");
        return (0);
    }
    return (1);
}


int convert_char_to_value(char c, int base)
{
    
    if (c >= 'a' && c <= 'z')
    {
        c = c - 'a' + 'A';
    }
    int value;

    if (c >= 'A')
    {
        value = c - 'A' + 10;
    }
    else
    {
        value = c - '0';
    }
    
    
    if (value >= base)
    {
        fprintf(stderr, "Invalid string literal, too big!\n");
        return (-1);  
    }

    return value;
}

unsigned long int convert_string(char *str, int base)
{
    unsigned long int result = 0;  

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isalnum(str[i]))
        {
            fprintf(stderr, "Invalid string literal\n");
            return 0;
        }
        int value = convert_char_to_value(str[i], base);
        if (value == -1)
        {
            return 0;  
        }
        result = result * base + value;
    }

    return result;
}


int main()
{
    int base;
    int retval = scanf("%d", &base);
    int flag = 0;

    if (retval == 0)
    {
        fprintf(stderr, "Invalid integer literal\n");
        return (1);
    }
    else if (retval == -1)
    {
        return (0);
    }

    if (!validate_base(base))
    {
       return (1);
    }

    char str[64];

    while (scanf("%63s", str) != EOF)
    {
        unsigned long int result = convert_string(str, base);

        if (result == 0)
        {
            flag = 1;  
        }
        else
        {
            printf("%lu\n", result); 
        }
    }
    return flag;
}
