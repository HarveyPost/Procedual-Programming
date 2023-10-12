#include <stdio.h>

int main()
{
    int arr[6] = {1, 2, 3, 2, 4, 1};
    int n = 6;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > 1)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}