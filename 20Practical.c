#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}NODE;

NODE* createNode(){
    NODE* n = (NODE*)malloc(sizeof(NODE));
    printf("Enter the info: ");
    scanf("%d",&n->info);
    n->next = NULL;
    return n;
}

NODE* createLinkedList(int n){
    NODE *head=NULL,*ptr=NULL,*temp;
    int i;

    for(i=0;i<n;i++){
        temp = createNode();

        if(head == NULL){
            head = temp;
            ptr = head;
        }
        else{
            ptr->next = temp;
            ptr = temp;
        }
    }

    return head;
}

NODE* append(NODE* head,int val){
    NODE *temp,*ptr;

    temp = (NODE*)malloc(sizeof(NODE));
    temp->info = val;
    temp->next = NULL;

    if(head == NULL)
        return temp;

    ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;

    return head;
}

void traverse(NODE* head){
    NODE* ptr = head;

    if(ptr == NULL){
        printf("List is empty\n");
        return;
    }

    while(ptr->next != NULL){
        printf("%d -> ",ptr->info);
        ptr = ptr->next;
    }
    printf("%d\n",ptr->info);
}

void splitList(NODE* head,NODE** odd,NODE** even){
    NODE* ptr = head;
    int pos = 1;

    while(ptr != NULL){
        if(pos % 2 != 0)
            *odd = append(*odd,ptr->info);
        else
            *even = append(*even,ptr->info);

        ptr = ptr->next;
        pos++;
    }
}

int main(){

    NODE *head=NULL,*odd=NULL,*even=NULL;
    int n;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d",&n);

    head = createLinkedList(n);

    splitList(head,&odd,&even);

    printf("Odd Position List:\n");
    traverse(odd);

    printf("Even Position List:\n");
    traverse(even);

    return 0;
}