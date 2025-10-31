#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node * create_node(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node ));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node * insert_node(int value, struct node * root){
    if(root==NULL){
        return create_node(value);
    }
    if(value<root->data){
        root->left=insert_node(value,root->left);
        return root;
    }
    else if(value>root->data){
        root->right=insert_node(value,root->right);
        return root;
    }
}

struct node * search (int value, struct node * root){
    if(root==NULL || root->data==value){
        return root;
    }
    else{
        if(value<root->data){
            search(value,root->left);
        }
        else if(value>root->data){
            search(value,root->right);
        }
    }
}

struct node * find_min(struct node * root){
    if(root==NULL){
        return root;
    }
    else{
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
}

struct node * find_max(struct node * root){
     if(root==NULL){
        return root;
    }
    else{
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
}

struct node * delete(struct node * root, int value){
    if(root==NULL){
        return;
    }
    else if(value<root->data){
            delete(root->left,value);
        }
    else if(value>root->data){
            delete(root->right,value);
        }
    else{
        if(root->left==NULL){
            struct node * temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        if(root->right==NULL){
            struct node *temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else{
            struct node *temp=find_min(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
       
    }
    return root;
}

