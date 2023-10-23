#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE *file = fopen("squares.dat", "r");

    if (file == NULL)
    {
        printf("Error opening file squares.dat\n");
        return 1;
    }

    printf("The contents of squares.dat are:\n");

    char row[1000];
    double sum;

    while (fgets(row, 1000, file) != NULL)
    {
        sum = atof(row);
        printf("%f\n", sum);
    }

    fclose(file);
}