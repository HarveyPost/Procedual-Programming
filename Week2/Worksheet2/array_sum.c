#include <stdio.h>

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);
    int i;
    int sum = 0;

    for (i = 0; i < length; i++)
    {
        sum += array[i];
    }

    printf("Sum of array: %d\n", sum);

    return 0;
}