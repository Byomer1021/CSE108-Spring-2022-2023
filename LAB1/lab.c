#include <stdio.h>

int main()
{
    // FizzBuzz
    int num;
    printf("Enter an integer value between 1 and 100: ");
    scanf("%d", &num);

    if (0 <= num <= 100)
    {

        if (num % 3 == 0 && num >= 5 && num <= 50)
        {
            printf("FizzBuzz\n");
        }
        else if (num % 3 == 0)
        {
            printf("Fizz\n");
        }
        else if (num >= 5 && num <= 50)
        {
            printf("Buzz\n");
        }
    }

    else return 0;

    // Z Calculator
    double x, y, z, max;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the value of y: ");
    scanf("%lf", &y);

    if (x < y)
        max = y;
    else
        max = x;
    z = (x / y) + (max / (x + y));

    printf("z = %lf\n", z);

    // Salary Calculator
    int age, years;
    double salary;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter years of experience: ");
    scanf("%d", &years);

    if (age < 20)
    {
        if (years >= 0 && years <= 10)
        {
            salary = 10000;
        }
        else
        {
            printf("Error\n");
            return 1;
        }
    }
    else if (age >= 20 && age <= 50)
    {
        if (years >= 0 && years <= 10)
        {
            salary = 15000;
        }
        else
        {
            salary = 20000;
        }
    }
    else
    {
        if (years >= 0 && years <= 10)
        {
            salary = 20000;
        }
        else
        {
            salary = 25000;
        }
    }

    printf("Salary: %.2lf\n", salary);

    return 0;
}