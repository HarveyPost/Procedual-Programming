#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

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

char get_filename(char *filename)
{
    printf("Input filename: ");
    fgets(filename, 256, stdin);
    // Remove the newline character from the filename
    filename[strcspn(filename, "\n")] = '\0';
}

int get_total_rows(FILE *file)
{
    // Declare an array named records of type FITNESS_DATA
    FITNESS_DATA records[1000];

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

        // Tokenise each line
        tokeniseRecord(row, ",", date, time, steps);

        // Store each token in the appropriate struct field
        strcpy(records[num_rows].date, date);
        strcpy(records[num_rows].time, time);
        records[num_rows].steps = atoi(steps);

        // Increment number of rows
        num_rows++;
    }

    return num_rows;
}

void get_fewest_steps(FILE *file)
{
    int smallest = 1000000;
    char smallest_date[11];
    char smallest_time[6];
    char smallest_steps[1000];
    char row[1000];

    while (fgets(row, 1000, file) != NULL)
    {
        // Store each token in a temp char array
        char date[11];
        char time[6];
        char steps[1000];

        // Tokenise each line
        tokeniseRecord(row, ",", date, time, steps);

        // Check if current record has the smallest number of steps
        if (atoi(steps) < smallest)
        {
            smallest = atoi(steps);
            strcpy(smallest_date, date);
            strcpy(smallest_time, time);
        }
    }

    printf("Fewest steps: %s %s\n", smallest_date, smallest_time);
}

void get_largest_steps(FILE *file)
{
    int largest = 0;
    char largest_date[11];
    char largest_time[6];
    char largest_steps[1000];
    char row[1000];

    while (fgets(row, 1000, file) != NULL)
    {
        // Store each token in a temp char array
        char date[11];
        char time[6];
        char steps[1000];

        // Tokenise each line
        tokeniseRecord(row, ",", date, time, steps);

        // Check if current record has the smallest number of steps
        if (atoi(steps) > largest)
        {
            largest = atoi(steps);
            strcpy(largest_date, date);
            strcpy(largest_time, time);
        }
    }

    printf("Largest steps: %s %s\n", largest_date, largest_time);
}

void get_mean_steps(FILE *file)
{
    int total_steps = 0;
    int num_rows = 0;
    char row[1000];

    while (fgets(row, 1000, file) != NULL)
    {
        // Store each token in a temp char array
        char date[11];
        char time[6];
        char steps[1000];

        // Tokenise each line
        tokeniseRecord(row, ",", date, time, steps);

        // Add the number of steps to the total
        total_steps += atoi(steps);
        num_rows++;
    }

    printf("Mean step count: %d\n", total_steps / num_rows);
}

void get_longest_period(FILE *file)
{
    int max_period_start = -1;
    int max_period_end = -1;
    char max_period_start_date[11];
    char max_period_start_time[6];
    char max_period_end_date[11];
    char max_period_end_time[6];

    int current_period_start = -1;
    int current_period_end = -1;
    char current_period_start_date[11];
    char current_period_start_time[6];
    char current_period_end_date[11];
    char current_period_end_time[6];

    char row[1000];
    int row_num = 0;
    
    while (fgets(row, 1000, file) != NULL)
    {
        // Store each token in a temp char array
        char date[11];
        char time[6];
        char steps[1000];

        // Tokenise each line
        tokeniseRecord(row, ",", date, time, steps);

        int int_steps = atoi(steps);

        // Check if current record has minimum 500 steps
        if (int_steps > 500)
        {
            // Check if current period has not started
            if (current_period_start == -1)
            {
                // Set current period start and store date and time
                current_period_start = row_num;
                strcpy(current_period_start_date, date);
                strcpy(current_period_start_time, time);
            }
            // Set current period end and store date and time
            current_period_end = row_num;
            strcpy(current_period_end_date, date);
            strcpy(current_period_end_time, time);
        }
        else
        {
            // Check if current period is longer than the longest period
            if (current_period_end - current_period_start > max_period_end - max_period_start)
            {
                // Set longest period start and end and store date and time
                max_period_start = current_period_start;
                max_period_end = current_period_end;
                strcpy(max_period_start_date, current_period_start_date);
                strcpy(max_period_start_time, current_period_start_time);
                strcpy(max_period_end_date, current_period_end_date);
                strcpy(max_period_end_time, current_period_end_time);
            }
            // Reset current period
            current_period_start = -1;
            current_period_end = -1;
        }
        row_num++;
    }
    
    printf("Longest period start: %s %s\n", max_period_start_date, max_period_start_time);
    printf("Longest period end: %s %s\n", max_period_end_date, max_period_end_time);
}

int main() {
    char filename[256];
    char input[256];
    FITNESS_DATA records[1000];
    int num_rows = 0;

    while (1) {
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");

        fgets(input, 256, stdin);
        input[strcspn(input, "\n")] = '\0';

        // Specify the filename to be imported
        if (strcmp(input, "A") == 0)
        {
            get_filename(filename);

            FILE *file = fopen(filename, "r");
    
            // Check if the file exists
            if (file == NULL)
            {
                printf("Error opening file\n");
                continue;;
            }
            fclose(file);
        }

        // Find the total number of records in the file
        else if (strcmp(input, "B") == 0)
        {
            FILE *file = fopen(filename, "r");
            num_rows = get_total_rows(file);
            fclose(file);

            printf("Total records: %d\n", num_rows);
        }

        // Find the date and time of the timeslot with the fewest steps
        else if (strcmp(input, "C") == 0)
        {
            FILE *file = fopen(filename, "r");

            get_fewest_steps(file);
        }
        
        // Find the data and time of the timeslot with the largest number of steps
        else if (strcmp(input, "D") == 0)
        {
            FILE *file = fopen(filename, "r");

            get_largest_steps(file);

            fclose(file);
        }
        
        // Find the mean step count of all the records in the file
        else if (strcmp(input, "E") == 0)
        {
            FILE *file = fopen(filename, "r");

            get_mean_steps(file);

            fclose(file);
        }
        
        // Find the longest continuous period where the step count is above 500 steps
        else if (strcmp(input, "F") == 0)
        {
            FILE *file = fopen(filename, "r");

            get_longest_period(file);

            fclose(file);
        }

        // Quit the program
        else if (strcmp(input, "Q") == 0)
        {
            break;
        }
        
        // Invalid option entered
        else
        {
            printf("Invalid option\n");
        }
    }

    return 0;
}