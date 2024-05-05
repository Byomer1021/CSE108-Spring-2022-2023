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

Order* dequeue(Order* queue, int* orderID) {
    if (queue == NULL) {
        *orderID = -1; // Indicate empty queue
        return NULL;
    } else {
        Order* temp = queue;
        *orderID = queue->orderID;
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

void serializeFIFO(Order* queue, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.");
        return;
    }

    Order* current = queue;
    while (current != NULL) {
        fwrite(current, sizeof(Order), 1, file);
        current = current->next;
    }

    fclose(file);
}

Order* deserializeFIFO(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading.");
        return NULL;
    }

    Order* queue = NULL;
    Order* current = NULL;
    Order temp;

    while (fread(&temp, sizeof(Order), 1, file) == 1) {
        Order* newOrder = (Order*)malloc(sizeof(Order));
        memcpy(newOrder, &temp, sizeof(Order));
        newOrder->next = NULL;

        if (queue == NULL) {
            queue = newOrder;
        } else {
            current->next = newOrder;
        }
        current = newOrder;
    }

    fclose(file);
    return queue;
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
    int orderID;
    printf("Dequeued Order ID: %d\n", queue->orderID);
    queue = dequeue(queue, &orderID);
    display(queue);
    printf("\n\n");

    // Serialize FIFO
    serializeFIFO(queue, "fifo_orders.bin");
    printf("FIFO Data Structure Serialized.\n\n");

    // Deserialize FIFO
    printf("Deserialize FIFO:\n");
    Order* deserializedQueue = deserializeFIFO("fifo_orders.bin");
    display(deserializedQueue);
    printf("\n\n");

    // Cleanup
    Order* current = deserializedQueue;
    while (current != NULL) {
        Order* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
