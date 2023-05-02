/*Can you find the needle in the haystack?

Write a function findNeedle() that takes an array full of junk but containing one "needle"

After your function finds the needle it should return a message (as a string) that says:

"found the needle at position " plus the index it found the needle, so:

Example(Input --> Output)

["hay", "junk", "hay", "hay", "moreJunk", "needle", "randomJunk"] --> "found the needle at position 5" */



#include <stddef.h>
#include <string.h>

char *find_needle(const char **haystack, size_t count)
{
    int i = 0;
    char *arr = strdup("needle");
    char *arr1 = malloc(sizeof(char) * 10000);
    while (haystack[i])
    {
        if (strcmp(arr, haystack[i]) == 0)
        {
            sprintf(arr1, "found the needle at position %d", i);
            return arr1;
        }
        i++;
    }
    return NULL;
}