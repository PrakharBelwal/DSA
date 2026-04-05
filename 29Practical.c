#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node{
    int info;
    struct node* next;
}NODE;

int cq[MAX];
int front=-1,rear=-1;

void insertArray(){
    int x;

    if((rear+1)%MAX==front){
        printf("Circular Queue Overflow\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d",&x);

    if(front==-1){
        front=rear=0;
    }
    else{
        rear=(rear+1)%MAX;
    }

    cq[rear]=x;
}

void deleteArray(){

    if(front==-1){
        printf("Circular Queue Underflow\n");
        return;
    }

    printf("Deleted element is: %d\n",cq[front]);

    if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
}

void displayArray(){
    int i;

    if(front==-1){
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements are:\n");

    i=front;

    while(i!=rear){
        printf("%d, ",cq[i]);
        i=(i+1)%MAX;
    }

    printf("%d\n",cq[rear]);
}

NODE *f=NULL,*r=NULL;

void insertList(){
    NODE* temp=(NODE*)malloc(sizeof(NODE));

    printf("Enter element to insert: ");
    scanf("%d",&temp->info);

    if(f==NULL){
        f=r=temp;
        temp->next=temp;
    }
    else{
        temp->next=f;
        r->next=temp;
        r=temp;
    }
}

void deleteList(){
    NODE* temp;

    if(f==NULL){
        printf("Circular Queue Underflow\n");
        return;
    }

    temp=f;
    printf("Deleted element is: %d\n",temp->info);

    if(f==r){
        f=r=NULL;
    }
    else{
        f=f->next;
        r->next=f;
    }

    free(temp);
}

void displayList(){
    NODE* ptr=f;

    if(ptr==NULL){
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements are:\n");

    while(ptr->next!=f){
        printf("%d -> ",ptr->info);
        ptr=ptr->next;
    }

    printf("%d\n",ptr->info);
}

int main(){

    int sel1,sel2;

    do{

        printf("\n--------Menu--------\n");
        printf("1. Circular Queue using Array\n");
        printf("2. Circular Queue using Linked List\n");
        printf("0. Exit\n");

        printf("\n--Enter your choice--\n");
        scanf("%d",&sel1);

        switch(sel1){

            case 1:

                do{

                    printf("\n--------Submenu--------\n");
                    printf("1. Insert\n");
                    printf("2. Delete\n");
                    printf("3. Display\n");
                    printf("0. Exit\n");

                    printf("\n--Enter your choice--\n");
                    scanf("%d",&sel2);

                    switch(sel2){

                        case 1:
                            insertArray();
                            break;

                        case 2:
                            deleteArray();
                            break;

                        case 3:
                            displayArray();
                            break;
                    }

                }while(sel2!=0);

                break;

            case 2:

                do{

                    printf("\n--------Submenu--------\n");
                    printf("1. Insert\n");
                    printf("2. Delete\n");
                    printf("3. Display\n");
                    printf("0. Exit\n");

                    printf("\n--Enter your choice--\n");
                    scanf("%d",&sel2);

                    switch(sel2){

                        case 1:
                            insertList();
                            break;

                        case 2:
                            deleteList();
                            break;

                        case 3:
                            displayList();
                            break;
                    }

                }while(sel2!=0);

                break;
        }

    }while(sel1!=0);

    return 0;
}