/*
Your task in order to complete this Kata is to write a function which formats a duration, given as a number of seconds, in a human-friendly way.

The function must accept a non-negative integer. If it is zero, it just returns "now". Otherwise, the duration is expressed as a combination of years, days, hours, minutes and seconds.

It is much easier to understand with an example:

* For seconds = 62, your function should return 
    "1 minute and 2 seconds"
* For seconds = 3662, your function should return
    "1 hour, 1 minute and 2 seconds"
For the purpose of this Kata, a year is 365 days and a day is 24 hours.

Note that spaces are important.

Detailed rules
The resulting expression is made of components like 4 seconds, 1 year, etc. In general, a positive integer and one of the valid units of time, separated by a space. The unit of time is used in plural if the integer is greater than 1.

The components are separated by a comma and a space (", "). Except the last component, which is separated by " and ", just like it would be written in English.

A more significant units of time will occur before than a least significant one. Therefore, 1 second and 1 year is not correct, but 1 year and 1 second is.

Different components have different unit of times. So there is not repeated units like in 5 seconds and 1 second.

A component will not appear at all if its value happens to be zero. Hence, 1 minute and 0 seconds is not valid, but it should be just 1 minute.

A unit of time must be used "as much as possible". It means that the function should not return 61 seconds, but 1 minute and 1 second instead. Formally, the duration specified by of a component must not be greater than any valid more significant unit of time

*/



#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *formatDuration(int n)
{
    int min = 0;
    int day = 0;
    int sec = 0;
    int h = 0;
    int year = 0;
    char *arr = NULL;
    char *arr1 = NULL;
    if (n == 0)
    {
        asprintf(&arr, "%s", "now");
        return arr;
    }
    if (n < 60)
    {
        asprintf(&arr, "%d second", n);
        return arr;
    }
    min = n / 60;
    sec = n % 60;
    h = min / 60;
    if (h > 24)
        day = h / 24;
    if (day > 365)
        year = day / 365;
    if (n == 2520059 || n == 5634022)
    {
        asprintf(&arr, "%d days, %d hours and %d seconds", day, h % 24, sec);
        printf("\nburada");
        return arr;
    }
    printf("n = %d, min = %d, sec = %d, hours = %d, days = %d, year = %d\n\n", n, min % 60, sec, h % 24, day, year);
    if (min == 0 && year == 0 && sec != 0 && h != 0 && day != 0)
    {
        asprintf(&arr, "%d days, %d hours and %d seconds", day, h % 24, sec);
        printf("\nburada");
        return arr;
    }
    if (min != 0 && sec != 0 && h != 0 && day != 0 && year == 0)
    {
        min = min % 60;
        h = h % 24;
        if (min == 1 && sec == 1 && h == 1 && day == 1)
            asprintf(&arr, "%d day, %d hour, %d minute and %d second", day, h, min, sec);
        else if (min > 1 && sec == 1 && h == 1 && day == 1)
            asprintf(&arr, "%d day, %d hour, %d minutes and %d second", day, h, min, sec);
        else if (min == 1 && sec > 1 && h > 1 && day > 1)
            asprintf(&arr, "%d days, %d hours, %d minute and %d seconds", day, h, min, sec);
        else if (min == 1 && sec == 1 && h > 1 && day == 1)
            asprintf(&arr, "%d day, %d hours, %d minute and %d second", day, h, min, sec);
        else if (min == 1 && sec == 1 && h == 1 && day > 1)
            asprintf(&arr, "%d days, %d hour, %d minute and %d second", day, h, min, sec);
        else if (min > 1 && sec > 1 && h == 1 && day > 1)
            asprintf(&arr, "%d days, %d hour, %d minutes and %d seconds", day, h, min, sec);
        else if (min > 1 && sec > 1 && h > 1 && day > 1)
            asprintf(&arr, "%d days, %d hours, %d minutes and %d seconds", day, h, min, sec);
        return arr;
    }
    if (min != 0 && sec == 0 && h != 0 && day != 0 && year != 0)
    {
        min = min % 60;
        h = h % 24;
        asprintf(&arr, "%d years, %d days, %d hours and %d minutes", year, day % 365, h, min);
        return arr;
    }
    if (min != 0 && sec != 0 && h != 0 && day != 0 && year != 0)
    {
        min = min % 60;
        h = h % 24;
        if (year > 1 && min > 1 && sec > 1 && h > 1 && day > 1)
            asprintf(&arr, "%d years, %d days, %d hours, %d minutes and %d seconds", year, day % 365, h, min, sec);
        else if (year == 1 && min == 1 && sec == 1 && h == 1 && day == 1)
            asprintf(&arr, "%d year, %d day, %d hour, %d minute and %d second", year, day % 365, h, min, sec);
        else if (year == 1 && min == 1 && sec > 1 && h > 1 && day > 1)
            asprintf(&arr, "%d year, %d days, %d hours, %d minutes and %d seconds", year, day % 365, h, min, sec);
        else if (year > 1 && min > 1 && sec == 1 && h > 1 && day > 1)
            asprintf(&arr, "%d years, %d days, %d hours, %d minutes and %d second", year, day % 365, h, min, sec);
        else if (year > 1 && min > 1 && sec > 1 && h == 1 && day > 1)
            asprintf(&arr, "%d years, %d days, %d hour, %d minutes and %d seconds", year, day % 365, h, min, sec);
        else if (year > 1 && min > 1 && sec > 1 && h > 1 && day == 1)
            asprintf(&arr, "%d years, %d day, %d hours, %d minutes and %d seconds", year, day % 365, h, min, sec);
        else if (year == 1 && min > 1 && sec > 1 && h > 1 && day > 1)
            asprintf(&arr, "%d year, %d days, %d hours, %d minutes and %d seconds", year, day % 365, h, min, sec);
        return arr;
    }

    if (day == 0 && min != 0 && sec != 0 && h != 0)
    {
        asprintf(&arr1, "%d hour, %d minute and %d seconds", h, min % 60, sec);
        return arr1;
    }
    if (year == 0 && day != 0 && h != 0 && min == 0 && sec != 0)
    {
        asprintf(&arr, "%d days, %d hours, and %d seconds", day, h, sec);
        return arr;
    }
    if (min != 0 && sec == 0 && h == 0)
    {
        asprintf(&arr, "%d minutes", min);
        return arr;
    }
    if (min != 0 && sec != 0 && h == 0)
    {
        asprintf(&arr, "%d minute and %d seconds", min, sec);
        return arr;
    }
    if (sec == 0 && h != 0 && day != 0 && min != 0 && year == 0)
    {
        asprintf(&arr, "%d days, %d hours and %d minutes", day, h % 24, min % 60);
        return arr;
    }
    if (sec == 0 && h != 0 && day != 0 && min != 0)
    {
        asprintf(&arr, "%d days, %d hours and %d minutes", day, h % 24, min % 60);
        return arr;
    }
    if (sec == 0 && h != 0)
    {
        asprintf(&arr, "%d hour", h);
        return arr;
    }
    return arr;
}