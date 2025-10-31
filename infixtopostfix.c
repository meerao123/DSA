#include <stdio.h>
#include<ctype.h>
#include <math.h>

#define MAX 100
char stack [MAX];
int top=-1;

int stackeval[MAX];
int topeval=-1;

void push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

void pusheval(int value){
    stackeval[++topeval]=value;
}

int popeval(){
    return stackeval[topeval--];
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
    for(int i=0;postfix[i]!='\0';i++){
        printf("%c",postfix[i]);
    }
}

int postfixevaluation(char postfix[]){

    for(int i=0;postfix[i]!='\0';i++){
        char c=postfix[i];
        if(isdigit(c)){
            pusheval(c-'0');
        }
        else{
            int v2=popeval();
            int v1=popeval();
            switch(c){
                case '+': pusheval(v1+v2); break;
                case '-': pusheval(v1-v2); break;
                case '*': pusheval(v1*v2); break;
                case '/': pusheval(v1/v2); break;
                case '^': pusheval(pow(v1,v2)); break;
            }
        }
    }
    return popeval();
}

int main(){
    char infix[MAX];
    char postfix[MAX];
    printf("Enter infix exp\n");
    scanf("%s",infix);
    printf("postfix expression\n");
    infixtopostfix(infix,postfix);
    printf("final ans\n");
    int result=postfixevaluation(postfix);
    printf("%d",result);
    return 0;

}
