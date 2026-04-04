// Search and sort in singly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

NODE *head = NULL;

void traverse()
{
    NODE *ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d -> ", ptr->info);
        ptr = ptr->next;
    }
    printf("%d", ptr->info);
}

NODE *createNode(int info)
{
    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->info = info;
    n->next = NULL;
    return n;
}

void createLinkedList(int length)
{
    head = NULL;
    int info;
    NODE *tail;
    for (int i = 0; i < length; i++)
    {
        printf("Enter the info: ");
        scanf("%d", &info);
        NODE *n = createNode(info);
        if (head == NULL)
        {
        head = n;
        }
        else
        {
        tail->next = n;
        }
        tail = n;
    }
    traverse();
}

NODE* search(){
    int var, flag;
    NODE* ptr;
    printf("Enter the number to search: ");
    scanf("%d",&var);
    for(ptr = head; ptr != NULL; ptr = ptr->next){
        if(ptr->info == var){
            break;
        }
    }
    return ptr;
}

void sort(){
    NODE* newHead = head;
    head = newHead->next;
    newHead->next = NULL;
    NODE* ptr = head;
    for(; ptr != NULL; ptr = head){
        for(NODE* newPtr = newHead; newPtr != NULL; newPtr = newPtr->next){
            if(newPtr->next == NULL){
                if(ptr->info <= newPtr->info){
                    head = ptr->next;
                    ptr->next = newPtr;
                    newHead = ptr;
                    break;
                }else{
                    head = ptr->next;
                    newPtr->next = ptr;
                    ptr->next = NULL;
                    break;
                }
            }
            if(ptr->info <= newPtr->info){
                head = ptr->next;
                ptr->next = newPtr;
                newHead = ptr;
                break;
            }
            if(ptr->info <= newPtr->next->info){
                head = ptr->next;
                ptr->next = newPtr->next;
                newPtr->next = ptr;
                break;
            }
        }
    }
    head = newHead;
    traverse();
}

int main(void){
    int len, sel;
    printf("Enter the length of linked list: ");
    scanf("%d",&len);
    createLinkedList(len);
    do{
        printf("\n--------Menu--------\n");
        printf("1. Search\n");
        printf("2. Sort\n");
        printf("0. Exit\n");
        printf("\n--Enter your choice--\n");
        scanf("%d",&sel);
        switch(sel){
            case 1: NODE* ptr = search(); ptr != NULL ? printf("Info = %d\n", ptr->info) : printf("Number not found\n"); break;
            case 2: sort(); break;
            case 0: break;
            default: printf("Enter correct choice\n");
        }
    }while(sel != 0);
}