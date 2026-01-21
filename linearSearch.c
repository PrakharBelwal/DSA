#include <stdio.h>

int main(void)
{
    int ele, pos, flag = 0, A[10], i, n;

    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("Enter the element of array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter the element to find\n");
    scanf("%d", &ele);
    for (i = 0; i < n; i++)
    {
        if (ele == A[i])
        {
            pos = i + 1;
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Element at pos = %d\n", pos);
    }
    else
    {
        printf("Element not found\n");
    }
}