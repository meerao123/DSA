#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include<stdlib.h>
#define MAX 100

struct node{
    char item;
    struct node *left,*right;
};

struct stack{
    struct node *items[MAX];
    int top;
};

void push(struct stack *s, struct node * n ){
    s->items[++s->top]=n;
}
struct node * pop(struct stack *s){
    return s->items[s->top--];
}

struct node * createnode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->item=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    else return 0;
}

void InfixtoPostfix(char infix[], char postfix[]){
    int j=0;
    char stack[MAX];
    int top=-1;
    for(int i=0;infix[i]!='\0';i++){
        char c=infix[i];
        if(isdigit(c)) postfix[j++]=c;
        else if(c=='(') stack[++top]=c;
        else if(c==')') {
            while(top!=-1 && stack[top]!='(') 
            postfix[j++]=stack[top--]; 
            top--;}
       else{
        while(top!=-1 && precedence(stack[top])>=precedence(c))
        {postfix[j++]=stack[top--];}
         stack[++top]=c;
       }
      
    }
    while(top!=-1){
        postfix[j++]=stack[top--];
    }
    postfix[j]='\0';
}

struct node * expressionTree(char postfix[]){
    struct stack s;
    s.top=-1;
    for(int i=0;postfix[i]!='\0';i++){
        char c=postfix[i];
        if(isdigit(c)) push(&s,createnode(c));
        else{
            struct node *n=createnode(c);
            n->right=pop(&s);
            n->left=pop(&s);
            push(&s,n);
        }
    }
    return pop(&s);
}

void preorder(struct node * root){
    if(root!=NULL){
    printf("%c ", root->item);
    preorder(root->left);
    preorder(root->right);
}
}

void postorder(struct node * root){
    if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->item);
}
}

int main(){
    char infix[MAX];
    char postfix[MAX];
    printf("enter infix expression\n");
    scanf("%s",infix);
    InfixtoPostfix(infix,postfix);
    struct node * root =expressionTree(postfix);
    printf("prefix expression\n");
    preorder(root);
    printf("postfix expression\n");
    postorder(root);
    return 0;
}