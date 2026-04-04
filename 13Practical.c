// insert into doubly linked list in beg, mid, end

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int info;
  struct node* next;
  struct node* prev;
}NODE;

NODE* head = NULL;

void traverse(){
  NODE* ptr = head;
  for(; ptr->next != NULL; ptr = ptr->next){
    printf("%d -> ", ptr->info);
  }
  printf("%d", ptr->info);
}

NODE* createNode(){
  NODE* n = malloc(sizeof(NODE));
  printf("Enter the info: ");
  scanf("%d",&n->info);
  n->next = NULL;
  n->prev = NULL;
  return n;
}

void createLinkedList(int len){
  head = NULL;
  NODE* ptr;
  for(int i = 0; i < len; i++){
    NODE* n = createNode();
    if(head != NULL){
      ptr->next = n;
      n->prev = ptr;
      ptr = n;
    }else{
      head = n;
      ptr = n;
    }
  }
  traverse();
}

void insertBeg(){
    NODE* n = createNode();
    n->next = head;
    head = n;
    traverse();
}

void insertEnd(){
    NODE* ptr;
    for(ptr = head; ptr->next != NULL; ptr = ptr->next);
    NODE* n = createNode();
    ptr->next = n;
    n->prev = ptr;
    traverse();
}

void sortInsertMid(){
    NODE* n = createNode();
    NODE* ptr;
    for(ptr = head; ptr->next != NULL; ptr = ptr->next){
        if(n->info <= ptr->next->info){
            n->next = ptr->next;
            ptr->next->prev = n;
            n->prev = ptr;
            ptr->next = n;
            break;
        }
    }
    traverse();
}

void unsortInsertMid(){
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    NODE *ptr = head, *n = createNode();
    for(int i = 0; i < pos-2; i++){
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next->prev = n;
    ptr->next = n;
    n->prev = ptr;
    traverse();
}

int main(void)
{
  int length, sel1, sel2;
  do
  {
    printf("\n--------Menu--------\n");
    printf("\n1. Sorted Linked List");
    printf("\n2. Unsorted Linked List");
    printf("\n0. Exit");
    printf("\n--Enter your choice--\n");
    scanf("%d", &sel1);
    switch (sel1)
    {
      case 1:
      {
        printf("Enter the length of the linked list: ");
        scanf("%d", &length);
        createLinkedList(length);
        do
        {
          printf("\n--------Submenu--------\n");
          printf("\n1. Insert in the beginning");
          printf("\n2. Insert in the middle");
          printf("\n3. Insert at the end");
          printf("\n0. Exit");
          printf("\n--Enter your choice--\n");
          scanf("%d", &sel2);
          switch (sel2)
          {
          case 1:
            insertBeg();
            break;
          case 2:
            sortInsertMid();
            break;
          case 3:
            insertEnd();
            break;
          case 0:
            break;
          default:
            printf("Enter correct choice\n");
          }
        } while (sel2 != 0);
        break;
      }
      case 2:
      {
        printf("Enter the length of the linked list: ");
        scanf("%d", &length);
        createLinkedList(length);
        do
        {
          printf("\n--------Submenu--------\n");
          printf("\n1. Insert in the beginning");
          printf("\n2. Insert in the middle");
          printf("\n3. Insert at the end");
          printf("\n0. Exit");
          printf("\n--Enter your choice--\n");
          scanf("%d", &sel2);
          switch (sel2)
          {
          case 1:
            insertBeg();
            break;
          case 2:
            unsortInsertMid();
            break;
          case 3:
            insertEnd();
            break;
          case 0:
            break;
          default:
            printf("Enter correct choice\n");
          }
        } while (sel2 != 0);
        break;
      }
    }
  } while (sel1 != 0);
}