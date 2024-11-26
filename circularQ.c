#include<stdio.h>
#define N 5

int queue[N];
int front =-1;
int rear = -1;

void enqueue(int x)
{
    if (front ==-1 && rear ==-1) {
        front = rear =0;
        queue[front]=x;
    }
    else if(((rear+1)%N)==front) {
        printf("Queue is full \n");
    }
    else {
        rear = (rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front ==-1 && rear ==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        printf("Deleted element is %d \n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Deleted element is %d \n", queue[front]);
        front = (front+1)%N;
    }
}
void display(){
    int i = front;
    if(front ==-1 && rear ==-1){
        printf("Queue is empty\n");
    }
    else{
        while(i!= rear){
            printf("%d ", queue[i]);
            i= (i+1)%N;      
        }
        printf("%d\n", queue[rear]);
    }
}
void peek(){
    printf("Front is %d \n", queue[front]);
}
