#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode;

void create(){
    struct node *temp;
    head = 0;
    int choice=1;

    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data to be added : \n");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if(head ==0){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to add data? \n1:yes \n0:no");
        scanf("%d", &choice);

    }
}
void insert_beg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to be added at the beginning: \n");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void insert_end()
{
    struct node *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to be added at the end: \n");
    scanf("%d", &newnode->data);
    newnode->next = 0; // since it is added at the end

    temp = head;
    while (temp != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_after()
{
    int x, value;
    struct node *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value after which you want to insert:\n");
    scanf("%d", &x);
    printf("Enter data to be inserted: \n");
    scanf("%d", &value);
    newnode->data = value;
    temp = head;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_before()
{
    int x, value;
    struct node *temp, *prevnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value before which you want to insert:\n");
    scanf("%d", &x);
    printf("Enter data to be inserted: \n");
    scanf("%d", &value);
    newnode->data = value;
    temp = head;

    while (temp->data != x)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == head) // no node present
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        newnode->next = temp;
        prevnode->next = newnode;
    }
}

void delete(){
    int x;
    struct node*temp , *prevnode;
    printf("Enter value to be deleted:");
    scanf("%d", &x);

    temp = head;
    while(temp != NULL && temp->data !=x){
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
    printf("Value not found");
    }else if (temp == head) {
    head = head->next;
    free(temp);
    }
    else {
        prevnode->next = temp->next;
        free(temp);
    }
}

void display(){
    struct node*temp;
    temp = head;
    while(temp->next !=0){
        printf("%d ",  temp->data);
        temp = temp->next;
    } 
}

int main() {
    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Create\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert After\n");
        printf("5. Insert Before\n");
        printf("6. Delete\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_after();
            break;
        case 5:
            insert_before();
            break;
        case 6:
            delete();
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}