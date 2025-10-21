#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * prev, *next;
};
struct node *head=NULL, *newnode,*temp;

struct node * create_node(){
    newnode=(struct node *)malloc(sizeof(struct node));
    return newnode;
}

void insert_begin(int value){
    create_node();
    newnode->data=value;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

void insert_end(int value){
    create_node();
    newnode->data=value;
    newnode->next=NULL;
    
    if(head==NULL){
        newnode->prev=NULL;
        head=newnode;
    }
    else{
        temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
}

void insert_at_pos( int value){
    int pos;
    temp=head;
    
    printf("enter the position u want to insert at (starting index 0): \n");
    scanf("%d",&pos);
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(pos==0){
        insert_begin(value);
    }
    else if(pos==count){
        insert_end(value);
    }
    else if(pos<0 || pos>count){
        printf("enter valid position\n");
        return;
    }
    else{
        create_node();
        temp=head;
        int i=0;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->data=value;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
        
    }
}

void delete_begin(){
    if(head==NULL){
        printf("list empty\n");
    }
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        free(temp);
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
}

void delete_end(){
     if(head==NULL){
        printf("list empty\n");
    }
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        free(temp);
    }
    else{
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        struct node * temp2;
        temp2=temp->next;
        temp->next=NULL;
        free(temp2);

    }
}

void delte_at_pos(){
    int pos;
    printf("enter the position u want to delete at (starting index 0): \n");
    scanf("%d",&pos);
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(pos==0){
        delete_begin();
    }
    else if(pos==count-1){
        delete_end();
    }
    else if(pos<0 || pos>=count){
        printf("enter valid position\n");
        return;
    }
    else{
        temp=head;
        int i=0;
        while(i<pos){
            temp=temp->next;
            i++;
        }
       struct node * temp2;
       temp2=temp->next;
       temp->next=temp2->next;
       temp2->next->prev=temp;
       free(temp);
    }
}
void display(){
    temp=head;
    if (head==NULL)
{
    printf("EMPTY\n");
}
else{
    int i=0;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    temp=head;
    for(i=0;i<count;i++){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
}

int main(){
    while(1){
        printf("------DOUBLY LINKED LIST-------\n");
        printf("enter what operation u want to do: \n");
        printf("1.insert begin\n2.insert end\n3. insert at pos\n4. delete begin\n5. delete end\n6. delete position\n7.display\n8.exit\n");
        int choice,value;
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert_begin(value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_at_pos(value);  // pos will be read inside the function
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                delte_at_pos();   // pos will be read inside the function
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}


