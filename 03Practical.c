/* WAP to perform sorting in array(Menu Driven):
> bubble sort
> selection sort
> insertion sort
> merge sort
> merging two sorted array */

#include <stdio.h>

void traverse(int arr[], int size){
  for(int i = 0; i < size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void bubbleSort(int arr[], int size){
  for(int i = 0; i < size-1; i++){
    for(int j = 0; j < size-i-1; j++){
      if(arr[j] > arr[j+1]){
        arr[j] = arr[j]^arr[j+1];
        arr[j+1] = arr[j]^arr[j+1];
        arr[j] = arr[j]^arr[j+1];
      }
    traverse(arr,size);
    }
  printf("\n");
  traverse(arr,size);
  printf("\n");
  }
}

void selectionSort(int arr[], int size){
  int min, temp = 0;
  for(int i = 0; i <  size; i++){
    min = i;
    for(int j = i; j < size; j++){
      if(arr[j] < arr[min]){
	min = j;
      }
    printf("min -> %d \n",arr[min]);
    }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
    traverse(arr, size);
    printf("\n");
  }
}

void insertionSort (int arr[], int size){
  for(int i = 1; i < size; i++){
    int key = arr[i];
    int j = i-1;
    while(j >= 0 && key < arr[j]){
      arr[j+1] = arr[j];
      j--;
    traverse(arr,size);
    }
    arr[j+1] = key;
    printf("\n");
    traverse(arr,size);
    printf("\n");
  }
}

void mergeSort(int arr[], int size){
}

int main(void){
  int size, arr[30], sel;
  do{
    printf("\nEnter the the size of array: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
      scanf("%d", &arr[i]);
    }
    printf("\n--------MENU--------\n");
    printf("1. Bubble sort\n");
    printf("2. Selection sort\n");
    printf("3. Insertion sort\n");
    printf("4. Merge sort\n");
    printf("5. Merge two sorted arrays\n");
    printf("0. Exit\n");
    printf("--Enter your choice--\n");
    scanf("%d",&sel);
    switch(sel){
      case 1:
        bubbleSort(arr, size);
        break;
      case 2:
        selectionSort(arr, size);
        break;
      case 3:
        insertionSort(arr, size);
        break;
      case 4:
        // mergeSort(arr, size);
        // traverse(arr, size);
        break;
      case 5:
        // mergeArr(arr, size);
        // traverse(arr, size);
        break;
      case 0:
        return 0;
      default:
      printf("Enter a valid choice\n");
    }
  }while(sel != 0);
}
