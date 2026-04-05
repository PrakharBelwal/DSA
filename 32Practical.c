#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* left;
    struct node* right;
}NODE;

NODE* createNode(int x){
    NODE* n=(NODE*)malloc(sizeof(NODE));
    n->info=x;
    n->left=NULL;
    n->right=NULL;
    return n;
}

NODE* insert(NODE* root,int x){

    if(root==NULL)
        return createNode(x);

    if(x < root->info)
        root->left=insert(root->left,x);

    else if(x > root->info)
        root->right=insert(root->right,x);

    else
        printf("Value already exists\n");

    return root;
}

NODE* search(NODE* root,int x){

    if(root==NULL || root->info==x)
        return root;

    if(x < root->info)
        return search(root->left,x);

    else
        return search(root->right,x);
}

void inorder(NODE* root){

    static int first = 1;

    if(root==NULL)
        return;

    inorder(root->left);

    if(first){
        printf("%d",root->info);
        first = 0;
    }
    else{
        printf(", %d",root->info);
    }

    inorder(root->right);
}

int main(){

    NODE* root=NULL;
    int choice,x;

    do{

        printf("\n--------Menu--------\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("0. Exit\n");

        printf("\n--Enter your choice--\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:

                printf("Enter the value to insert: ");
                scanf("%d",&x);

                root=insert(root,x);
                break;

            case 2:

                printf("Enter the value to search: ");
                scanf("%d",&x);

                if(search(root,x))
                    printf("Value found\n");
                else
                    printf("Value not found\n");

                break;

            case 3:

                printf("BST elements:\n");
                inorder(root);
                printf("\n");

                break;
        }

    }while(choice!=0);

    return 0;
}