#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

struct Student
{
	int ID;
	int age;
	float gpa;
};

int *createARR(int size)
{
	int *arr = (int *)malloc(size * sizeof(int));

	printf("Enter the elements of the array: ");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	return arr;
}

int findMin(int *arr, int size)
{
	int min = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

int *calculateSum(int *arr, int size)
{
	int *cumulativeArray = (int *)calloc(size, sizeof(int));

	cumulativeArray[0] = arr[0];
	for (int i = 1; i < size; i++)
	{
		cumulativeArray[i] = cumulativeArray[i - 1] + arr[i];
	}

	return cumulativeArray;
}

void printmyArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void generateRandomStudents(struct Student *students)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		students[i].ID = i + 1;
		students[i].age = rand() % 10 + 18;
		students[i].gpa = (float)(rand() % 50) / 10.0;
	}
	// for (int j = 0; j < 10; j++)
	// {
	// 	printf("ID:%d , AGE:%d , pga:%d \n", students[j].ID, students[j].age, students[j].gpa);
	// }
}

float calculateAverageGPA(struct Student *students)
{
	float sum = 0.0;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		sum += students[i].gpa;
	}

	float average = sum / ARRAY_SIZE;

	return average;
}

int main()
{
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);

	// part1

	int *array = createARR(size);

	int min = findMin(array, size);
	printf("Min of the array elements: %d\n", min);

	free(array);

	// part2

	int *firstArray = createARR(size);

	int *secondArray = calculateSum(firstArray, size);

	printf("First array: ");
	printmyArray(firstArray, size);

	printf("Second array (cumulative sum): ");
	printmyArray(secondArray, size);

	free(firstArray);
	free(secondArray);

	// part3

	srand(time(NULL));

	float totalAverage = 0.0;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		struct Student *students = (struct Student *)malloc(ARRAY_SIZE * sizeof(struct Student));

		generateRandomStudents(students);

		float averageGPA = calculateAverageGPA(students);
		totalAverage += averageGPA;

		free(students);
	}

	float overallAverage = totalAverage / ARRAY_SIZE;

	printf("Average GPA of %d x %d students: %.1f\n", ARRAY_SIZE, ARRAY_SIZE, overallAverage);

	return 0;
}
