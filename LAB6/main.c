#include <stdio.h>

#define MAX_NUMBERS 100
#define MAX_ROWS 100

int read_numbers(int numbers[])
{
    int count = 0;
    int number;
    printf("Enter numbers, one per line. End with -100:\n");
    while (count < MAX_NUMBERS && scanf("%d", &number) == 1 && number != -100)
    {
        numbers[count] = number;
        count++;
    }
    return count;
}

void label_numbers(int numbers[], char labels[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (numbers[i] % 2 == 0)
        {
            labels[i] = 'e';
        }
        else
        {
            labels[i] = 'o';
        }
    }
}

void print_labeled_numbers(int numbers[], char labels[], int count)
{
    printf("Number\tLabel\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%c\n", numbers[i], labels[i]);
    }
}


int main()
{

     //part1
    int numbers[MAX_NUMBERS];
    char labels[MAX_NUMBERS];
    int count = read_numbers(numbers);
    label_numbers(numbers, labels, count);
    print_labeled_numbers(numbers, labels, count);

    // part2
       FILE *ptr = fopen("table.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int n, i;
    fscanf(ptr, "%d", &n);

    int age[MAX_ROWS];
    char occupation[MAX_ROWS];
    float salary[MAX_ROWS];
    char team[MAX_ROWS];

    for (i = 0; i < n; i++) {
        fscanf(ptr, "%d %c %f %c", &age[i], &occupation[i], &salary[i], &team[i]);
    }

    fclose(ptr);

    char selected_team;
    printf("Please select a team: ");
    scanf(" %c", &selected_team);

    float total_salary = 0;
    int counter = 0;

    for (i = 0; i < n; i++) {
        if (team[i] == selected_team) {
            total_salary += salary[i];
            counter++;
        }
    }

    if (counter > 0) {
        float avg_salary = total_salary / counter;
        printf("Average salaries of fans of %c: %.1f\n", selected_team, avg_salary);
    } else {
        printf("There are no fans of %c in the database!\n", selected_team);
    }

    return 0;
}

