#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node *front=NULL, *rear=NULL, *temp;
void enqueue( int value){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=value;
    if(front==NULL){
        rear=newnode;
        front=newnode;

    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    if(front==NULL){
        printf("queue empty\n");
        
    }
    else if(front==rear){
        temp=front;
        front=NULL;
        rear=NULL;
        printf("%d dequeued\n",temp->data);
        free(temp);
    }
    else{
        temp=front;
        front=front->next;
        printf("%d dequeued\n",temp->data);
        free(temp);
        
    }
}

void display()
{
    struct node *temp;
    temp=front;
    if(front==NULL){
        printf("queue empty. enqueue first\n");
    }
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL){
            printf("->");
        }
        temp=temp->next;
    }
}

int main(){
    int choice,value;
    
    while(1){
        printf("----------QUEUE-----------\n");
        printf("enter what you want to do:\n");
        printf("1. enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter the value you want to enqueue: ");
            scanf("%d",&value);
            enqueue(value);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            return 0;
        }
    }
    return 0;
}