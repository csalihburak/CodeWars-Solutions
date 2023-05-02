/*
Write a function, persistence, that takes in a positive parameter num and returns its multiplicative persistence, which is the number of times you must multiply the digits in num until you reach a single digit.

For example (Input --> Output):

39 --> 3 (because 3*9 = 27, 2*7 = 14, 1*4 = 4 and 4 has only one digit)
999 --> 4 (because 9*9*9 = 729, 7*2*9 = 126, 1*2*6 = 12, and finally 1*2 = 2)
4 --> 0 (because 4 is already a one-digit number)
*/

int multiply(int *arr, int l)
{
    int i = 0;
    int res = 1;
    while (i < l)
    {
        res *= arr[i];
        i++;
    }
    return res;
}

int persistence(int n)
{
    int i = 0;
    int count = 1;
    int *res = malloc(sizeof(int) * 1000);
    int res1 = 1;
    if (n >= 0 && n <= 9)
        return 0;
    while (n != 0)
    {
        res[i++] = n % 10;
        n /= 10;
    }
    res1 = multiply(res, i);
    if (res1 > 9)
    {
        count += persistence(res1);
    }
    return count;
}