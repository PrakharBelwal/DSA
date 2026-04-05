#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int queue[MAX];
int front=-1,rear=-1;

void insert(){
    int x;

    if(rear==MAX-1){
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d",&x);

    if(front==-1)
        front=0;

    rear++;
    queue[rear]=x;
}

void delete(){
    if(front==-1 || front>rear){
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element is: %d\n",queue[front]);
    front++;

    if(front>rear){
        front=-1;
        rear=-1;
    }
}

void display(){
    int i;

    if(front==-1){
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");

    for(i=front;i<=rear;i++){
        printf("%d",queue[i]);
        if(i<rear)
            printf(", ");
    }

    printf("\n");
}

int main(){

    int choice;

    do{

        printf("\n--------Menu--------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("0. Exit\n");

        printf("\n--Enter your choice--\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;
        }

    }while(choice!=0);

    return 0;
}