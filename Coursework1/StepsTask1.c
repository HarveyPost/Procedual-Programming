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
    FITNESS_DATA p1;

    // Open CSV file
    FILE *file = fopen("FitnessData_2023.csv", "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    tokeniseRecord(file, ",", p1.date, p1.time, p1.steps);

    fclose(file);

    printf("Date: %s\n", p1.date);
    printf("Time: %s\n", p1.time);
    printf("Steps: %s\n", p1.steps);

    return 0;
}