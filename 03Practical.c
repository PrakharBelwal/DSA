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
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
    traverse(arr,size);
  }
  printf("\n");
  traverse(arr,size);
  printf("\n");
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

void merge(int arr[], int low, int mid, int high){
  int i = low;
  int j = mid + 1;
  int k = 0;
  int temp[30];

  while(i <= mid && j <= high){
    if(arr[i] < arr[j]){
      temp[k] = arr[i];
      i++;
    }
    else{
      temp[k] = arr[j];
      j++;
    }
    k++;
  }

  while(i <= mid){
    temp[k] = arr[i];
    i++;
    k++;
  }

  while(j <= high){
    temp[k] = arr[j];
    j++;
    k++;
  }

  for(i = low, k = 0; i <= high; i++, k++){
    arr[i] = temp[k];
  }

  traverse(arr, high+1);
}

void mergeSort(int arr[], int low, int high){
  if(low < high){
    int mid = (low + high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);
  }
}

void mergeArr(int arr[], int size){
  int arr2[30], size2;
  int merged[60];

  printf("Enter size of second sorted array: ");
  scanf("%d",&size2);

  printf("Enter elements of second sorted array:\n");
  for(int i = 0; i < size2; i++){
    scanf("%d",&arr2[i]);
  }

  int i = 0, j = 0, k = 0;

  while(i < size && j < size2){
    if(arr[i] < arr2[j]){
      merged[k] = arr[i];
      i++;
    }
    else{
      merged[k] = arr2[j];
      j++;
    }
    k++;
  }

  while(i < size){
    merged[k] = arr[i];
    i++;
    k++;
  }

  while(j < size2){
    merged[k] = arr2[j];
    j++;
    k++;
  }

  printf("\nMerged Array:\n");
  traverse(merged, size+size2);
}

int main(void){
  int size, arr[30], sel;
  do{
    printf("\nEnter the the size of array: ");
    scanf("%d", &size);

    printf("Enter elements:\n");
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
        mergeSort(arr, 0, size-1);
        printf("\nSorted Array:\n");
        traverse(arr, size);
        break;

      case 5:
        mergeArr(arr, size);
        break;

      case 0:
        return 0;

      default:
        printf("Enter a valid choice\n");
    }

  }while(sel != 0);
}