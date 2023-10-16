#include <stdio.h>

int main()
{
    int grade = 0;
    printf("Enter a grade: ");
    scanf("%d", &grade);

    if (grade >= 70)
    {
        printf("Distinction\n");
    }
    else if (grade >= 50)
    {
        printf("Pass\n");
    }
    else
    {
        printf("Fail\n");
    }

    return 0;
}