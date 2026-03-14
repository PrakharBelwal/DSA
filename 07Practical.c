/*
  WAP to perform following on sparse matrix:
    Transpose of sparse matrix
    Addition on two sparse matrix
    Multiplication on two sparse matrix
*/

#include <stdio.h>

void createMatrix(int matrix[10][10], int *row, int *col)
{
  int majority, zeroCount = 0, flag = 0;
  while (flag != 1)
  {

    printf("Enter the number of rows: ");
    scanf(" %d", row);
    if (*row > 10)
    {
      printf("Number of rows must be less than 10\n");
      continue;
    }
    printf("Enter the number of cols: ");
    scanf(" %d", col);
    if (*col > 10)
    {
      printf("Number of columns must be less than 10\n");
      continue;
    }
    majority = (*row + *col) / 2;

    for (int i = 0; i < *row; i++)
    {
      printf("--\n");
      for (int j = 0; j < *col; j++)
      {
        scanf("%d", &matrix[i][j]);
      }
      printf("--\n");
    }

    for (int i = 0; i < *row; i++)
    {
      for (int j = 0; j < *col; j++)
      {
        if (matrix[i][j] == 0)
        {
          zeroCount++;
          if (zeroCount >= majority)
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

  printf("Sparse Matrix\n\n");
}

void printMatrix(int matrix[10][10], int row, int col){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void transpose(){
  int matrix[10][10], transposed[10][10], r, c;
  createMatrix(matrix, &r, &c);
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      transposed[j][i] = matrix[i][j];
    }
  }
  printf("Transposed Matrix: \n");
  printMatrix(transposed, r, c);
  return;
}

void addition(){
  int matrix1[10][10], row1, col1;
  int matrix2[10][10], row2, col2;
  int sumMatrix[10][10], sumRow, sumCol;
  createMatrix(matrix1, &row1, &col1);
  createMatrix(matrix2, &row2, &col2);
  if(row1 != row2 || col1 != col2){
    printf("Entered matrix are not of same dimensions");
    return;
  }
  sumRow = row1;
  sumCol = col1;
  for(int i = 0; i < sumRow; i++){
    for(int j = 0; j < sumCol; j++){
      sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  printf("Result matrix:\n");
  printMatrix(sumMatrix, sumRow, sumCol);
}

void multiplication(){
  int matrix1[10][10], row1, col1;
  int matrix2[10][10], row2, col2;
  int productMatrix[10][10], productRow, productCol;
  createMatrix(matrix1, &row1, &col1);
  createMatrix(matrix2, &row2, &col2);
  if(col1 != row2){
    printf("Number of rows of first matrix must be equal to number of columns of second matrix");
    return;
  }
  productRow = row1;
  productCol = col2;
  for(int i  = 0; i < productRow; i++){
    for(int j = 0; j < productCol; j++){
      productMatrix[i][j] = 0;
      for(int k = 0; k < col1; k++){
        productMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  printf("Result matrix:\n");
  printMatrix(productMatrix, productRow, productCol);
}

int main(void)
{
  int choice;
  do
  {
    printf("\n-------Menu--------\n");
    printf("\n1. Transposition");
    printf("\n2. Addition");
    printf("\n3. Multipication");
    printf("\n0. Exit");
    printf("\n--Enter your choice--\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1: transpose(); break;
    case 2: addition(); break;
    case 3: multiplication(); break;
    case 0:
      break;
    default:
      printf("Enter correct choice\n");
    }
  } while (choice != 0);
}