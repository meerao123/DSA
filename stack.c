#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * top=NULL,*temp, *newnode;

struct node *push(struct node *top, int value){
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(top==NULL){
        top=newnode;
        temp=top;
    }
    else{
       newnode->next=top;
       top=newnode;
    }
    return top;
}

struct node * pop(struct node *top){
    if(top==NULL){
        printf("stack empty\n");
        return NULL;
    }
    else if(top->next==NULL){
        
        temp=top;
        top=NULL;
        printf("popped %d",temp->data);
        free(temp);
        return top;
        
    }
    else{

        temp=top;
        top=top->next;
        printf("popped %d",temp->data);
        free(temp);
        return top;
    }
}

void peek(struct node * top){
    if(top==NULL){
        printf("stack empty\n");
    }
    else{
        printf("%d",top->data);
    }
}

void display_stack(struct node *top){
    temp=top;
    if(top==NULL){
        printf("NULL");
    }
    while(temp!=NULL){
        printf("<-%d",temp->data);
        temp=temp->next;
    }
}
int main(){
    int n,value;
    while(1){
        printf("-------stack-------\n");
        printf("enter your choice: \n");
        printf("1. push\n2.pop\n3.peek\n4.display\n5.exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display_stack(top);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

            

