// Create and traverse forward and backward in a doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int info;
  struct node* next;
  struct node* prev;
}NODE;

NODE* head = NULL;

NODE* createNode(){
  NODE* n = malloc(sizeof(NODE));
  printf("Enter the info: ");
  scanf("%d",&n->info);
  n->next = NULL;
  n->prev = NULL;
  return n;
}

void createLinkedList(int len){
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
}

void traverseForward(){
  NODE* ptr = head;
  for(; ptr->next != NULL; ptr = ptr->next){
    printf("%d -> ", ptr->info);
  }
  printf("%d", ptr->info);
}

void traverseBackward(){
  NODE* ptr = head;
  for(;ptr->next != NULL; ptr = ptr->next);
  printf("%d",ptr->info);
  for(ptr = ptr->prev ;ptr != NULL; ptr = ptr->prev){
    printf(" <- %d",ptr->info);
  }
}

int main(void){
  int len, sel;
  printf("Enter length of the linked list: ");
  scanf("%d",&len);
  createLinkedList(len);
  do{
    printf("\n--------Menu--------\n");
    printf("1. Traverse Forward\n");
    printf("2. Traverse Backward\n");
    printf("0. Exit");
    printf("\n--Enter your choice--\n");
    scanf("%d",&sel);
    switch(sel){
      case 1: traverseForward(); break;
      case 2: traverseBackward(); break;
      case 0: break;
      default: printf("Enter correct choice\n");
    }
  }while(sel != 0);
}