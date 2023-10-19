#include <stdio.h>

char concatStrings (char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    while (str1[i] != '\0')
    {
        i++;
    }
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    return *str1;
}

int main ()
{
    char str1[] = "Hello";
    char str2[] = " mate";
    concatStrings(str1, str2);
    printf("The concatenated string is %s\n", str1);

    return 0;
}