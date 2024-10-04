/*
* File: anagrams.c
* Author: Suhani Surana
* Purpose: This program computes the anagrams of the first word
based on the inputs given without being case sensitive
*
*/

#include <stdio.h>
#include <ctype.h>

/* This function returns the frequency of a letter
in a string and it does that in a case sensitive
manner
*/

int getFrequency(char c[], char letter)
{
    int i;
    int frequency = 0; // Initialize frequency to 0

    for (i = 0; c[i] != '\0'; i++)
    {
        if (toupper(c[i]) == toupper(letter))
        {
            frequency++;
        }
    }
    return frequency;
}

int main()
{
    char str[64];
    char first[64];

    // Read the first string
    if (scanf("%63s", first) == EOF)
    {
        return 0;
    }

    for (int j = 0; first[j] != '\0'; j++)
    {
        if (!((first[j] >= 'a' && first[j] <= 'z') ||
              (first[j] >= 'A' && first[j] <= 'Z')))
        {
            fprintf(stderr, "Invalid string literal\n");
            return 1;
        }
    }

    printf("%s\n", first);
    int flag1 = 0;
    // Read subsequent strings and check if they are anagrams of the first string
    while (scanf("%63s", str) != EOF)
    {
        int i;
        int flag = 0;

        // Compare frequencies of characters in the current string to the first string
        for (i = 0; str[i] != '\0'; i++)
        {
            if (!((str[i] >= 'a' && str[i] <= 'z') ||
                  (str[i] >= 'A' && str[i] <= 'Z')))
            {
                fprintf(stderr, "Invalid string literal\n");
                flag1 = 1;
                flag = 1;
                break;
            }
            int freq1 = getFrequency(first, str[i]);
            int freq2 = getFrequency(str, str[i]);

            // If frequencies don't match, it's not an anagram
            if (freq1 != freq2)
            {
                flag = 1;
                break;
            }
        }

        // If the flag is still 0, then the strings are anagrams
        if (flag == 0)
        {
            printf("%s\n", str);
        }
    }
    if (flag1 == 0)
    {
        return 0;
    }
    return 1;
}