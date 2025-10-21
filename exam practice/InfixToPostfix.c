#include <stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define MAX 20
int top=-1;
char stack[MAX];
void push(char value){
    stack[++top]=value;
}
char pop(){
    return stack[top--];
}
char peek(){
    return stack[top];
}
int isempty(){
    return top==-1;
}
int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c== '-'){
        return 1;
    }
    return 0;
}

int InfixToPostfix(char infix[], char postfix[]){
    int j=0;
     for(int i=0;infix[i]!='\0';i++){
        char c=infix[i];
        if(isdigit(c)){
            postfix[j++]=c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(!isempty() && peek()!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            while(!isempty()&&precedence(peek())>=precedence(c) ){
                postfix[j++]=pop();
            }
            push(c);
        }
     }
     while(!isempty()){
        postfix[j++]=pop();
        
     }
     postfix[j]='\0';
}

int postfixeval(char postfix[]){
    
    int stackeval[MAX];
    int topeval=-1;
    for (int i=0;postfix[i]!='\0';i++){
        char c=postfix[i];
        if(isdigit(c)){
            stackeval[++topeval]=c-'0';
        }
        else{
           int b=stackeval[topeval--];
           int a=stackeval[topeval--];
           switch (c){
            case '*': stackeval[++topeval]=a*b; break;
            case '/': stackeval[++topeval]=a/b; break;
            case '+': stackeval[++topeval]=a+b; break;
            case '-': stackeval[++topeval]=a-b; break;
            case '^': stackeval[++topeval]=(int) pow(a,b); break;
           }
        }
    }
    return stackeval[topeval];
}

int main(){
    char infix[MAX]; char postfix[MAX];
    printf("Enter infix expression:\n");
    scanf("%s",infix);
    InfixToPostfix(infix,postfix);
    printf("%s\n",postfix);
    int result=postfixeval(postfix);
    printf("%d\n",result);
    return 0;
}