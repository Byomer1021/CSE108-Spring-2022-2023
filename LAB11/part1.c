#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

typedef struct Order {
    char customerName[max];
    int orderID;
    char items[max];
    char orderTime[max];
    struct Order* next;
} Order;


Order* enqueue(Order* queue, char* customerName, int orderID, char* items, char* orderTime) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    strcpy(newOrder->customerName, customerName);
    newOrder->orderID = orderID;
    strcpy(newOrder->items, items);
    strcpy(newOrder->orderTime, orderTime);
    newOrder->next = NULL;

    if (queue == NULL) {
        return newOrder;
    } else {
        Order* current = queue;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newOrder;
        return queue;
    }
}

Order* dequeue(Order* queue) {
    if (queue == NULL) {
        return NULL;
    } else {
        Order* temp = queue;
        queue = queue->next;
        free(temp);
        return queue;
    }
}

void display(Order* queue) {
    Order* current = queue;
    while (current != NULL) {
        printf("- Order ID: %d, Customer Name: %s, Items: %s\n", current->orderID, current->customerName, current->items);
        current = current->next;
    }
}

void updateOrder(Order* queue, int orderID, char* newItems) {
    Order* current = queue;
    while (current != NULL) {
        if (current->orderID == orderID) {
            strcpy(current->items, newItems);
            break;
        }
        current = current->next;
    }
}

int main() {
    Order* queue = NULL;

    // Enqueue 
    printf("Enqueue Operation:\n");
    queue = enqueue(queue, "Baris Ozcan", 101, "Burger, Fries, Coke", "10:00 AM");
    printf("Enqueued: Order ID: %d, Customer Name: %s, Items: %s\n", queue->orderID, queue->customerName, queue->items);
    display(queue);
	printf("\n\n");

    // Enqueue 
    printf("Enqueue Operation:\n");
    queue = enqueue(queue, "Zehra Bilici", 102, "Pizza, Salad, Ice Cream", "10:30 AM");
    printf("Enqueued: Order ID: %d, Customer Name: %s, Items: %s\n", queue->next->orderID, queue->next->customerName, queue->next->items);
    display(queue);
	printf("\n\n");

    // Enqueue 
    printf("Enqueue Operation:\n");
    queue = enqueue(queue, "Mehmet Burak Koca", 103, "Steak, Mashed Potatoes, Salad", "11:00 AM");
    printf("Enqueued: Order ID: %d, Customer Name: %s, Items: %s\n", queue->next->next->orderID, queue->next->next->customerName, queue->next->next->items);
    display(queue);
	printf("\n\n");

       // Dequeue
    printf("Dequeue Operation:\n");
    printf("Dequeued Orders Older than Threshold Time:\n");
    queue = dequeue(queue);
    display(queue);
	printf("\n\n");

    // Display
    printf("Display Orders by Order Time:\n");
    display(queue);
	printf("\n\n");

    // Display
    printf("Display Orders by Customer Name:\n");
    display(queue);
	printf("\n\n");

    // Update 
    printf("Update Order:\n");
    updateOrder(queue, 102, "Pizza, Salad, Coke");
    printf("Updated Order: Order ID: %d, Customer Name: %s, Items: %s\n", queue->next->orderID, queue->next->customerName, queue->next->items);
    display(queue);
	printf("\n\n");

    // Delete 
    printf("Delete Order:\n");
    Order* temp = queue;
    queue = queue->next;
    free(temp);
    printf("Deleted Order: Order ID: %d\n", temp->orderID);
    display(queue);
	printf("\n\n");

    // Disp
    printf("Display Orders by Order Time:\n");
    display(queue);

    return 0;
}

