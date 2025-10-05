#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node *prev;
    char url[100];
    struct node *next;
};

struct node *current=NULL;

void visit_site(char url[]){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    strcpy(newnode->url,url);
    newnode->prev=current;
    if(current!=NULL){
        current->next= newnode;
    }
    current=newnode;
    printf("visited %s",current->url);
}

void prev_site(){
    if(current==NULL|| current->prev==NULL){
        printf("no previously visited site\n");
    }
    else{
        current=current->prev;
        printf("%s\n",current->url);
    }
}

void next_site(){
    if(current==NULL|| current->next==NULL){
        printf("no next page. cannot go forward\n\n");
    }
    else{
        current=current->next;
        printf("%s\n",current->url);
    }
}

void display(){
    if(current==NULL){
        printf("no visited page\n");
    }
    else{
        printf("%s\n",current->url);
    }
}

int main(){
    int choice;
    char url[100];
    while(1){
        printf("\nMenu\n----\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("enter choice: \n");
        scanf("%d",&choice);
        getchar();             //to consume the newline to avoid error for fgets
        switch(choice){
            case 1:
            printf("enter the site u want to visit:\n");
            fgets(url,100,stdin);
            visit_site(url);
            break;
            case 2:
            prev_site();
            break;
            case 3:
            next_site();
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
