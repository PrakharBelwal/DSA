// Deletion in singly linked list: beginning, end, middle

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

void deleteBeg(){
    NODE* ptr = head;
    head = head->next;
    free(ptr);
    traverse();
}

void deleteEnd(){
    NODE* ptr = head;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    traverse();
}

void unsortDeleteMid(){
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d",&pos);
    NODE* ptr = head;
    for(int i = 0; i < pos-1; i++){
        ptr = ptr->next;
    }
    NODE* next = ptr->next->next;
    free(ptr->next);
    ptr->next = next;
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
            // sortDeleteMid();
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
            // unsortDeleteMid();
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