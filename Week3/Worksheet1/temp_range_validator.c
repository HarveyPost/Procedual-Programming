#include <stdio.h>

int main()
{
    int temp = 0;
    printf("Enter a temperature: ");
    scanf("%d", &temp);

    if (temp >= -10 && temp <= 40)
    {
        printf("Temperature is in range\n");
    }
    else
    {
        printf("Temperature is not in range\n");
    }

    return 0;
}