#include <stdio.h>

typedef struct stack{
  int top1;
  int top2;
  int stack[10];
}stack;

stack s;

void traverse(){
  for(int i = 0; i < 10; i++){
    printf("%d  ", s.stack[i]);
  }
}

stack initStack(){
  stack s;
  s.top1 = -1;
  s.top2 = 10;
  for(int i = 0; i < 10; i++){
    s.stack[i] = 0;
  }
  return s;
}

void insert1(){
  if(s.top1+1 == s.top2 || s.top1 >= 10){
    printf("Collision detected\n");
    return;
  }
  printf("Enter the value: ");
  scanf("%d",&s.stack[++s.top1]);
}
void insert2(){
  if(s.top1 == s.top2-1 || s.top2 <= 0){
    printf("Collision detected\n");
    return;
  }
  printf("Enter the value: ");
  scanf("%d",&s.stack[--s.top2]);
}

void remove1(){
  if(s.top1 < 0){
    printf("Stack underflow\n");
    return;
  }
  s.stack[s.top1--] = 0;
}

void remove2(){
  if(s.top2 > 9){
    printf("Stack underflow\n");
    return;
  }
  s.stack[s.top2++] = 0;
}

int main(void){
  s = initStack();
  traverse(s.stack);
  int sel;
  do{
    printf("\n--------Menu--------\n");
    printf("\n1. Insert into first stack");
    printf("\n2. Insert into second stack");
    printf("\n3. Remove from first stack");
    printf("\n4. Remove from second stack");
    printf("\n0. Exit");
    printf("\n--Enter the choice--\n");
    scanf("%d", &sel);
    switch(sel){
      case 1: insert1(); traverse(); break;
      case 2: insert2(); traverse(); break;
      case 3: remove1(); traverse(); break;
      case 4: remove2(); traverse(); break;
      case 0: break;
      default: printf("Enter coorect choice\n");
    }
  }while(sel != 0);
}