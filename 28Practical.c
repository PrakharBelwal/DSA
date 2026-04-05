#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node{
    int info;
    int priority;
    struct node* next;
}NODE;

int pq[MAX];
int pr[MAX];
int size=0;

void insertArray(){
    int x,p,i;

    if(size==MAX){
        printf("Priority Queue Overflow\n");
        return;
    }

    printf("Enter the element: ");
    scanf("%d",&x);

    printf("Enter the priority: ");
    scanf("%d",&p);

    i=size-1;

    while(i>=0 && pr[i]>p){
        pq[i+1]=pq[i];
        pr[i+1]=pr[i];
        i--;
    }

    pq[i+1]=x;
    pr[i+1]=p;
    size++;
}

void deleteArray(){

    if(size==0){
        printf("Priority Queue Underflow\n");
        return;
    }

    printf("Deleted element is: %d\n",pq[0]);

    for(int i=0;i<size-1;i++){
        pq[i]=pq[i+1];
        pr[i]=pr[i+1];
    }

    size--;
}

void displayArray(){

    if(size==0){
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue elements are:\n");

    for(int i=0;i<size;i++){
        printf("%d",pq[i]);
        if(i<size-1)
            printf(", ");
    }

    printf("\n");
}

NODE* head=NULL;

void insertList(){
    NODE *temp,*ptr,*prev;
    int x,p;

    temp=(NODE*)malloc(sizeof(NODE));

    printf("Enter the element: ");
    scanf("%d",&x);

    printf("Enter the priority: ");
    scanf("%d",&p);

    temp->info=x;
    temp->priority=p;
    temp->next=NULL;

    if(head==NULL || p<head->priority){
        temp->next=head;
        head=temp;
        return;
    }

    ptr=head;

    while(ptr!=NULL && ptr->priority<=p){
        prev=ptr;
        ptr=ptr->next;
    }

    prev->next=temp;
    temp->next=ptr;
}

void deleteList(){
    NODE* temp;

    if(head==NULL){
        printf("Priority Queue Underflow\n");
        return;
    }

    temp=head;
    printf("Deleted element is: %d\n",temp->info);

    head=head->next;
    free(temp);
}

void displayList(){
    NODE* ptr=head;

    if(ptr==NULL){
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue elements are:\n");

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
        printf("1. Priority Queue using Array\n");
        printf("2. Priority Queue using Linked List\n");
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