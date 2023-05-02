/*
Write a function that accepts an array of 10 integers (between 0 and 9), that returns a string of those numbers in the form of a phone number.

Example
create_phone_number(phnum, (const unsigned char[]){1,2,3,4,5,6,7,8,9,0});

phnum <- "(123) 456-7890"
The returned format must be correct in order to complete this challenge.

Don't forget the space after the closing parentheses!
*/

#include <string.h>

char *create_phone_number(char phnum[15], const unsigned char nums[10])
{
    sprintf(phnum, "(%d%d%d) %d%d%d-%d%d%d%d", nums[0], nums[1], nums[2], nums[3], nums[4],
            nums[5], nums[6], nums[7], nums[8], nums[9]);
    return phnum;
}