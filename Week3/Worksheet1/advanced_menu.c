#include <stdio.h>

int main()
{
    int choice;

    printf("1. Option 1\n");
    printf("2. Option 2\n");
    printf("3. Option 3\n");
    printf("4. Option 4\n");
    printf("5. Option 5\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You chose Option1\n");
            break;
        case 2:
            printf("You chose Option 2.\n");
            break;
        case 3:
            printf("You chose Option 3.\n");
            break;
        case 4:
            printf("You chose Option 4.\n");
            break;
        case 5:
            printf("You chose Option 5.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            break;
    }

    return 0;
}