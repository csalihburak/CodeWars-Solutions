/*The drawing shows 6 squares the sides of which have a length of 1, 1, 2, 3, 5, 8. It's easy to see that the sum of the perimeters of these squares is : 4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80 

Could you give the sum of the perimeters of all the squares in a rectangle when there are n + 1 squares disposed in the same manner as in the drawing:

image: http://i.imgur.com/EYcuB1wm.jpg

alternative text

Hint:
See Fibonacci sequence

Ref:
http://oeis.org/A000045

The function perimeter has for parameter n where n + 1 is the number of squares (they are numbered from 0 to n) and returns the total perimeter of all the squares.

perimeter(5)  should return 80
perimeter(7)  should return 216

*/

typedef unsigned long long ull;
ull perimeter(int n)
{
    ull n1;
    ull i = 0;
    ull res = 0;
    n1 = 1;
    ull n2 = 1;
    ull n3 = 0;
    for (i = 2; i < n + 1; ++i)
    {
        printf("%d", res);
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        res += n3;
    }
    res += 2;
    return res * 4;
}