#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}NODE;

NODE *front=NULL,*rear=NULL;

void insert(){
    NODE* temp=(NODE*)malloc(sizeof(NODE));

    printf("Enter the element to insert: ");
    scanf("%d",&temp->info);

    temp->next=NULL;

    if(front==NULL){
        front=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

void delete(){
    NODE* temp;

    if(front==NULL){
        printf("Queue Underflow\n");
        return;
    }

    temp=front;
    printf("Deleted element is: %d\n",temp->info);

    front=front->next;

    if(front==NULL)
        rear=NULL;

    free(temp);
}

void display(){
    NODE* ptr=front;

    if(ptr==NULL){
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");

    while(ptr->next!=NULL){
        printf("%d -> ",ptr->info);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->info);
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