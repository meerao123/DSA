#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node * createnode(int value){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node * insert_node(int value, struct node *root){
    int choice;
    struct node *newnode=createnode(value);
    if(root==NULL){
        return newnode;
    }
    printf("enter where u wanna insert %d in relation to %d(left-1,right-2)",value,root->data);
    scanf("%d",&choice);
    if(choice==1){
        root->left=insert_node(value,root->left);
    }
    else if(choice==2){
        root->right=insert_node(value,root->right);
    }
    else{
        printf("enter valid choice\n");
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        
       postorder(root->left);
        
        postorder(root->right);
        printf("%d ",root->data);
    }
}


int main(){
    struct node *root;
    int n,value,data;
    printf("enter number of nodes\n");
    scanf("%d",&n);
    
    if(n>0){
        printf("Enter value of root\n");
        scanf("%d",&value);
        root=createnode(value);
        for(int i=1;i<n;i++){
            printf("enter value for %d node",i);
            scanf("%d",&data);
            insert_node(data,root);
        }
    }
    printf("inorder\n");
    inorder(root);
    printf("preoder\n");
    preorder(root);
    printf("postorder\n");
    postorder(root);
    return 0;
}