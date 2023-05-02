/*
Is similar to factorial of a number, In primorial, not all the natural numbers get multiplied, 
only prime numbers are multiplied to calculate the primorial of a number. 
It's denoted with P# and it is the product of the first n prime numbers.
*/

#define ull unsigned long long

int isprime(int n)
{
    int i = 2;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    while (i < n / 2)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int *create(int n)
{
    int i = 0;
    int *arr = malloc(sizeof(int) * (n + 1));
    int iter = 2;
    int j = 0;
    while (1)
    {
        if (isprime(iter) && i < n)
        {
            arr[j++] = iter;
            i++;
            if (i >= n)
                break;
        }
        iter++;
    }
    return arr;
}

ull num_primorial(unsigned n)
{
    int i = 0;
    ull res = 1;
    int *arr = create(n);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    i = 0;
    while (i < n)
    {
        res *= arr[i];
        i++;
    }
    return res; 
}