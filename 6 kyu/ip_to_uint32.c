/*
Take the following IPv4 address: 128.32.10.1. This address has 4 octets where each octet is a single byte (or 8 bits).

1st octet 128 has the binary representation: 10000000
2nd octet 32 has the binary representation: 00100000
3rd octet 10 has the binary representation: 00001010
4th octet 1 has the binary representation: 00000001
So 128.32.10.1 == 10000000.00100000.00001010.00000001

Because the above IP address has 32 bits, we can represent it as the 32 bit number: 2149583361.

Write a function ip_to_int32(ip) ( JS: ipToInt32(ip) ) that takes an IPv4 address and returns a 32 bit number.

Example
"128.32.10.1" => 2149583361

*/


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static int howmany(const char *s, char c)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            i++;
        else
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (count);
}

static char *print_it(char *p, const char *s, int i, int k)
{
    int x;

    x = 0;
    while (k > 0)
    {
        p[x] = s[i - k];
        x++;
        k--;
    }
    p[x] = '\0';
    return (p);
}

static char *word_split(char **p, const char *s, char c, int howmny)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (j < howmny)
    {
        while (s[i] != '\0' && s[i] == c)
            i++;
        while (s[i] != '\0' && s[i] != c)
        {
            i++;
            k++;
        }
        p[j] = (char *)malloc(sizeof(char) * (k + 1));
        if (!p)
            return (0);
        print_it(p[j], s, i, k);
        j++;
        k = 0;
    }
    p[j] = 0;
    return (p[j]);
}

char **ft_split(char const *s, char c)
{
    char **p;
    int howmny;

    if (s)
    {
        howmny = howmany(s, c);
        p = (char **)malloc(sizeof(char *) * (howmny + 1));
        if (!p)
            return (0);
        word_split(p, s, c, howmny);
        return (p);
    }
    return (0);
}

uint32_t ip_to_uint32(const char *ip)
{
    char **arr = ft_split(ip, '.');
    char *arr1 = malloc(sizeof(char) * 1000);
    uint32_t res = 0;
    int i = 0;
    int num = 0;
    int count = 0;
    int j = 7;
    for (i = 0; arr[i] != NULL; i++)
    {
        num = atoi(arr[i]);
        printf("%d\n", num);
        while (j >= 0)
        {
            if ((num >> j) & 1)
                arr1[count++] = '1';
            else
                arr1[count++] = '0';
            j--;
        }
        j = 7;
    }
    arr1[count] = '\0';
    i = 0;
    while (arr1[i])
    {
        res <<= 1;
        if (arr1[i] == '1')
            res |= 1;
        i++;
    }
    printf("%d", res);
    return res;
}