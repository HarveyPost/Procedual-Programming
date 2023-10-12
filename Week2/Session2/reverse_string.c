#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "Hello";
    int length = strlen(string);
    int i;

    printf("Reversed string: ");
    for (i = length - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }
    printf("\n");

    return 0;
}