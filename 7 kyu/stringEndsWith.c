/*

Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).

Examples:

solution('abc', 'bc') // returns true
solution('abc', 'd') // returns false

*/

#include <stdbool.h>
#include <string.h>

bool solution(const char *string, const char *ending)
{
    const size_t lenString = strlen(string), lenEnding = strlen(ending);
    return lenEnding <= lenString && strcmp(string + (lenString - lenEnding), ending) == 0;
}