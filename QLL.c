#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
struct node *newnode;

void enqueue() {
    int x;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0; // Initialize next pointer to NULL

    if (front == 0 && rear == 0) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    struct node *temp;
    if (front == 0 && rear == 0) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        front = front->next;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        if (front == 0) { // If queue becomes empty
            rear = 0;
        }
    }
}

void display() {
    struct node *temp;
    if (front == 0 && rear == 0) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        printf("Queue elements are: ");
        while (temp != 0) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek() {
    if (front == 0 && rear == 0) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", front->data);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
