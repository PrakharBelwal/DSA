// delete doubly linked list in beg, mid, end

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

void deleteBeg(){
    NODE* ptr = head;
    head = ptr->next;
    ptr->next->prev = NULL;
    free(ptr);
    traverse();
}

void deleteEnd(){
    NODE* ptr;
    for(ptr = head; ptr->next->next != NULL; ptr = ptr->next);
    free(ptr->next);
    ptr->next = NULL;
    traverse();
}

void sortDeleteMid(){
    int info;
    printf("Enter the number to delete: ");
    scanf("%d", &info);
    NODE* ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next){
        if(ptr->next->info == info){
            break;
        }
    }
    NODE* del = ptr->next;
    ptr->next->next->prev = ptr;
    ptr->next = ptr->next->next;
    free(del);
    traverse();
}

void unsortDeleteMid(){
    int pos;
    NODE* ptr = head;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    for(int i = 0; i < pos-2; i++){
        ptr = ptr->next;
    }
    NODE* del = ptr->next;
    ptr->next->next->prev = ptr;
    ptr->next = ptr->next->next;
    free(del);
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
          printf("\n1. Delete in the beginning");
          printf("\n2. Delete in the middle");
          printf("\n3. Delete at the end");
          printf("\n0. Exit");
          printf("\n--Enter your choice--\n");
          scanf("%d", &sel2);
          switch (sel2)
          {
          case 1:
            deleteBeg();
            break;
          case 2:
            sortDeleteMid();
            break;
          case 3:
            deleteEnd();
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
          printf("\n1. Delete in the beginning");
          printf("\n2. Delete in the middle");
          printf("\n3. Delete at the end");
          printf("\n0. Exit");
          printf("\n--Enter your choice--\n");
          scanf("%d", &sel2);
          switch (sel2)
          {
          case 1:
            deleteBeg();
            break;
          case 2:
            unsortDeleteMid();
            break;
          case 3:
            deleteEnd();
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
