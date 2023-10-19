#include <stdio.h>

int sum (int a, int b)
{
    int answer;
    answer = a + b;
    return a + b;
}

int main ()
{
    int x = 5;
    int y = 10;
    int z = sum(x, y);
    printf("The sum of %d and %d is %d\n", x, y, z);

    return 0;
}