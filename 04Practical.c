#include <stdio.h>

void bubbleSort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        arr[j] = arr[j] ^ arr[j + 1];
        arr[j + 1] = arr[j] ^ arr[j + 1];
        arr[j] = arr[j] ^ arr[j + 1];
      }
    }
  }
}

void linearSearch(int arr[], int size, int target)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == target)
    {
      printf("%d found at %d", arr[i], i + 1);
      break;
    }
    else if (i == size - 1)
    {
      printf("Target not found");
    }
  }
}

void binarySearch(int arr[], int size, int target){
  bubbleSort(arr, size);
  int low = 0, high = size-1;
  int mid = (low+high)/2;
  while(low<=high){
    mid = (low+high)/2;
    if(arr[mid] == target){
      printf("\n%d found at %d", arr[mid], mid + 1);
      return;
    }
    else if(arr[mid] > target){
      high = mid-1;
    }
    else if(arr[mid] < target){
      low = mid+1;
    }
  }
  printf("\nSomething broke: %d -> mid, %d -> low, %d -> high, %d -> arr[mid]", mid, low, high, arr[mid]);
  return;
}

int main(void)
{
  int arr[100], size, sel, target;

  do
  {
    printf("\nenter the size of array: ");
    while (scanf("%d", &size) != 1)
    {
      printf("Invalid input\n");
      while (getchar() != '\n');
      printf("\nEnter the size of array: ");
    }
    for (int i = 0; i < size; i++)
    {
      scanf("%d", &arr[i]);
    }
    printf("\n--------Menu--------\n");
    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\n0. Exit");
    printf("\n--Enter your choice--\n");
    scanf("%d", &sel);
    switch (sel)
    {
    case 1:
      printf("Enter the number to find: ");
      scanf(" %d", &target);
      linearSearch(arr, size, target);
      break;
    case 2:
      printf("Enter the number to find: ");
      scanf(" %d", &target);
      binarySearch(arr, size, target);
      break;
    }
  } while (sel != 0);
}