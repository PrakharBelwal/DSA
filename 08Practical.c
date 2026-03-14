/* 
  WAP to create, traverse and reverse a single linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int info;
  struct node* next;
} NODE;

NODE* head = NULL;

NODE *createNode(int info){
  NODE* n = (NODE*)malloc(sizeof(NODE));
  n->info = info;
  n->next = NULL;
  return n;
}

void createLinkedList(int length){
  int info;
  NODE* tail;
  for(int i = 0; i < length; i++){
    printf("Enter the info: ");
    scanf("%d", &info);
    NODE* n = createNode(info);
    if(head == NULL){
      head = n;
      
    }else{
      tail->next = n;
    }
    tail = n;
  }
}

void traverse(){
  NODE* ptr = head;
  while(ptr->next != NULL){
    printf("%d -> ", ptr->info);
    ptr = ptr->next;
  }
  printf("%d",ptr->info);
}

void reverse(){
  NODE *prev, *next;
  for(NODE* ptr = head; ptr != NULL; ptr = next){
    if(ptr->next == NULL){
      ptr->next = prev;
      head = ptr;
      return;
    }
    next = ptr->next;
    if(ptr == head){
      prev = ptr;
      ptr->next = NULL;
      continue;
    }
    ptr->next = prev;
    prev = ptr;
  }
}

int main(void){
  int choice, length;
  printf("Enter the length of linked list: ");
  scanf("%d", &length);
  createLinkedList(length);
  do{
    printf("\n--------Menu--------\n");
    printf("\n1. Traverse Linked List");
    printf("\n2. Reverse Linked List");
    printf("\n0. Exit");
    printf("\n--Enter your choice--\n");
    scanf("%d", &choice);
    switch(choice){
      case 1: traverse(); break;
      case 2: reverse(); break;
      case 0: break;
      default: printf("Enter correct choice\n");
    }
  }while(choice != 0);
}