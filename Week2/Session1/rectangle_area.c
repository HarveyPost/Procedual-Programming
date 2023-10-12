#include <stdio.h>

int main()
{
    // Prompt user for dimensions
    float length, width, area;

    printf("Please enter the length of the rectangle: ");
    scanf("%f", &length);
    printf("Please enter the width of the rectangle: ");
    scanf("%f", &width);
    
    // Calculate area and output result
    area = length * width;
    printf("The area of the rectangle is %f\n", area);
    
    return 0;
}