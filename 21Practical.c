#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[50];
    int rollno;
    int marks[5];
    float avg;
    char result[10];
    struct node* next;
}NODE;

NODE* createNode(){
    NODE* n = (NODE*)malloc(sizeof(NODE));
    int i,sum=0;

    printf("Enter the name: ");
    scanf(" %[^\n]",n->name);

    printf("Enter the roll number: ");
    scanf("%d",&n->rollno);

    for(i=0;i<5;i++){
        printf("Enter marks of subject %d: ",i+1);
        scanf("%d",&n->marks[i]);
        sum += n->marks[i];
    }

    n->avg = sum/5.0;

    if(n->avg >= 50)
        strcpy(n->result,"Pass");
    else
        strcpy(n->result,"Fail");

    n->next = NULL;

    return n;
}

NODE* append(NODE* head){
    NODE *temp = createNode();
    NODE *ptr;

    if(head == NULL)
        return temp;

    ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;

    return head;
}

void traverse(NODE* head){
    NODE* ptr = head;
    int i;

    if(ptr == NULL){
        printf("No students in database\n");
        return;
    }

    printf("\nRoll\tName\t\tMarks(5)\tAverage\tResult\n");
    printf("-------------------------------------------------------------\n");

    while(ptr != NULL){
        printf("%d\t%s\t",ptr->rollno,ptr->name);

        for(i=0;i<5;i++)
            printf("%d ",ptr->marks[i]);

        printf("\t%.2f\t%s\n",ptr->avg,ptr->result);

        ptr = ptr->next;
    }
}

int main(){

    NODE* head = NULL;
    int choice;

    do{

        printf("\n--------Menu--------\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("0. Exit\n");

        printf("\n--Enter your choice--\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                head = append(head);
                break;

            case 2:
                traverse(head);
                break;
        }

    }while(choice != 0);

    return 0;
}