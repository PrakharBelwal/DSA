// WAP to insert node in linked list in beg, mid, end in unsorted and sorted linked list

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

void insertBeg()
{
  int info;
  NODE* ptr = head;
  printf("Enter the info: ");
  scanf("%d", &info);
  NODE* n = createNode(info);
  n->next = ptr;
  head = n;
  traverse();
}

void unsortInsertMid()
{
  int pos, info;
  NODE* ptr = head, *next;
  printf("Enter the position where to insert new node: ");
  scanf("%d", &pos);
  pos -= 2;
  printf("Enter the info: ");
  scanf("%d", &info);
  NODE* n = createNode(info);
  for(int i = 0; i < pos; i++){
    if(ptr->next == NULL){
      printf("Position out of bound\n");
      return;
    }
    ptr = ptr->next;
  }
  next = ptr->next;
  ptr->next = n;
  n->next = next;
  traverse();
}

void sortInsertMid()
{
  int info;
  NODE *ptr, *next;
  printf("Enter the info: ");
  scanf("%d",&info);
  NODE* n = createNode(info);
  for(ptr = head; ptr->next->info < info; ptr = ptr->next);
  next = ptr->next;
  ptr->next = n;
  n->next = next;
  traverse();
}

void insertEnd()
{
  int info;
  NODE* ptr = head;
  printf("Enter the info: ");
  scanf("%d", &info);
  NODE* n = createNode(info);
  while(ptr->next != NULL){
    ptr = ptr->next;
  }
  ptr->next = n;
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