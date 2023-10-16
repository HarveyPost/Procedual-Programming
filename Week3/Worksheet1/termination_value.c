#include <stdio.h>

int main()
{
    int num;
    
    while (num != -1)
    {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == -1)
        {
            printf("Terminating program...\n");
            break;
        }
        else if (num >= 0 && num <= 100)
        {
            printf("Valid number entered: %d\n", num);
        }
        else
        {
            printf("Invalid number entered: %d\n", num);
        }
    }

    return 0;
}