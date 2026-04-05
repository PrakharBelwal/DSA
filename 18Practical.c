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
    NODE *head = NULL, *ptr = NULL, *temp;
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

void traverse(NODE* head){
    NODE* ptr = head;

    while(ptr->next != NULL){
        printf("%d -> ",ptr->info);
        ptr = ptr->next;
    }
    printf("%d\n",ptr->info);
}

NODE* mergeSorted(NODE* a, NODE* b){
    NODE *result = NULL, *tail;

    if(a == NULL) return b;
    if(b == NULL) return a;

    if(a->info <= b->info){
        result = a;
        a = a->next;
    }
    else{
        result = b;
        b = b->next;
    }

    tail = result;

    while(a != NULL && b != NULL){
        if(a->info <= b->info){
            tail->next = a;
            a = a->next;
        }
        else{
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if(a != NULL)
        tail->next = a;
    else
        tail->next = b;

    return result;
}

int main(){
    NODE *l1 = NULL, *l2 = NULL, *merged;
    int n1,n2;

    printf("Enter the number of elements in first sorted linked list: ");
    scanf("%d",&n1);

    l1 = createLinkedList(n1);

    printf("Enter the number of elements in second sorted linked list: ");
    scanf("%d",&n2);

    l2 = createLinkedList(n2);

    merged = mergeSorted(l1,l2);

    printf("Merged Linked List:\n");
    traverse(merged);

    return 0;
}