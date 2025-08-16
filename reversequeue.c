#include<stdio.h>
#define MAX 10
int queue[MAX];
int f=-1, r=-1;
void enqueue(int value){
    if(f==0 && r==MAX -1){
        printf("queue is full\n");
        return;
    }
    else if(f==-1 && r==-1){
        f=0; r=0;
        queue[r]=value;
    }
    else{
        queue[++r]=value;
    }
}
int dequeue(){
    if((f==-1 && r==-1)|| f==r+1){
        printf("queue is empty\n");
        return -1;
    }
    else{
        return queue[f++];
        
    }
}
void display(){
    if((f==-1 && r==-1)|| f==r+1){
        printf("queue is empty\n");
    }
    else{
        for(int i=f;i<=r;i++){
            printf("%d\t",queue[i]);
        }
    }
    printf("\n");
}

void reversequeue(){

    if((f==-1 && r==-1)|| f==r+1){
       
        return;
    }
    else{
        int data=dequeue();
        reversequeue();
        enqueue(data);

    }
}
int main(){
    int n,val;
    printf("enter the number of elements: \n");
    scanf("%d",&n);
    printf("Enter the queue elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        enqueue(val);

    }
    printf("original queue: ");
    display();
    printf("\nqueue after reversing: ");
    reversequeue();
    display();
    return 0;
    
}