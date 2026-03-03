/* WAP to impement following operation on one dimensional array:
(1) Insertion in sorted and unsorted array
(2) Deletion from sorted and unsorted arrays
(3) Traversal
(4) Reverse */

#include <stdio.h>

int insSort(int arr[], int size)
{
  int ele, pos = size;
  printf("Enter the element to be inserted: ");
  scanf("%d", &ele);
  for (int i = 0; i < size; i++)
  {
    if (ele < arr[i])
    {
      pos = i;
      break;
    }
  }
  for (int i = size; i > pos; i--)
  {
    arr[i] = arr[i - 1];
  }
  arr[pos] = ele;
  return ++size;
}

int insUnsort(int arr[], int size){
  int ele, pos;
  printf("Enter the position to insert element into:");
  scanf("%d",&pos);
  pos--;
  printf("Enter the element to insert: ");
  scanf("%d",&ele);
  for(int i = size; i > pos; i--){
    arr[i] = arr[i-1];
  }
  arr[pos] = ele;
  return ++size;
}

int delSort(int arr[], int size){
  int ele, pos = size;
  printf("Enter the element to delete: ");
  scanf("%d", &ele);
  for(int i = 0; i < size; i++){
    if(ele == arr[i]){
      pos = i;
      break;
    }
  }
  for(int i = pos; i < size; i++){
    arr[i] = arr[i+1];
  }
  return --size;
}

int delUnsort(int arr[], int size){
  int pos = size;
  printf("Enter the posiion of element to delete: ");
  scanf("%d",&pos);
  pos--;
  for(int i = pos; i < size; i++){
    arr[i] = arr[i+1];
  }
  return --size;
}

void traverse(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
}

void reverse(int arr[], int size){
  int temp;
  for(int i = 0; i < size/2; i++){
    temp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = temp;
  }
}

int main(void)
{
  int arr[100], size, sel;
  printf("enter the size of array: ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }
  do
  {
    printf("\n--------Menu--------\n");
    printf("1. Insert in sorted array\n");
    printf("2. Inserte in unsorted array\n");
    printf("3. Delete in sorted array\n");
    printf("4. Delete in unsorted array\n");
    printf("5. Traverse\n");
    printf("6. Reverse\n");
    printf("0. Exit\n");
    printf("----Enter The Choice----\n");
    scanf("%d", &sel);
    switch (sel)
    {
    case 1:
      size = insSort(arr, size);
      break;
    case 2:
      size = insUnsort(arr, size);
      break;
    case 3:
      size = delSort(arr, size);
      break;
    case 4:
      size = delUnsort(arr, size);
      break;
    case 5:
      traverse(arr, size);
      break;
    case 6:
      reverse(arr, size);
      break;
    case 0:
      return 0;
    default:
      printf("Enter a correct choice");
    }
  } while (sel != 0);
}