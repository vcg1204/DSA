#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = 0, *newnode;

void push() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to be pushed: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
}

void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        temp = top;
        printf("Popped element is: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        temp = top;
        printf("Stack elements are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
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
