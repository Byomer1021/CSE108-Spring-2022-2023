#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
//hocam lab11 e serialize ve deserialize fonksiyonları ekledim örnekleri değiştirmedim sizin isimleriniz duruyor o yüzden hala
typedef struct Order {
    char customerName[max];
    int orderID;
    char items[max];
    char orderTime[max];
    struct Order* next;
} Order;

Order* push(Order* stack, char* customerName, int orderID, char* items, char* orderTime) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    strcpy(newOrder->customerName, customerName);
    newOrder->orderID = orderID;
    strcpy(newOrder->items, items);
    strcpy(newOrder->orderTime, orderTime);
    newOrder->next = stack;
    return newOrder;
}

Order* pop(Order* stack) {
    if (stack == NULL) {
        return NULL;
    } else {
        Order* temp = stack;
        stack = stack->next;
        free(temp);
        return stack;
    }
}

void display(Order* stack) {
    Order* current = stack;
    while (current != NULL) {
        printf("- Order ID: %d, Customer Name: %s, Items: %s\n", current->orderID, current->customerName, current->items);
        current = current->next;
    }
}

void serializeLIFO(Order* stack, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.");
        return;
    }

    Order* current = stack;
    while (current != NULL) {
        fwrite(current, sizeof(Order), 1, file);
        current = current->next;
    }

    fclose(file);
}

Order* deserializeLIFO(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading.");
        return NULL;
    }

    Order* stack = NULL;
    Order* current = NULL;
    Order temp;

    while (fread(&temp, sizeof(Order), 1, file) == 1) {
        Order* newOrder = (Order*)malloc(sizeof(Order));
        memcpy(newOrder, &temp, sizeof(Order));
        newOrder->next = NULL;

        if (stack == NULL) {
            stack = newOrder;
        } else {
            current->next = newOrder;
        }
        current = newOrder;
    }

    fclose(file);
    return stack;
}

int main() {
    Order* stack = NULL;

    // Push
    printf("Push Operation:\n");
    stack = push(stack, "Baris Ozcan", 101, "Burger, Fries, Coke", "10:00 AM");
    printf("Pushed: Order ID: %d, Customer Name: %s, Items: %s\n", stack->orderID, stack->customerName, stack->items);
    display(stack);
    printf("\n\n");

    // Push
    printf("Push Operation:\n");
    stack = push(stack, "Zehra Bilici", 102, "Pizza, Salad, Ice Cream", "10:30 AM");
    printf("Pushed: Order ID: %d, Customer Name: %s, Items: %s\n", stack->orderID, stack->customerName, stack->items);
    display(stack);
    printf("\n\n");

    // Push
    printf("Push Operation:\n");
    stack = push(stack, "Mehmet Burak Koca", 103, "Steak, Mashed Potatoes, Salad", "11:00 AM");
    printf("Pushed: Order ID: %d, Customer Name: %s, Items: %s\n", stack->orderID, stack->customerName, stack->items);
    display(stack);
    printf("\n\n");

    // Pop
    printf("Pop Operation:\n");
    printf("Popped Orders:\n");
    stack = pop(stack);
    display(stack);
    printf("\n\n");

    // Serialize LIFO
    serializeLIFO(stack, "lifo_orders.bin");
    printf("LIFO Data Structure Serialized.\n\n");

    // Deserialize LIFO
    printf("Deserialize LIFO:\n");
    Order* deserializedStack = deserializeLIFO("lifo_orders.bin");
    display(deserializedStack);
    printf("\n\n");

    // Cleanup
    Order* current = deserializedStack;
    while (current != NULL) {
        Order* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
