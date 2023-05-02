/*
Your company MRE Tech has developers with very different backgrounds. One day a new project is getting started and now, to your surprise, you are the senior C programmer in the team. The other programmers come from PHP, Python, Perl, OCaml, and Bash. To help with the transition to C the project manager decides to reject the standard library and to implement an in house solution. The project manager did some Python programming in high school and decides that this new library should have a Python-like touch.

The first task for this library is formatted printing:

Task
Write a function mr_asprintf

char *mr_asprintf(const char *format, ...);
that takes a format string and any number of additional arguments and returns a malloced string where all conversion specifications (e.g. {i}) are replaced by the aforementioned additional arguments.

Format of the format string
The format string is composed of zero or more directives: ordinary characters (not {), which are copied unchanged, and conversion specifications in the form { <type> }. You only have to implement type i for int and type s for char *. To allow literal curly braces ({), {{ is replaced with {.

Examples
char *result = mr_asprintf("Gaius Julius Caesar Augustus Germanicus");
// result == "Gaius Julius Caesar Augustus Germanicus"

char *result = mr_asprintf("Nickname: {s}", "Caligula");
// result == "Nickname: Caligula"

char *result = mr_asprintf("Reign: {i} AD - {i} AD", 37, 41);
// result == "Reign: 37 AD - 41 AD"

char *result = mr_asprintf("born: {s} {i}, {i} in {s}", "August", 31, 12, "Antium");
// result == "born: August 31, 12 in Antium"
*/


#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    return x;
}

char *mr_asprintf(const char *format, ...)
{
    int i = 0;
    va_list ap;
    va_start(ap, format);
    char *arr = malloc(sizeof(char) * 1000);
    char *tut = malloc(sizeof(char) * 1000);
    int j = 0;
    int k = 0;
    printf("%s\n", format);
    while (format[i])
    {
        if (format[i] == '{' && format[i + 2] == '}' && format[i + 2])
        {
            if (format[i + 1] == 's')
            {
                tut = va_arg(ap, char *);
                j = 0;
                while (tut[j])
                    arr[k++] = tut[j++];
                i += 3;
            }
            else if (format[i + 1] == 'i')
            {
                int a = va_arg(ap, int);
                tut = ft_itoa(a);
                j = 0;
                while (tut[j])
                    arr[k++] = tut[j++];
                i += 3;
            }
        }
        else if (format[i] == '{' && format[i + 1] == '{')
        {
            arr[k++] = '{';
            i += 2;
        }
        if (!format[i])
        {
            arr[k] = '\0';
            return arr;
        }
        else if (format[i] != '{')
            arr[k++] = format[i++];
    }
    arr[k] = '\0';
    return arr;
}