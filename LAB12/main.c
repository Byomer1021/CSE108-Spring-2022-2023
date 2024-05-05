#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer
{
	char name[100];
	int age;
	char priorityGroupName[20];
	int priorityLevel;
	struct Customer *prev;
	struct Customer *next;
} Customer;

void readCustomersFromFile(Customer **queue)
{
	FILE *file = fopen("customers.txt", "r");
	if (file == NULL)
	{
		printf("Error opening the file.\n");
		return;
	}

	char line[200];
	while (fgets(line, sizeof(line), file))
	{
		char name[100];
		int age;
		char priorityGroupName[20];
		int priorityLevel;

		sscanf(line, "%s %d %s %d", name, &age, priorityGroupName, &priorityLevel);

		// for (int i = 0; i < 6; i++)
		// {
		// 	printf("%s", name);
		// }

		// Creating new customer
		Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
		strcpy(newCustomer->name, name);
		newCustomer->age = age;
		strcpy(newCustomer->priorityGroupName, priorityGroupName);
		newCustomer->priorityLevel = priorityLevel;
		newCustomer->prev = NULL;
		newCustomer->next = NULL;

		// Insert mnew customer into the priority queue
		if (*queue == NULL)
		{
			// If queue empty make the new customer the first element
			*queue = newCustomer;
		}
		else
		{
			// Find the appropriate position to insert the newcustomer based on priority level
			Customer *current = *queue;
			while (current != NULL && current->priorityLevel >= newCustomer->priorityLevel)
			{
				current = current->next;
			}

			if (current == NULL)
			{
				// Insert new customer at the end of the queue
				Customer *last = *queue;
				while (last->next != NULL)
				{
					last = last->next;
				}
				last->next = newCustomer;
				newCustomer->prev = last;
			}
			else
			{
				// Insert the new customer before the current customer
				if (current->prev != NULL)
				{
					current->prev->next = newCustomer;
				}
				else
				{
					*queue = newCustomer;
				}
				newCustomer->prev = current->prev;
				current->prev = newCustomer;
				newCustomer->next = current;
			}
		}
	}

	fclose(file);
}
void writeCustomersToFile(Customer *queue)
{
	FILE *file = fopen("customers.txt", "w");
	if (file == NULL)
	{
		printf("Error opening the file.\n");
		return;
	}

	Customer *current = queue;
	while (current != NULL)
	{
		fprintf(file, "%s %d %s %d\n", current->name, current->age, current->priorityGroupName, current->priorityLevel);
		current = current->next;
	}

	fclose(file);
}
void insert_Customer(Customer **queue, char *name, int age, char *priorityGroupName, int priorityLevel)
{
	// Create new customer
	Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
	strcpy(newCustomer->name, name);
	newCustomer->age = age;
	strcpy(newCustomer->priorityGroupName, priorityGroupName);
	newCustomer->priorityLevel = priorityLevel;
	newCustomer->prev = NULL;
	newCustomer->next = NULL;

	// Insert new customer into the priority queue
	if (*queue == NULL)
	{
		// If the queue is empty make the new customer the first element
		*queue = newCustomer;
	}
	else
	{
		// Find the appropriate position to insert the new customer based on priority level
		Customer *current = *queue;
		while (current != NULL && current->priorityLevel >= newCustomer->priorityLevel)
		{
			current = current->next;
		}

		if (current == NULL)
		{
			// Insert the new customer at the end of the queue
			Customer *last = *queue;
			while (last->next != NULL)
			{
				last = last->next;
			}
			last->next = newCustomer;
			newCustomer->prev = last;
		}
		else
		{
			// Insert the new customer before the current customer
			if (current->prev != NULL)
			{
				current->prev->next = newCustomer;
			}
			else
			{
				*queue = newCustomer;
			}
			newCustomer->prev = current->prev;
			current->prev = newCustomer;
			newCustomer->next = current;
		}
	}

	printf("Customer added successfully ...\n");

	// Write the updated customer data to the file
	writeCustomersToFile(*queue);
}

