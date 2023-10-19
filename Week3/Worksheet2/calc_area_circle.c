#include <stdio.h>

float circleArea (float radius)
{
    float area;
    area = 3.14159 * radius * radius;
    return area;
}

int main ()
{
    float radius = 5;
    float area = circleArea(radius);
    printf("The area of a circle with radius %f is %f\n", radius, area);

    return 0;
}