#include <stdio.h>

int main()
{
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {4, 5, 6};
    int n = 3;
    int arr3[6];

    for (int i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
        arr3[i + n] = arr2[i];
    }

    printf("Concatenated array: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}