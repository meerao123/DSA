//The General post office wishes to give preferential treatment to its customers.
// They have identified the customer categories as Defence personnel, Differently abled,Senior citizen, Ordinary.
// The customers are to be given preference in the decreasing order - Differently abled, Senior citizen, 
// Defence personnel,Normal person.Generate the possible sequence of completion.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[100];
    int priority;
    struct node * next;
};
struct node *head=NULL;

struct node * create_node(char name[], int priority){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    strcpy(temp->name,name);
    temp->priority=priority;
    temp->next=NULL;
    return temp;
}

void enqueue(char name[],int priority){
    struct node *newnode=create_node(name,priority);
    
    if(head==NULL|| priority>head->priority){
        newnode->next=head;
        head=newnode;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL && temp->next->priority>=priority){
            temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
        printf("customer added: %s (priority: %d)",newnode->name, newnode->priority);
    }

void dequeue(){
    if(head==NULL){
        printf("queue empty\n");
    }
    else{
        struct node *temp=head;
        printf("serving: %s (priority: %d)",head->name,head->priority);
        head=head->next;
        free(temp);
    }
}

void displayqueue(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%s (priority %d)-->",temp->name,temp->priority);
        temp=temp->next;
    }
    printf("NULL\n");

}

int main(){
    int choice;
    char name[100];
    int priority;
    while (1){
    printf("Enter choice: 1. add customer\n2. serve customer\n3. display queue\n4. exit\n");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
        printf("enter name : ");
        fgets(name,100,stdin);
        printf("enter priority: 1-ordinary\n2.defence \n3.senior citizen\n4.differently abled\n");
        scanf("%d",&priority);
        enqueue(name,priority);
        displayqueue();
        break;
        case 2:
        dequeue();
        displayqueue();
        break;
        case 3:
        displayqueue();
        break;
        case 4:
        printf("exiting\n");
        return 0;
        default:
        printf("enter valid choice\n");
     }
    }

}
