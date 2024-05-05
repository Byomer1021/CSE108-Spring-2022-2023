#include <stdio.h>

float convert_celsius_to_fahrenheit(float celsius)
{
    return celsius * (9.0 / 5.0) + 32.0;
}

float convert_fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32.0) * (5.0 / 9.0);
}

void display_menu()
{
    printf("Temperature Conversion Menu\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Quit\n");
}

int part1()
{
    char choice;
    float temperature, result;
    while (1)
    {
        display_menu();
        printf("Enter your choice (1-3): ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            printf("Enter the temperature value to convert: ");
            scanf("%f", &temperature);
            result = convert_celsius_to_fahrenheit(temperature);
            printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, result);
            break;

        case '2':
            printf("Enter the temperature value to convert: ");
            scanf("%f", &temperature);
            result = convert_fahrenheit_to_celsius(temperature);
            printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, result);
            break;

        case '3':
            printf("Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}
int part2()
{
    int num, reversed_num = 0;
    int digit_count = 0;

    printf("Enter a number (3, 4, or 5): ");
    scanf("%d", &num);

    // counting the number of digits in the input number
    int temp = num;
    while (temp != 0)
    {
        digit_count++;
        temp /= 10;
    }

    if (digit_count < 3 || digit_count > 5)
    {
        printf("Invalid input. Please enter a number with 3, 4, or 5 digits.\n");
        return 0;
    }

    // reversing the input number
    while (num != 0)
    {
        reversed_num = reversed_num * 10 + num % 10;
        num /= 10;
    }

    printf("Reversed number: %d\n", reversed_num);
}

int main()
{
    part1();
    part2();
}
