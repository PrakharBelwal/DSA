#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node{
    int info;
    struct node* next;
}NODE;

NODE* top = NULL;

void push(int x){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->info = x;
    temp->next = top;
    top = temp;
}

int pop(){
    NODE* temp;
    int val;

    if(top == NULL){
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    val = temp->info;
    top = top->next;
    free(temp);

    return val;
}

int evaluatePostfix(char exp[]){
    int i,a,b,res;
    char ch;

    for(i=0;exp[i]!='\0';i++){

        ch = exp[i];

        if(isdigit(ch))
            push(ch-'0');

        else{

            b = pop();
            a = pop();

            switch(ch){
                case '+': res = a+b; break;
                case '-': res = a-b; break;
                case '*': res = a*b; break;
                case '/': res = a/b; break;
            }

            push(res);
        }
    }

    return pop();
}

int evaluatePrefix(char exp[]){
    int i,a,b,res;
    char ch;

    for(i=strlen(exp)-1;i>=0;i--){

        ch = exp[i];

        if(isdigit(ch))
            push(ch-'0');

        else{

            a = pop();
            b = pop();

            switch(ch){
                case '+': res = a+b; break;
                case '-': res = a-b; break;
                case '*': res = a*b; break;
                case '/': res = a/b; break;
            }

            push(res);
        }
    }

    return pop();
}

int main(){

    int choice,result;
    char exp[100];

    do{

        printf("\n--------Menu--------\n");
        printf("1. Evaluate Postfix Expression\n");
        printf("2. Evaluate Prefix Expression\n");
        printf("0. Exit\n");

        printf("\n--Enter your choice--\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:

                printf("Enter postfix expression: ");
                scanf("%s",exp);

                result = evaluatePostfix(exp);

                printf("Result: %d\n",result);
                break;

            case 2:

                printf("Enter prefix expression: ");
                scanf("%s",exp);

                result = evaluatePrefix(exp);

                printf("Result: %d\n",result);
                break;
        }

    }while(choice!=0);

    return 0;
}