void remove_Customer(Customer **queue, char *name)
{
	if (*queue == NULL)
	{
		printf("Queue is empty. No customer to remove.\n");
		return;
	}

	Customer *current = *queue;
	while (current != NULL)
	{
		// printf("asdasd");
		if (strcmp(current->name, name) == 0)
		{
			if (current->prev != NULL)
			{
				current->prev->next = current->next;
				// printf("---as");
			}
			else
			{
				*queue = current->next;
			}
			if (current->next != NULL)
			{
				current->next->prev = current->prev;
			}
			free(current);
			printf("Customer '%s'removed successfully .\n", name);
			// Write the updated customer data to the file
			writeCustomersToFile(*queue);
			return;
		}
		current = current->next;
	}

	printf("Customer '%s' not found.\n", name);
}

void display_Customers(Customer *queue)
{
	if (queue == NULL)
	{
		printf("Queue is empty.\n");
		return;
	}

	printf("Customers:\n");

	Customer *current = queue;
	while (current != NULL)
	{
		printf("Name: %s, Age: %d, Priority Group: %s, Priority Level: %d\n", current->name, current->age, current->priorityGroupName, current->priorityLevel);
		current = current->next;
	}
}

void search_Customer(Customer *queue, char *name)
{
	if (queue == NULL)
	{
		printf("Queue is empty. No customer found.\n");
		return;
	}

	Customer *current = queue;
	while (current != NULL)
	{
		// printf("aaaaaaaa");
		if (strcmp(current->name, name) == 0)
		{
			printf("Customer found:\n");
			printf("Name: %s, Age: %d, Priority Group: %s, Priority Level: %d\n", current->name, current->age, current->priorityGroupName, current->priorityLevel);
			return;
		}
		current = current->next;
	}

	printf("Customer '%s' not found.\n", name);
}

void change_Priority(Customer *queue, char *name, int newPriorityLevel)
{
	if (queue == NULL)
	{
		printf("Queue is empty. No customer to update.\n");
		return;
	}

	Customer *current = queue;
	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			current->priorityLevel = newPriorityLevel;
			printf("Priority level for customer '%s' updated to %d.\n", name, newPriorityLevel);
			// Write the updated customer data to the file
			writeCustomersToFile(queue);
			return;
		}
		current = current->next;
	}

	printf("Customer '%s' not found. Cannot update priority level.\n", name);
}

void Menu()
{
	printf("\nMenu:\n");
	printf("1- Insert new customer\n");
	printf("2- Remove customer\n");
	printf("3- Display customers in order\n");
	printf("4- Search a customer\n");
	printf("5- Change priority settings\n");
	printf("6- Exit\n");
}

int main()
{
	Customer *queue = NULL;
	int choice;

	printf("*************************\n");
	printf("Welcome to the ABC bank\n");

	do
	{
		Menu();
		printf("Please select an option: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			char name[100];
			int age;
			char priorityGroupName[100];
			int priorityLevel;

			printf("Enter customer name: ");
			scanf("%s", name);
			printf("Enter customer age: ");
			scanf("%d", &age);
			printf("Enter priority group name: ");
			scanf("%s", priorityGroupName);
			printf("Enter priority level: ");
			scanf("%d", &priorityLevel);

			insert_Customer(&queue, name, age, priorityGroupName, priorityLevel);
			break;
		}
		case 2:
		{
			char name[100];
			printf("Enter the name of the customer to remove: ");
			scanf("%s", name);
			remove_Customer(&queue, name);
			break;
		}
		case 3:
			display_Customers(queue);
			break;
		case 4:
		{
			char name[100];
			printf("Enter the name of the customer to search: ");
			scanf("%s", name);
			search_Customer(queue, name);
			break;
		}
		case 5:
		{
			char name[100];
			int newPriorityLevel;
			printf("Enter the name of the customer to change priority: ");
			scanf("%s", name);
			printf("Enter the new priority level: ");
			scanf("%d", &newPriorityLevel);
			change_Priority(queue, name, newPriorityLevel);
			break;
		}
		case 6:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid option. Please try again.\n");
			break;
		}
	} while (choice != 6);

	// Free memory
	Customer *current = queue;
	while (current != NULL)
	{
		Customer *temp = current;
		current = current->next;
		free(temp);
	}

	return 0;
}
