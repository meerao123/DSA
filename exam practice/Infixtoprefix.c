#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

int top = -1;
char stack[MAX];

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isempty() { return top == -1; }

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;
}

void reverse(char str[]){
    int n = strlen(str);
    for(int i=0;i<n/2;i++){
        char temp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }
}

void InfixToPostfix(char infix[], char postfix[]){
    int j=0;
    top = -1; // reset stack
    for(int i=0; infix[i]!='\0'; i++){
        char c = infix[i];
        if(isdigit(c)){
            postfix[j++] = c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(!isempty() && peek()!='(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        else{
            while(!isempty() && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while(!isempty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int prefixeval(char prefix[]){
    int stackeval[MAX];
    int topeval = -1;
    for(int i = strlen(prefix)-1; i>=0; i--){
        char c = prefix[i];
        if(isdigit(c)){
            stackeval[++topeval] = c - '0';
        } else {
            int a = stackeval[topeval--];
            int b = stackeval[topeval--];
            switch(c){
                case '+': stackeval[++topeval] = a + b; break;
                case '-': stackeval[++topeval] = a - b; break;
                case '*': stackeval[++topeval] = a * b; break;
                case '/': stackeval[++topeval] = a / b; break;
                case '^': stackeval[++topeval] = (int)pow(a,b); break;
            }
        }
    }
    return stackeval[topeval];
}

int main(){
    char infix[MAX], prefix[MAX], temp[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    strcpy(temp, infix);
    reverse(temp);
    for(int i=0; temp[i]!='\0'; i++){
        if(temp[i]=='(') temp[i]=')';
        else if(temp[i]==')') temp[i]='(';
    }

    InfixToPostfix(temp, prefix); // now prefix is actually reversed postfix
    reverse(prefix); // get actual prefix

    printf("Prefix Expression: %s\n", prefix);
    int result = prefixeval(prefix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}
