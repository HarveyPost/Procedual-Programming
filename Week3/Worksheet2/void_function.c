#include <stdio.h>

void reverseArray (int arr[], int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}

int main ()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    reverseArray(arr, len);
    
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}