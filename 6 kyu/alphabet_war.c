/*

Introduction
There is a war...between alphabets!
There are two groups of hostile letters. The tension between left side letters and right side letters was too high and the war began. The letters called airstrike to help them in war - dashes and dots are spread throughout the battlefield. Who will win?

Task
Write a function that accepts a fight string which consists of only small letters and * which represents a bomb drop place. Return who wins the fight after bombs are exploded. When the left side wins return Left side wins!, and when the right side wins return Right side wins!. In other cases, return Let's fight again!.

The left side letters and their power:

 w - 4
 p - 3 
 b - 2
 s - 1
The right side letters and their power:

 m - 4
 q - 3 
 d - 2
 z - 1
The other letters don't have power and are only victims.
The * bombs kill the adjacent letters ( i.e. aa*aa => a___a, **aa** => ______ );

Example
alphabet_war("s*zz");          => Right side wins!
alphabet_war("*zd*qm*wp*bs*"); => Let's fight again!
alphabet_war("zzzz*s*");       => Right side wins! 
alphabet_war("www*www****z");  => Left side wins! 

*/



#include <stdlib.h>
#include <stdio.h>

char *alphabet_war(const char *fight)
{
    int lpoint = 0;
    int rpoint = 0;
    int i = 0;
    int j = 0;
    char *arr = strdup(fight);
    printf("fight = %s\n", fight);
    while (fight[i])
    {
        if (fight[i] == '*' && i != 0)
        {
            arr[i] = 'A';
            arr[i + 1] = 'A';
            arr[i - 1] = 'A';
        }
        if (i == 0 && fight[i] == '*')
        {
            arr[i] = 'A';
            arr[i + 1] = 'A';
        }
        i++;
    }
    printf("arr = %s\n", arr);
    i = 0;
    while (arr[i])
    {
        if (arr[i] == 'w' || arr[i] == 's' || arr[i] == 'b' || arr[i] == 'p')
        {
            if (arr[i] == 'w')
                lpoint += 4;
            else if (arr[i] == 'p')
                lpoint += 3;
            else if (arr[i] == 'b')
                lpoint += 2;
            else
                lpoint += 1;
        }
        if (arr[i] == 'm' || arr[i] == 'q' || arr[i] == 'd' || arr[i] == 'z')
        {
            if (arr[i] == 'm')
                rpoint += 4;
            else if (arr[i] == 'q')
                rpoint += 3;
            else if (arr[i] == 'd')
                rpoint += 2;
            else
                rpoint += 1;
        }
        i++;
    }
    printf("r = %d, l = %d\n", rpoint, lpoint);
    if (lpoint > rpoint)
        return ("Left side wins!");
    else if (rpoint > lpoint)
        return ("Right side wins!");
    else if (lpoint == rpoint)
        return ("Let's fight again!");
    return ("Let's fight again!");
}