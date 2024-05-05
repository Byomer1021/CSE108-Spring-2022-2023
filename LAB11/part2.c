#include <stdio.h>
#include <stdlib.h>

struct ExamPaper
{
	char *studentName;
	long long int studentNumber;
	int score;
	struct ExamPaper *next;
};




struct ExamPaper *push(struct ExamPaper *stack, char *studentName, long long int studentNumber, int score)
{
	struct ExamPaper *newPaper = (struct ExamPaper *)malloc(sizeof(struct ExamPaper));
	newPaper->studentName = studentName;
	newPaper->studentNumber = studentNumber;
	newPaper->score = score;

	newPaper->next = stack;

	printf("Exam Paper Added: Student Name: %s, Student Number: %lld, Score: %d\n", studentName, studentNumber, score);

	return newPaper;
}

struct ExamPaper *pop(struct ExamPaper *stack)
{
	if (stack == NULL)
	{
		printf("Stack is empty.\n");
		return NULL;
	}

	struct ExamPaper *topPaper = stack;

	stack = stack->next;

	printf("Last Added Exam Paper:\n- Student Name: %s, Student Number: %lld, Score: %d\n", topPaper->studentName, topPaper->studentNumber, topPaper->score);

	free(topPaper);

	return stack;
}

int isEmpty(struct ExamPaper *stack)
{
	if (stack == NULL)
	{
		printf("Stack is empty.\n");
		return 1;
	}
	else
	{
		printf("Stack is not empty.\n");
		return 0;
	}
}

void display(struct ExamPaper *stack)
{
	printf("Exam Papers in the Stack:\n");

	struct ExamPaper *currentPaper = stack;

	while (currentPaper != NULL)
	{
		printf("- %s, Student Number: %lld, Score: %d\n", currentPaper->studentName, currentPaper->studentNumber, currentPaper->score);
		currentPaper = currentPaper->next;
	}
}

int main()
{
	struct ExamPaper *stack = NULL;

	stack = push(stack, "Zehra Bilici", 20220000001, 90);

	display(stack);

	stack = push(stack, "Baris Özcan", 20190000002, 85);
	stack = push(stack, "Mehmet Burak Koca", 20180000010, 95);

	stack = pop(stack);
	display(stack);

	isEmpty(stack);

	return 0;
}
