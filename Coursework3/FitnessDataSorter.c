#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

// Function to compare the number of steps
int compareSteps(const void *a, const void *b) {
    FitnessData dataA = *(FitnessData *)a;
    FitnessData dataB = *(FitnessData *)b;
    return dataB.steps - dataA.steps;
}

int main() {
    
    // Declare an array named records of type FITNESS_DATA
    FitnessData records[1000];

    char filename[256];
    printf("Enter filename: ");
    fgets(filename, 256, stdin);
    // Remove the newline character from the filename
    filename[strcspn(filename, "\n")] = '\0';

    // Open CSV file
    FILE *file = fopen(filename, "r");

    // Check if file exists and is not empty
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Counter for number of rows
    int num_rows = 0;
    char row[1000];

    // Read each line of the file
    while (fgets(row, 1000, file) != NULL)
    {
        // Store each token in a temp char array
        char date[11];
        char time[6];
        int steps;
        
        // Reference: https://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm
        // Check for format of the line
        if ((sscanf(row, "%10s %5s %d", date, time, &steps) != 3))
        {
            printf("Error: invalid file\n");
            return 1;
        }

        // If the format is correct, tokenize the record
        tokeniseRecord(row, ',', date, time, &steps);

        strcpy(records[num_rows].date, date);
        strcpy(records[num_rows].time, time);
        records[num_rows].steps = steps;

        num_rows++;
    }

    fclose(file);

    // Reference: https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
    // Sort the records by number of steps in descending order
    qsort(records, num_rows, sizeof(FitnessData), compareSteps);

    // Create the new tsv file
    char newfilename[1000];
    sprintf(newfilename, "%s.tsv", filename);

    FILE *newfile = fopen(newfilename, "w");

    // Check if file can be opened
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Write the sorted records to the new tsv file
    for (int i = 0; i < num_rows; i++)
    {
        fprintf(newfile, "%s\t%s\t%d\n", records[i].date, records[i].time, records[i].steps);
    }

    fclose(newfile);
}
