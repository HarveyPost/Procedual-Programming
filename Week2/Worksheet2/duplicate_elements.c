#include <stdio.h>

int main()
{
    int arr[6] = {1, 1, 3, 4, 4, 5};
    int n = 6;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > 0)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}