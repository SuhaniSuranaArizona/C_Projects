#include <stdio.h>
#include <ctype.h> // For isalnum()

// Function to validate the base
int validate_base(int base)
{
    if (base < 2 || base > 36)
    {
        fprintf(stderr, "Invalid integer literal\n");
        return 0;
    }
    return 1;
}

// Function to convert a character to its numerical value based on base
int char_to_value(char ch)
{
    if (ch >= 'a' && ch <= 'z') // Convert lowercase to uppercase
    {
        ch = ch - 'a' + 'A';
    }

    if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 10; // Alphabet characters
    }
    else if (ch >= '0' && ch <= '9')
    {
        return ch - '0'; // Numeric digits
    }

    return -1; // Invalid character
}

// Function to process the string and return the result in the given base
int process_string(char *str, int base, unsigned long int *result, int *flag)
{
    *flag = 0;
    *result = 0;  // Starting value of result

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isalnum(str[i]))
        {
            fprintf(stderr, "Invalid string literal\n");
            *flag = 1;
            return 0;
        }

        int pos = char_to_value(str[i]);

        if (pos == -1 || pos >= base)
        {
            fprintf(stderr, "Invalid string literal, too big!\n");
            *flag = 1;
            return 0;
        }

        *result = (*result * base) + pos; // Accumulate the result
    }

    return 1; // Success
}

// Main function to handle input and call helper functions
int main()
{
    int base;
    int retval = scanf("%d", &base);
    if (retval == 0)
    {
        fprintf(stderr, "Invalid integer literal\n");
        return 1;
    }
    else if (retval == -1)
    {
        return 0;
    }

    if (!validate_base(base))
    {
        return 1;
    }

    char str[64];
    int flag = 0;

    // Read strings in a loop
    while (scanf("%63s", str) != EOF)
    {
        unsigned long int result = 1;
        if (process_string(str, base, &result, &flag))
        {
            printf("%lu\n", result); // Print result if successful
        }
        
    }

    return 0;
}
