#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE *file = fopen("numbers.dat", "a+");

    if (file == NULL)
    {
        printf("Error opening file numbers.dat\n");
        return 1;
    }

    float sum = 0;
    int num_rows = 0;
    char row[1000];

    while (fgets(row, 1000, file) != NULL)
    {
        sum += atof(row);
        num_rows++;
    }

    float average = sum / num_rows;

    fprintf(file, "%f\n", average);

    fclose(file);
}