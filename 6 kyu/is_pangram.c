/*
A pangram is a sentence that contains every single letter of the alphabet at least once. For example, the sentence "The quick brown fox jumps over the lazy dog" is a pangram, because it uses the letters A-Z at least once (case is irrelevant).

Given a string, detect whether or not it is a pangram. Return True if it is, False if not. Ignore numbers and punctuation.
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
bool is_pangram(const char *str_in)
{
  int i = 0;
  int count[100] = {0};
  for(i=0;str_in[i]!='\0';i++)
    {
        if(str_in[i]==32)
            continue;                   //skip if white space
 
        if(str_in[i]>96)                   //If small letter
            count[str_in[i]-97] +=1;       //increment the count
       else                             //If capital letter
            count[str_in[i]-65] +=1;
    }
    for(i=0;i<26;i++)
    {
        /*If any element in count array is zero, then it is not Pangram*/
        if(count[i]==0)
          return false;
    }
        return true;
}