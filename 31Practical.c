#include <stdio.h>

#define MAX 10

typedef struct stack{
    int top1;
    int top2;
    int arr[MAX];
}stack;

stack s;

void traverse(){
    printf("\nArray State:\n");
    for(int i=0;i<MAX;i++){
        if(s.arr[i]==-1)
            printf("-  ");
        else
            printf("%d  ",s.arr[i]);
    }
    printf("\n");
}

stack initStack(){
    stack s;
    s.top1=-1;
    s.top2=MAX;

    for(int i=0;i<MAX;i++)
        s.arr[i]=-1;

    return s;
}

void insert1(){

    if(s.top1+1==s.top2){
        printf("Collision detected\n");
        return;
    }

    int x;

    printf("Enter the value: ");
    scanf("%d",&x);

    s.arr[++s.top1]=x;
}

void insert2(){

    if(s.top1+1==s.top2){
        printf("Collision detected\n");
        return;
    }

    int x;

    printf("Enter the value: ");
    scanf("%d",&x);

    s.arr[--s.top2]=x;
}

void remove1(){

    if(s.top1<0){
        printf("Stack Underflow\n");
        return;
    }

    s.arr[s.top1--]=-1;
}

void remove2(){

    if(s.top2>=MAX){
        printf("Stack Underflow\n");
        return;
    }

    s.arr[s.top2++]=-1;
}

int main(){

    s=initStack();

    traverse();

    int sel;

    do{

        printf("\n--------Menu--------\n");
        printf("1. Insert into first stack\n");
        printf("2. Insert into second stack\n");
        printf("3. Remove from first stack\n");
        printf("4. Remove from second stack\n");
        printf("0. Exit\n");

        printf("\n--Enter your choice--\n");
        scanf("%d",&sel);

        switch(sel){

            case 1:
                insert1();
                traverse();
                break;

            case 2:
                insert2();
                traverse();
                break;

            case 3:
                remove1();
                traverse();
                break;

            case 4:
                remove2();
                traverse();
                break;

            case 0:
                break;

            default:
                printf("Enter correct choice\n");
        }

    }while(sel!=0);
}