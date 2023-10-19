#include <stdio.h>

float arithmetic_operation (float num1, float num2, char op)
{
    float result;

    switch (op)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        default:
            printf("Invalid operator\n");
            result = 0;
    }

    return result;
}

int main ()
{
    float num1 = 5;
    float num2 = 10;
    char op = '/';
    float result = arithmetic_operation(num1, num2, op);
    printf("The result of %.2f %c %.2f is %.2f\n", num1, op, num2, result);

    return 0;
}