#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char word[50];
    struct node * next;
};
struct node *head=NULL;

struct node * create_node(const char * word){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    strcpy(temp->word,word);
    temp->next= NULL;
    return temp;
}

void insert_end( const char* word){

    struct node * new=create_node(word);
    if(head==NULL){
        head=new;
        struct node * temp=head;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
        temp=new;
    }

}

void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%s ",temp->word);
        temp=temp->next;
    }
}

void find_and_replace( const char *target, const char *replacement){
    struct node *temp=head;
    while(temp!=NULL){
        if(strcmp(temp->word,target)==0){
            strcpy(temp->word,replacement);
        }
        temp=temp->next;
    }
}


int main(){
    char sentance[200];
    char word[50];
    char replacement[50];
    const char *token;
    printf("enter the sentance\n");
    fgets(sentance,200,stdin);
    sentance[strcspn(sentance,"\n")]='\0';
    token=strtok(sentance," ");
    while(token !=NULL){
        insert_end(token);
        token=strtok(NULL," ");
    }
    printf("enter the word u wanna replace\n");
    fgets(word,50,stdin);
    word[strcspn(word,"\n")]='\0';
    printf("enter the word u wanna replace with\n");
    fgets(replacement,50,stdin);
    replacement[strcspn(replacement,"\n")]='\0';
    find_and_replace(word,replacement);
    printf("modified sentance\n");
    display();
    return 0;
}