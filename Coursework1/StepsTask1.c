#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main()
{
    // Declare an array named records of type FITNESS_DATA
    FITNESS_DATA records[1000];

    // Open CSV file
    FILE *file = fopen("FitnessData_2023.csv", "r");

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
        char steps[1000];

        tokeniseRecord(row, ",", date, time, steps);

        // Store each token in the appropriate struct field
        strcpy(records[num_rows].date, date);
        strcpy(records[num_rows].time, time);
        records[num_rows].steps = atoi(steps);

        // Increment number of rows
        num_rows++;
    }

    fclose(file);

    printf("Number of records in file: %d\n", num_rows);

    // Print the first 3 records with times 7:30, 7:45 and 8:00
    for (int i = 0; i < 3; i++) {
        printf("%s/%s/%d\n", records[i].date, records[i].time, records[i].steps);
    }

    return 0;
}