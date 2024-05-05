#include <stdio.h>
#include <string.h>

int min(char *s)
{
    int n = strlen(s);
    int ops = 0;
    int i = 0;

    while (i < n)
    {
        int j = i + 1;
        while (j < n && s[j] == s[i])
        {
            j++;
        }
        ops++;
        i = j;
    }

    return ops - 1;
}

void foo_min_max(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
}

int main()
{ // part1
    char pt1[100];
    scanf("%s", s);
    printf("%d\n", min(s));

    // part3
    int arr[50], j = 0, i;
    printf("Enter numbers(enter -1 to finish):");
    while (i != -1)
    {
        scanf("%d", &i);
        if (i != -1)
        {
            arr[j] = i;
            j++;
        }
    }
    foo_min_max(arr, j);
}
