#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100
char stack [MAX];
int top=-1;

void push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

void infixtopostfix(char infix[],char postfix[]){
    int j=0;

    for(int i=0;infix[i]!='\0';i++){
        char c=infix[i];
        if(isdigit(c)||isalpha(c)){
            postfix[j++]=c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(c)){
                postfix[j++]=pop();
            }
            push(c);
        }
    }
    while (top != -1) {
    postfix[j++] = pop();
}
    postfix[j]='\0';
    
}

struct node{
    char data;
    struct node *left, *right;
};

struct stack{
    struct node *data;
    struct stack *next;
};
struct stack * stack_top=NULL;

struct node *create_node(char value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void push_stack(struct node *treenode){
    struct stack *temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=treenode;
    temp->next=stack_top;
    stack_top=temp;
}

struct node * pop_stack(){
    struct stack *temp=stack_top;
    struct node *res=stack_top->data;
    stack_top=stack_top->next;
    free(temp);
    return res;
}

struct node * exp_tree(char postfix[]){
    for(int i=0;postfix[i]!='\0';i++){
        char c=postfix[i];
        if(isdigit(c)){
            struct node *operand=create_node(c);
            push_stack(operand);
        }
        else{
            struct node *operator=create_node(c);
            operator->right=pop_stack();
            operator->left=pop_stack();
            push_stack(operator);
        }
    }
    return pop_stack();
}

void inorder(struct node *root){
    if(root!=NULL){
        if(root->left && root->right){
            printf("(");
        }
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
        if(root->left && root->right){
            printf(")");
        }

    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (postfix)
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main(){
    struct node *root=NULL;
    int choice;
    char infix[MAX];
    char postfix[MAX];
    printf("enter infix expression");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    while(1){
        printf("enter what u want to do\n1.create exp tree\n2.infix expression\n3.prefix\n4.postfix\n5.exit");
        scanf("%d",&choice);
        switch (choice){
            case 1:
            root=exp_tree(postfix);
            printf("created\n");
            break;
            case 2:
                if(root == NULL) printf("Create the tree first!\n");
                else {
                    printf("Inorder Traversal (Infix): ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if(root == NULL) printf("Create the tree first!\n");
                else {
                    printf("Preorder Traversal (Prefix): ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if(root == NULL) printf("Create the tree first!\n");
                else {
                    printf("Postorder Traversal (Postfix): ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
        }
    }
