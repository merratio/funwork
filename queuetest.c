#include<stdio.h>
#include<string.h>
#define SIZE 5

void enQueue();
void deQueue();
void display();

char items[SIZE][10], front= -1, rear = -1;

int main()
{

    deQueue();
    enQueue();
    enQueue();
    enQueue();


    display();
    deQueue();
    display();

    return 0;
}

void enQueue(){
    char value[10];

    printf("\nEnter the value that you want to be added to queue: ");
    scanf("%s",value);

    if(rear == SIZE - 1){
        printf("\nQueue is full");
    }
    else{
        if(front == -1)
        front = 0;
        rear++;
        strcpy(items[rear],value);
        printf("\n inserted  -> %s",value);


        int x;
        printf("Enter the value: ");
        scanf("%d", &x);
        
    }
}

void deQueue(){
    if(front == -1){
        printf("The queue is empty");
    }
    else{
        printf("Deleted");
        front++;
        if(front > rear){
            front = rear -1;
        }
    }
}

void display(){
    if(rear == -1){
        printf("Queue is empty");
    }
    else{
        printf("\nThe elements of the queue are : ");
        for(int i = front; i<=rear; i++){
            printf("%s ",items[i]);
        }
    }
    printf("\n");
}