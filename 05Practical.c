#include <stdio.h>

int main(void)
{
  int matrix[10][10], row, col, flag = 0, majority, zeroCount = 0, t_matrix[50][3], cur_row = 1;
  while (flag != 1)
  {

    printf("Enter the number of rows: ");
    scanf(" %d", &row);
    if(row > 10){
      printf("Number of rows must be less than 10\n");
      continue;
    }
    printf("Enter the number of cols: ");
    scanf(" %d", &col);
    if(col > 10){
      printf("Number of columns must be less than 10\n");
      continue;
    }
    majority = (row + col) / 2;

    for (int i = 0; i < row; i++)
    {
      printf("--\n");
      for (int j = 0; j < col; j++)
      {
        scanf("%d", &matrix[i][j]);
      }
      printf("--\n");
    }

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
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

  printf("Sparse Matrix\n");

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (matrix[i][j] != 0)
      {
        t_matrix[cur_row][0] = i+1;
        t_matrix[cur_row][1] = j+1;
        t_matrix[cur_row][2] = matrix[i][j];
        cur_row++;
      }
    }
  }

  t_matrix[0][0] = row;
  t_matrix[0][1] = col;
  t_matrix[0][2] = cur_row-1;

  for (int i = 0; i < cur_row; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d ", t_matrix[i][j]);
    }
    printf("\n");
  }
}
