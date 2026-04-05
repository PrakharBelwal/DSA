#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int queue[MAX];
int front=0,rear=-1;

int stack[MAX];
int top=-1;

void generateCoupon(){
    int id;

    if(rear==MAX-1){
        printf("Patient queue is full\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d",&id);

    rear++;
    queue[rear]=id;

    printf("Coupon generated for Patient ID %d\n",id);
}

void servePatient(){
    int id;

    if(front>rear){
        printf("No waiting patients\n");
        return;
    }

    id=queue[front];
    front++;

    top++;
    stack[top]=id;

    printf("Patient %d served\n",id);
}

void displayQueue(){
    int i;

    if(front>rear){
        printf("Waiting queue is empty\n");
        return;
    }

    printf("Waiting patients:\n");

    for(i=front;i<=rear;i++){
        printf("%d",queue[i]);
        if(i<rear)
            printf(", ");
    }

    printf("\n");
}

void displayVisited(){
    int i;

    if(top==-1){
        printf("No visited patients\n");
        return;
    }

    printf("Visited patients:\n");

    for(i=top;i>0;i--){
        printf("%d -> ",stack[i]);
    }
    printf("%d\n",stack[0]);
}

int main(){

    int choice;

    do{

        printf("\n--------Menu--------\n");
        printf("1. Generate Coupon\n");
        printf("2. Serve Patient\n");
        printf("3. Display Waiting Queue\n");
        printf("4. Display Visited Patients\n");
        printf("5. Get Visited Count\n");
        printf("0. Exit\n");

        printf("\n--Enter your choice--\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                generateCoupon();
                break;

            case 2:
                servePatient();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                displayVisited();
                break;

            case 5:
                printf("Total visited patients: %d\n",top+1);
                break;
        }

    }while(choice!=0);

    return 0;
}