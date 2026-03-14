/*
  WAP to display the sparse matrix in the following way(Menu Driven)  :-
    Upper triangular matrix
    Lower triangular matrix
    Diagonal matrix
*/

#include <stdio.h>

void upper(int matrix[10][10], int row){
  for(int i = 0; i < row; i++){
    for(int k = i; k > 0; k--){
      printf("  ");
    }
    for (int j = i; j < row; j++){
      printf("%d ",matrix[i][j]);
    }
    printf("\n");
  }
}

void lower(int matrix[10][10], int row){
  for(int i = 0; row - i > 0; i++){
    for(int j = 0; j < i+1; j++){
      printf("%d ",matrix[i][j]);
    }
    printf("\n");
  }
}

void diagonal(int matrix[10][10], int row){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < i; j++){
      printf("  ");
    }
    printf("%d\n",matrix[i][i]);
  }
}

int main(void)
{
  int matrix[10][10], row, flag = 0, zeroCount = 0, t_matrix[50][3], cur_row = 1, sel;
  while (flag != 1)
  {

    printf("Enter the number of rows of square matrix: ");
    scanf(" %d", &row);
    if(row > 10){
      printf("Number of rows must be less than 10\n");
      continue;
    }

    for (int i = 0; i < row; i++)
    {
      printf("--\n");
      for (int j = 0; j < row; j++)
      {
        scanf("%d", &matrix[i][j]);
      }
      printf("--\n");
    }

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < row; j++)
      {
        if (matrix[i][j] == 0)
        {
          zeroCount++;
          if (zeroCount >= row)
          {
            flag = 1;
            break;
          }
        }
      }

      if (flag == 1)
      {
        break;
      }
    }

    if (flag == 0)
    {
      printf("Not a sparse\n");
    }
  }

  printf("Sparse Matrix\n");

  do{
    printf("\n--------Menu--------\n");
    printf("\n1. Upper Triangle");
    printf("\n2. Lower Triangle");
    printf("\n3. Diagonal");
    printf("\n0. Exit");
    printf("\n--Enter your choice--\n");
    scanf("%d",&sel);
    switch(sel){
    case 1: upper(matrix, row); break;
    case 2: lower(matrix, row); break;
    case 3: diagonal(matrix, row); break;
    case 0: break;
    default: printf("\nEnter correct choice\n");
    }
  }while(sel != 0);
}
