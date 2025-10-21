#include<stdio.h>
#define MAX 5
int arr[MAX];
int f=-1; int r=-1;
void frontenqueue(int value){

    if((f==0 && r==MAX-1) || (f==r+1)){
        printf("the queue is full\n");
    }
    else if(f==0){
        f=MAX-1;
        arr[f]=value;
        printf("%d enqueued successfully!\n",value);
    }
    else if(f==-1 && r==-1){
        f=r=0;
        arr[f]=value;
        printf("%d enqueued successfully!\n",value);
    }
    else{
        f--;
        arr[f]=value;
        printf("%d enqueued successfully!\n",value);
    }

}

void rearenqueue(int value){
    if((f==0 && r==MAX-1) || (f==r+1)){
        printf("the queue is full\n");
    }
    else if(f==-1 && r==-1){
        f=r=0;
        arr[r]=value;
        printf("%d enqueued successfully!\n",value);
    }
    else if(r==MAX-1){
        r=0;
        arr[r]=value;
        printf("%d enqueued successfully!\n",value);
    }
    else{
        r++;
        arr[r]=value;
        printf("%d enqueued successfully!\n",value);
    }
}
void frontdequeue(){
    if(f==-1 && r==-1){
        printf("queue is empty\n");
    }
    else if(f==MAX-1){
        printf("%d dequeued\n",arr[f]);
        f=0;
    }
    else if(f==r){
        printf("%d dequeued\n",arr[f]);
        f=r=-1;
    }
    else{
        printf("%d dequeued\n",arr[f]);
        f++;
    }
}
void reardequeue(){
    if(f==-1 && r==-1){
        printf("queue is empty\n");
    }
    else if(f==r){
        printf("%d dequeued\n",arr[r]);
        f=r=-1;
    }
    else if(r==0){
        printf("%d dequeued\n",arr[r]);
        r=MAX-1;
    }
    else{
        printf("%d dequeued\n",arr[r]);
        r--;
    }

}
void showfront(){
    if(f==-1){
        printf("queue is empty\n");
    }
    printf("%d\n",arr[f]);
}
void showrear(){
    if(f==-1){
        printf("queue is empty\n");
    }
    printf("%d\n",arr[r]);
}
void display(){
    if(f==r==-1){
         printf("queue is empty\n");
    }
    else{
        int i=f;
        while(i!=r){
            printf("%d\t",arr[i]);
            i=(i+1)%MAX;
        }
    }
    printf("%d\n",arr[r]);
}

int main(){
    int n;
    while(1){
        int v;
        printf("enter your option:\n1. insert at front\n2. insert at rear\n3. delete at front\n4.delete at rear\n5.show front\n6.show rear\n7.display queue elements\n8. exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:
            
            printf("enter the value you want to insert\n");
            scanf("%d",&v);
            frontenqueue(v);
            break;
            case 2:
            printf("enter the value you want to insert\n");
            scanf("%d",&v);
            rearenqueue(v);
            break;
            case 3:
            frontdequeue();
            break;
            case 4:
            reardequeue();
            break;
            case 5:
            showfront();
            break;
            case 6:
            showrear();
            break;
            case 7:
            display();
            break;
            case 8:
            return 0;
            default:
            printf("enter valid option\n");
        }
    }
    
}