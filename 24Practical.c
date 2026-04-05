#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char x){
    stack[++top]=x;
}

char pop(){
    return stack[top--];
}

int precedence(char c){
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[],char postfix[]){
    int i=0,j=0;
    char ch;

    while(infix[i]!='\0'){

        ch=infix[i];

        if(isalnum(ch))
            postfix[j++]=ch;

        else if(ch=='(')
            push(ch);

        else if(ch==')'){
            while(stack[top]!='(')
                postfix[j++]=pop();
            pop();
        }

        else{
            while(top!=-1 && precedence(stack[top])>=precedence(ch))
                postfix[j++]=pop();
            push(ch);
        }

        i++;
    }

    while(top!=-1)
        postfix[j++]=pop();

    postfix[j]='\0';
}

void reverse(char exp[]){
    int i,j;
    char temp;

    j=strlen(exp)-1;

    for(i=0;i<j;i++,j--){
        temp=exp[i];
        exp[i]=exp[j];
        exp[j]=temp;
    }
}

void infixToPrefix(char infix[],char prefix[]){
    char temp[MAX];

    strcpy(temp,infix);
    reverse(temp);

    for(int i=0;temp[i];i++){
        if(temp[i]=='(')
            temp[i]=')';
        else if(temp[i]==')')
            temp[i]='(';
    }

    char postfix[MAX];
    infixToPostfix(temp,postfix);

    reverse(postfix);
    strcpy(prefix,postfix);
}

int main(){

    int choice;
    char infix[MAX],postfix[MAX],prefix[MAX];

    do{

        printf("\n--------Menu--------\n");
        printf("1. Convert Infix to Postfix\n");
        printf("2. Convert Infix to Prefix\n");
        printf("0. Exit\n");

        printf("\n--Enter your choice--\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:

                printf("Enter infix expression: ");
                scanf("%s",infix);

                top=-1;
                infixToPostfix(infix,postfix);

                printf("Postfix Expression: %s\n",postfix);
                break;

            case 2:

                printf("Enter infix expression: ");
                scanf("%s",infix);

                top=-1;
                infixToPrefix(infix,prefix);

                printf("Prefix Expression: %s\n",prefix);
                break;
        }

    }while(choice!=0);

    return 0;
}