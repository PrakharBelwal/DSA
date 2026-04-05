#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coeff;
    int exp;
    struct node* next;
}NODE;

NODE* createNode(){
    NODE* n = (NODE*)malloc(sizeof(NODE));
    printf("Enter coefficient: ");
    scanf("%d",&n->coeff);
    printf("Enter exponent: ");
    scanf("%d",&n->exp);
    n->next = NULL;
    return n;
}

NODE* insertTerm(NODE* head, int c, int e){
    NODE *ptr = head, *temp, *prev = NULL;

    temp = (NODE*)malloc(sizeof(NODE));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;

    if(head == NULL || e > head->exp){
        temp->next = head;
        head = temp;
        return head;
    }

    while(ptr != NULL && ptr->exp > e){
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr != NULL && ptr->exp == e){
        ptr->coeff = ptr->coeff + c;
        free(temp);
    }
    else{
        temp->next = ptr;
        prev->next = temp;
    }

    return head;
}

NODE* createPolynomial(int n){
    NODE* head = NULL;
    NODE* temp;
    int i,c,e;

    for(i=0;i<n;i++){
        printf("Enter coefficient: ");
        scanf("%d",&c);
        printf("Enter exponent: ");
        scanf("%d",&e);

        head = insertTerm(head,c,e);
    }

    return head;
}

void traverse(NODE* head){
    NODE* ptr = head;

    if(ptr == NULL){
        printf("0\n");
        return;
    }

    while(ptr != NULL){
        printf("%dx^%d",ptr->coeff,ptr->exp);

        if(ptr->next != NULL && ptr->next->coeff >= 0)
            printf(" + ");

        ptr = ptr->next;
    }

    printf("\n");
}

NODE* addPolynomial(NODE* p1, NODE* p2){
    NODE* result = NULL;
    NODE* ptr;

    ptr = p1;
    while(ptr != NULL){
        result = insertTerm(result,ptr->coeff,ptr->exp);
        ptr = ptr->next;
    }

    ptr = p2;
    while(ptr != NULL){
        result = insertTerm(result,ptr->coeff,ptr->exp);
        ptr = ptr->next;
    }

    return result;
}

int main(){

    NODE *p1 = NULL, *p2 = NULL, *sum;
    int n1,n2;

    printf("Enter the number of terms in first polynomial: ");
    scanf("%d",&n1);

    p1 = createPolynomial(n1);

    printf("Enter the number of terms in second polynomial: ");
    scanf("%d",&n2);

    p2 = createPolynomial(n2);

    printf("First Polynomial:\n");
    traverse(p1);

    printf("Second Polynomial:\n");
    traverse(p2);

    sum = addPolynomial(p1,p2);

    printf("Sum of Polynomials:\n");
    traverse(sum);

    return 0;
}