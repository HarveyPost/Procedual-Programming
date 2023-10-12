#include <stdio.h>

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);
    int i;

    printf("Reversed array: ");
    for (i = length - 1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}