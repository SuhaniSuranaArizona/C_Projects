/*
 * File: anagrams.c
 * Author: Suhani Surana
 * Purpose: Defines a function to compute the anagrams from a series of strings
 *
 */

#include <stdio.h>
int getFrequency(char c[], char letter)
{
    int i;
    int frequency;
    for (i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == letter)
        {
            frequency++;
        }
    }
    return (frequency);
}

int main()
{

    char str[64];

    char first[64];
    if (scanf("%63s", first) == EOF)
    {
        return (0);
    }
    else
    {
        printf("%s", str);
    }

    while (scanf("%63s", str) != EOF)
    {

        int i;
        int flag = 0;
        for (i = 0; str[i] != '\0'; i++)
        {
            int freq1 = getFrequency(first, str[i]);
            int freq2 = getFrequency(str, str[i]);
            if (freq1 != freq2)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("%s", str);
        }
    }

    
    return (0);
    
}
