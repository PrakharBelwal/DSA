#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node{
    int info;
    struct node* next;
    struct node* prev;
}NODE;

int deque[MAX];
int front=-1,rear=-1;

void insertFrontArray(){
    int x;

    if((front==0 && rear==MAX-1) || front==rear+1){
        printf("Deque Overflow\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d",&x);

    if(front==-1){
        front=rear=0;
    }
    else if(front==0){
        front=MAX-1;
    }
    else{
        front--;
    }

    deque[front]=x;
}

void insertRearArray(){
    int x;

    if((front==0 && rear==MAX-1) || front==rear+1){
        printf("Deque Overflow\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d",&x);

    if(front==-1){
        front=rear=0;
    }
    else if(rear==MAX-1){
        rear=0;
    }
    else{
        rear++;
    }

    deque[rear]=x;
}

void deleteFrontArray(){

    if(front==-1){
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element is: %d\n",deque[front]);

    if(front==rear){
        front=rear=-1;
    }
    else if(front==MAX-1){
        front=0;
    }
    else{
        front++;
    }
}

void deleteRearArray(){

    if(front==-1){
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element is: %d\n",deque[rear]);

    if(front==rear){
        front=rear=-1;
    }
    else if(rear==0){
        rear=MAX-1;
    }
    else{
        rear--;
    }
}

void displayArray(){
    int i;

    if(front==-1){
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements are:\n");

    i=front;

    while(i!=rear){
        printf("%d, ",deque[i]);
        i=(i+1)%MAX;
    }

    printf("%d\n",deque[rear]);
}

NODE *f=NULL,*r=NULL;

void insertFrontList(){
    NODE* temp=(NODE*)malloc(sizeof(NODE));

    printf("Enter element to insert: ");
    scanf("%d",&temp->info);

    temp->prev=NULL;
    temp->next=f;

    if(f==NULL){
        f=r=temp;
    }
    else{
        f->prev=temp;
        f=temp;
    }
}

void insertRearList(){
    NODE* temp=(NODE*)malloc(sizeof(NODE));

    printf("Enter element to insert: ");
    scanf("%d",&temp->info);

    temp->next=NULL;
    temp->prev=r;

    if(r==NULL){
        f=r=temp;
    }
    else{
        r->next=temp;
        r=temp;
    }
}

void deleteFrontList(){
    NODE* temp;

    if(f==NULL){
        printf("Deque Underflow\n");
        return;
    }

    temp=f;
    printf("Deleted element is: %d\n",temp->info);

    f=f->next;

    if(f==NULL)
        r=NULL;
    else
        f->prev=NULL;

    free(temp);
}

void deleteRearList(){
    NODE* temp;

    if(r==NULL){
        printf("Deque Underflow\n");
        return;
    }

    temp=r;
    printf("Deleted element is: %d\n",temp->info);

    r=r->prev;

    if(r==NULL)
        f=NULL;
    else
        r->next=NULL;

    free(temp);
}

void displayList(){
    NODE* ptr=f;

    if(ptr==NULL){
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements are:\n");

    while(ptr->next!=NULL){
        printf("%d -> ",ptr->info);
        ptr=ptr->next;
    }

    printf("%d\n",ptr->info);
}

int main(){

    int sel1,sel2;

    do{

        printf("\n--------Menu--------\n");
        printf("1. Deque using Array\n");
        printf("2. Deque using Linked List\n");
        printf("0. Exit\n");

        printf("\n--Enter your choice--\n");
        scanf("%d",&sel1);

        switch(sel1){

            case 1:

                do{

                    printf("\n--------Submenu--------\n");
                    printf("1. Insert Front\n");
                    printf("2. Insert Rear\n");
                    printf("3. Delete Front\n");
                    printf("4. Delete Rear\n");
                    printf("5. Display\n");
                    printf("0. Exit\n");

                    printf("\n--Enter your choice--\n");
                    scanf("%d",&sel2);

                    switch(sel2){

                        case 1:
                            insertFrontArray();
                            break;

                        case 2:
                            insertRearArray();
                            break;

                        case 3:
                            deleteFrontArray();
                            break;

                        case 4:
                            deleteRearArray();
                            break;

                        case 5:
                            displayArray();
                            break;
                    }

                }while(sel2!=0);

                break;

            case 2:

                do{

                    printf("\n--------Submenu--------\n");
                    printf("1. Insert Front\n");
                    printf("2. Insert Rear\n");
                    printf("3. Delete Front\n");
                    printf("4. Delete Rear\n");
                    printf("5. Display\n");
                    printf("0. Exit\n");

                    printf("\n--Enter your choice--\n");
                    scanf("%d",&sel2);

                    switch(sel2){

                        case 1:
                            insertFrontList();
                            break;

                        case 2:
                            insertRearList();
                            break;

                        case 3:
                            deleteFrontList();
                            break;

                        case 4:
                            deleteRearList();
                            break;

                        case 5:
                            displayList();
                            break;
                    }

                }while(sel2!=0);

                break;
        }

    }while(sel1!=0);

    return 0;
}