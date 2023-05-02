/*

Welcome.

In this kata you are required to, given a string, replace every letter with its position in the alphabet.

If anything in the text isn't a letter, ignore it and don't return it.

"a" = 1, "b" = 2, etc.

Example
alphabet_position("The sunset sets at twelve o' clock.")
Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" ( as a string )

*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

static char *ft_array(char *x, unsigned int number, long int len)
{
    while (number > 0)
    {
        x[len--] = 48 + (number % 10);
        number = number / 10;
    }
    return (x);
}

static long int ft_len(int n)
{
    int len;

    len = 0;
    if (n <= 0)
        len = 1;
    while (n != 0)
    {
        len++;
        n = n / 10;
    }
    return (len);
}

char *ft_itoa(int n)
{
    char *x;
    long int len;
    unsigned int number;
    int sign;

    sign = 1;
    len = ft_len(n);
    x = (char *)malloc(sizeof(char) * (len + 1));
    if (!(x))
        return (NULL);
    x[len--] = '\0';
    if (n == 0)
        x[0] = '0';
    if (n < 0)
    {
        sign *= -1;
        number = n * -1;
        x[0] = '-';
    }
    else
        number = n;
    x = ft_array(x, number, len);
    return (x);
}
// returned string has to be dynamically allocated and will be freed by the caller
char *alphabet_position(const char *text)
{
    int i;
    int len;
    char *text1;
    len = strlen(text);
    text = (char *)text;
    i = 0;
    int j = 0;
    int act;
    int left;
    left = 0;
    int right;
    right = 0;
    char a;
    text1 = (char *)malloc(sizeof(char) * len + 1);
    while (i < len)
    {
        a = tolower(text[i]);
        act = a - 96;
        if (act >= 1 && act <= 9)
            text1[j++] = (act + 48);
        else if (act >= 10 && act <= 26)
        {
            left = act / 10;
            right = act % 10;
            text1[j++] = (char)left + 48;
            text1[j++] = (char)right + 48;
        }
        if (act >= 1 && act <= 26)
            text1[j++] = ' ';
        i++;
    }
    text1[j - 1] = '\0';
    return text1;
}