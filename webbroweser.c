#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *prev;
    char url[100];
    struct node *next;
};

struct node * current =NULL;

void visit_site(char url[]){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->prev=current;
    newnode->next=NULL;
    strcpy(newnode->url,url);
    if(current!=NULL){
        current->next=newnode;
    }
    current=newnode;
    printf("visited %s\n",url);
}

void go_back(){
    if(current==NULL || current->prev==NULL){
        printf("no previos site\n");
    }
    else{
        current =current->prev;
        printf("visited %s",current->url);
    }
}

void go_front(){
    if(current==NULL || current->next==NULL){
        printf("no next site\n");
    }
    else{
        current =current->next;
        printf("visited %s",current->url);
    }
}

void display(){
    if(current==NULL){
        printf("visit a sit first\n");
    }
    else{
        printf("%s",current->url);
    }
}

int main(){
    char url[100];
    int choice;
    while(1){
        printf("\nMenu\n----\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("enter choice: \n");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
            printf("enter the site u want to visit:\n");
            fgets(url,100,stdin);
            visit_site(url);
            break;
            case 2:
            go_back();
            break;
            case 3:
            go_front();
            break;
            case 4:
            display();
            break;
            case 5:
            return 0;
            default:
            printf("enter valid choice\n");
        }
    }
    return 0;
}

