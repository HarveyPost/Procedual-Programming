#include <stdio.h>

float sphereVolume (float radius)
{
    float volume;
    volume = 4.0/3.0 * 3.14159 * radius * radius * radius;
    return volume;
}

int main ()
{
    float radius = 5;
    float volume = sphereVolume(radius);
    printf("The volume of a sphere with radius %f is %f\n", radius, volume);

    return 0;
}