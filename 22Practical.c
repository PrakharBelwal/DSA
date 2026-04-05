#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node{
    int info;
    struct node* next;
}NODE;

int stack[MAX];
int top = -1;

void pushArray(){
    int x;

    if(top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter the element to push: ");
    scanf("%d",&x);

    top++;
    stack[top] = x;
}

void popArray(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted element is: %d\n",stack[top]);
    top--;
}

void displayArray(){
    int i;

    if(top == -1){
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");

    for(i=0;i<=top;i++){
        printf("%d",stack[i]);
        if(i<top)
            printf(", ");
    }
    printf("\n");
}

NODE* head = NULL;

void pushList(){
    NODE* temp = (NODE*)malloc(sizeof(NODE));

    printf("Enter the element to push: ");
    scanf("%d",&temp->info);

    temp->next = head;
    head = temp;
}

void popList(){
    NODE* temp;

    if(head == NULL){
        printf("Stack Underflow\n");
        return;
    }

    temp = head;
    printf("Deleted element is: %d\n",temp->info);

    head = head->next;
    free(temp);
}

void displayList(){
    NODE* ptr = head;

    if(ptr == NULL){
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");

    while(ptr->next != NULL){
        printf("%d -> ",ptr->info);
        ptr = ptr->next;
    }
    printf("%d\n",ptr->info);
}

int main(){

    int sel1,sel2;

    do{

        printf("\n--------Menu--------\n");
        printf("1. Stack using Array\n");
        printf("2. Stack using Linked List\n");
        printf("0. Exit\n");

        printf("\n--Enter your choice--\n");
        scanf("%d",&sel1);

        switch(sel1){

            case 1:

                do{

                    printf("\n--------Submenu--------\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Display\n");
                    printf("0. Exit\n");

                    printf("\n--Enter your choice--\n");
                    scanf("%d",&sel2);

                    switch(sel2){

                        case 1:
                            pushArray();
                            break;

                        case 2:
                            popArray();
                            break;

                        case 3:
                            displayArray();
                            break;
                    }

                }while(sel2 != 0);

                break;

            case 2:

                do{

                    printf("\n--------Submenu--------\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Display\n");
                    printf("0. Exit\n");

                    printf("\n--Enter your choice--\n");
                    scanf("%d",&sel2);

                    switch(sel2){

                        case 1:
                            pushList();
                            break;

                        case 2:
                            popList();
                            break;

                        case 3:
                            displayList();
                            break;
                    }

                }while(sel2 != 0);

                break;
        }

    }while(sel1 != 0);

    return 0;
}