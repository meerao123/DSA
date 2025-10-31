#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int expo;
    struct node *next;
};

struct node *create_poly(int n){
    struct node*head=NULL;
    struct node *temp=NULL;
    struct node *newnode;
    for(int i=0;i<n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("enter the coefficient of term %d",i+1);
        scanf("%d",&newnode->coeff);
        printf("Enter the expo for term %d",i+1);
        scanf("%d",&newnode->expo);
        if(head==NULL){
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

void display_poly(struct node *head){
    struct node *temp;
    temp=head;
    
    while(temp!=NULL){
        if(temp->coeff!=0){
        printf("%d",temp->coeff);
        
    if(temp->expo !=0 && temp->expo!=1){
        printf("x^%d",temp->expo);
    }
    if(temp->expo==1){
        printf("x");
    }
    if(temp->next!=NULL){
        printf(" + ");
    }
}
    temp=temp->next;
}
    printf("\n");
}

struct node * add_poly(struct node *poly1, struct node *poly2){
    struct node *head=NULL, *temp=NULL, *newnode;
    while(poly1!=NULL && poly2!=NULL){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=NULL;
        if(poly1->expo > poly2->expo){
            newnode->coeff = poly1->coeff;
            newnode->expo = poly1->expo;
            poly1=poly1->next;
        }
        else if(poly2->expo > poly1->expo){
           newnode->coeff = poly2->coeff;
            newnode->expo = poly2->expo;
            poly2=poly2->next;
        }
        else{
            newnode->coeff=poly1->coeff + poly2->coeff;
            newnode->expo=poly1->expo;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        if(head==NULL){
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    while(poly1!=NULL){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->coeff = poly1->coeff;
            newnode->expo = poly1->expo;
        poly1=poly1->next;
        temp->next=newnode;
        temp=newnode;

    }
    while(poly2!=NULL){
         newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->coeff = poly2->coeff;
            newnode->expo = poly2->expo;
        poly2=poly2->next;
        temp->next=newnode;
        temp=newnode;
    }
    return head;
}

struct node * multiply_poly(struct node *poly1, struct node * poly2){
    struct node *head=NULL,*temp=NULL, *newnode, *p=poly2;
    while(poly1!=NULL){
        poly2=p;
        while(poly2!=NULL){
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->next=NULL;
            newnode->coeff=poly1->coeff * poly2->coeff;
            newnode->expo=poly1->expo +poly2->expo;
            if(head==NULL){
                head=newnode;
                temp=head;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
            poly2=poly2->next;
        }
        poly1=poly1->next;
    }
    return head;
}

struct node * merge_poly(struct node *poly){
    struct node *i,*j,*prevj;
    i=poly;
    while(i!=NULL){
        j=i->next;
        prevj=i;
        while(j!=NULL){
        if(i->expo==j->expo){
            i->coeff=i->coeff+j->coeff;
            prevj->next=j->next;
            free(j);
            j=prevj->next;
        }
        else{
            prevj=j;
            j=j->next;
        }
    }
    i=i->next;
    }
    return poly;
}

int main(){
    int n1,n2;
    printf("Enter the number of terms in polynomial 1: \n");
    scanf("%d",&n1);
    printf("enter number of terms in polynomial 2: \n");
    scanf("%d",&n2);
    struct node *polynomial1=create_poly(n1);
    struct node *polynomial2=create_poly(n2);
    printf("polynomial 1:\n");
    display_poly(polynomial1);
    printf("polynomial 2:\n");
    display_poly(polynomial2);
    printf("resultant polynomial\n");
    struct node * result=add_poly(polynomial1,polynomial2);
    display_poly(result);
    struct node * res= multiply_poly(polynomial1,polynomial2);
    struct node *final_res=merge_poly(res);
    printf("after multiplying: \n");
    display_poly(final_res);

    return 0;
}