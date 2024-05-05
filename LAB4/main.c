#include <stdio.h>

void drawSquare(int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void drawTriangle(int size)
{
    int i, j, k;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            printf("  ");
        }
        for (k = 0; k < 2 * i + 1; k++)
        {
            if (k == 0 || k == 2 * i || i == size - 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void writeShapesToFile()
{
    char shapeType;
    int size;
    FILE *fp = fopen("shapes.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file.");
        return;
    }
    while (1)
    {
        printf("Enter shape type (s: square, t: triangle) and size (between 3 - 10), or 'e' to exit: ");
        scanf(" %c", &shapeType);
        if (shapeType == 'e')
        {
            break;
        }
        scanf("%d", &size);
       while (size < 3 || size > 10)
        {
            printf("Size must be between 3 - 10.\n");
            printf("Enter size (between 3 - 10) again: ");
            scanf("%d", &size);
        }
        if (shapeType == 's')
        {
            fprintf(fp, "s,%d\n", size);
        }
        else if (shapeType == 't')
        {
            fprintf(fp, "t,%d\n", size);
        }
        else
        {
            printf("Invalid shape type.\n");
        }
    }
    fclose(fp);
}

void readShapesFromFileAndDraw()
{
    char shapeType;
    int size;
    FILE *fp = fopen("shapes.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.");
        return;
    }
    while (fscanf(fp, "%c,%d\n", &shapeType, &size) == 2)
    {
        if (shapeType == 's')
        {
            drawSquare(size);
            printf("\n");
        }
        else if (shapeType == 't')
        {
            drawTriangle(size);
            printf("\n");
        }
        else
        {
            printf("Invalid shape type.\n");
        }
    }
    fclose(fp);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nWelcome to shape reader! Please make your choice to continue:\n");
        printf("1) Generate a shape file\n");
        printf("2) Read and draw a shape file\n");
        printf("3) Terminate the program\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            writeShapesToFile();
            break;
        case 2:
            readShapesFromFileAndDraw();
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}
