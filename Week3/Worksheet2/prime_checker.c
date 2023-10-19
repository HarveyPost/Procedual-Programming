#include <stdio.h>

int isPrime (int num)
{
    int i;
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main ()
{
    int num = 7;
    int prime = isPrime(num);
    if (prime == 1)
    {
        printf("%d is prime\n", num);
    }
    else
    {
        printf("%d is not prime\n", num);
    }

    return 0;
}