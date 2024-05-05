#include <stdio.h>

void median_manager(int number1, int number2, int number3)
{

    printf("Enter 3 integers: ");
    scanf("%d %d %d", &number1, &number2, &number3);

    if (number1 <= number2)
    {
        if (number2 <= number3)
        {
            printf("Median number is %d\n", number2);
        }
        else if (number1 >= number3)
        {
            printf("Median number is %d\n", number1);
        }
        else
        {
            printf("Median number is %d\n", number3);
        }
    }
    else
    {
        if (number1 <= number3)
        {
            printf("Median number is %d\n", number1);
        }
        else if (number2 >= number3)
        {
            printf("Median number is %d\n", number2);
        }
        else
        {
            printf("Median number is %d\n", number3);
        }
    }
}

void exam_calc()
{
    float score1, score2, score3, avg;
    char grade1, grade2, grade3;

    printf("Enter your scores: ");
    scanf("%f %f %f", &score1, &score2, &score3);

    // Calculate average
    avg = (score1 + score2 + score3) / 3;

    // Assign grades based on score
    switch ((int)score1 / 10)
    {
    case 10:
        grade1 = 'A';
        break;
    case 9:
        grade1 = 'A';
        break;
    case 8:
        grade1 = 'A';
        break;
    case 7:
        grade1 = 'B';
        break;
    case 6:
        grade1 = 'B';
        break;
    case 5:
        grade1 = 'C';
        break;
    case 4:
        grade1 = 'D';
        break;
    default:
        grade1 = 'F';
        break;
    }

    switch ((int)score2 / 10)
    {
    case 10:
        grade2 = 'A';
        break;
    case 9:
        grade2 = 'A';
        break;
    case 8:
        grade2 = 'A';
        break;
    case 7:
        grade2 = 'B';
        break;
    case 6:
        grade2 = 'B';
        break;
    case 5:
        grade2 = 'C';
        break;
    case 4:
        grade2 = 'D';
        break;
    default:
        grade2 = 'F';
        break;
    }

    switch ((int)score3 / 10)
    {
    case 10:
        grade3 = 'A';
        break;
    case 9:
        grade3 = 'A';
        break;
    case 8:
        grade3 = 'A';
        break;
    case 7:
        grade3 = 'B';
        break;
    case 6:
        grade3 = 'B';
        break;
    case 5:
        grade3 = 'C';
        break;
    case 4:
        grade3 = 'D';
        break;
    default:
        grade3 = 'F';
        break;
    }

    // Print grades and average
    printf("Your letter grades are ");

    if((score1==100) || (score1>= 90) || (70<=score1<80)) printf("%c+,", grade1);
    else printf("%c,",grade1);
     if((score2==100) || (score2>= 90) || (70<=score2<80)) printf("%c+,", grade2);
     else printf("%c,",grade1);
     if((score3==100) || (score3>= 90) || (70<=score3<80)) printf("%c+,", grade3);
     else printf("%c,",grade3);
     printf("with an %.2f average\n",avg);
}

void arithmatic_operation()
{
    int m = 0, n = 0;
    char operator;
    
    float result, answer; // answer is users result is the true

    printf("Enter an arithmetic operation (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two numbers:");
    scanf("%d %d", &m, &n);

    printf("Result :");
    scanf("%f", &answer);

    switch (operator)
    {
    case '+':

        result = m + n;

        if (answer == result)
            printf("Bravo, correct answer! \n");
        else
            printf("Wrong answer, try again. \n");

        break;
    case '*':

        result = m * n;
        if (answer == result)
            printf("Bravo, correct answer! \n");
        else
            printf("Wrong answer, try again. \n");

        break;
    case '-':

        result = m - n;

        if (answer == result)
            printf("Bravo, correct answer! \n");
        else
            printf("Wrong answer, try again. \n");

        break;
    case '/':

        result = m / n;

        if (answer == result)
            printf("Bravo, correct answer! \n");
        else
            printf("Wrong answer, try again. \n");

        break;

    default:
        printf("Wrong Operatorrr");

        break;
    }
}

int main()
{
    int x, y, z;
    
    median_manager(x, y, z);
    exam_calc();
    arithmatic_operation();
    return 0;
}