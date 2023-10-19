#include <stdio.h>

int str_len (char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

int main ()
{
    char str[] = "Hello mate";
    int len = str_len(str);
    printf("The length of %s is %d\n", str, len);

    return 0;
}