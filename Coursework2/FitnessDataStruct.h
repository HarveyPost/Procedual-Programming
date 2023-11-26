#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

#include <stdio.h>

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

#endif // FITNESS_DATA_STRUCT_H