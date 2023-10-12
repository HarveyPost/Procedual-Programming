#include <stdio.h>

int main()
{
    int array[] = {1, 23, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);
    int i, max = 0;

    for (i = length - 1; i >= 0; i--)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    printf("Maximum element: %d\n", max);

    return 0;
}