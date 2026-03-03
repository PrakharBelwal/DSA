/* WAP to perform following string related function (user defined) on an array
> finding string length
> concatenation of two strings
> comparing two string
> copy one string to another */

#include <stdio.h>

int length(){
  char str[100];
  printf("Enter the string: ");
  scanf(" %[^\n]s", str);
  int i;
  for(i = 0; str[i] != '\0'; i++);
  return i;
}

void concate(){
  char str1[100], str2[100];
  printf("Enter the first string: ");
  scanf(" %[^\n]s",str1);
  printf("Enter the second string: ");
  scanf(" %[^\n]s",str2);
  int i, j;
  for(i = 0; str1[i] != '\0'; i++);
  for(j = 0; str2[j] != '\0'; j++){
    str1[i+j] = str2[j];
  }
  str1[i+j] = '\0';
  printf("%s",str1);
}

void compare(){
  int cmp;
  char str1[100], str2[100];
  printf("Enter the first string: ");
  scanf(" %[^\n]s",str1);
  printf("Enter the second string: ");
  scanf(" %[^\n]s",str2);
  int len1, len2;
  for(len1 = 0; str1[len1] != '\0'; len1++);
  for(len2 = 0; str2[len2] != '\0'; len2++);
  if(len1 > len2){
    printf("String 1 is larger");
    return;
  }else if(len2 > len1){
    printf("String 2 is larger");
    return;
  }else{
    for(int i = 0; i < len1; i++){
      if(str1[i] > str2[i]){
        printf("String 1 is greater");
        return;
      }else if(str2[i] > str1[i]){
        printf("String 2 is greater");
        return;
      }else{
        printf("String 1 and 2 are equal");
        return;
      }
    }
  }
}

void copy(char copy[]){
  char str[100];
  printf("Enter the string: ");
  scanf(" %[^\n]s", str);
  for(int i = 0; str[i] != '\0'; i++){
    copy[i] = str[i];
  }
}

int main(void){
  int sel;
  do{
    printf("\n--------Menu--------\n");
    printf("1. Length of string\n");
    printf("2. Concatenate two string\n");
    printf("3. Compare two string\n");
    printf("4. Copy two string\n");
    printf("0. Exit\n");
    printf("--Enter your choice--\n");
    scanf("%d", &sel);
    switch(sel){
      case 1:
        printf("%d",length());
        break;
      case 2:
        concate();
        break;
      case 3:
        compare();
        break;
      case 4:
        char strCp[100];
        copy(strCp);
        printf("%s",strCp);
        break;
      case 0:
        return 0;
      default:
        printf("Enter correct choice");
    }
  }while(sel != 0);
}