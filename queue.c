#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

void enqueue(){
    int value;
    if(rear==MAX-1){
        printf("queue full\n");
        return;
    }
    else{
        printf("Enter the value\n");
        scanf("%d",&value);
        if(front==-1){
            front=0;
        }
        queue[++rear]=value;
        printf("inserted %d\n",value);

    }
}

void dequeue(){
    if(front==-1){
        printf("queue empty\n");
    }
    else{
        printf("dequeued %d",queue[front++]);
        if(front>rear){
            front=rear=-1;
        }
    }
}

void display_Queue(){
    if(front==-1){
        printf("queue empty\n");
    }
    else{
        int i=front;
        while(1){
            printf("%d ",queue[i]);
            if(i==rear){
                break;
            }
            i++;
        }
    }
}

int deque[MAX];
int f=-1, r=-1;

int isempty(){
    return (f==-1);
}

int isfull(){
    return (f==(r+1)%MAX);
}

void insert_front(){
    if(isfull()){
        printf("queue full\n");
        return;
    }
    else{
        int value;
        printf("Enter value\n");
        scanf("%d",&value);
        if(f==-1){
            r=0;f=0;
        }
        else if(f==0){
            f=MAX-1;
        }
        else{
            f--;
        }
        deque[f]=value;
    }
}

void insert_rear(){
    if(isfull()){
        printf("full\n");
        return;
    }
    else{
        int value;
        printf("Enter value\n");
        scanf("%d",&value);
        if(f==-1){
            f=0;r=0;
        }
        else if(r==MAX-1){
            r=0;
        }
        else{
            r=(r+1) %MAX;
        }
        deque[r]=value;
    }
}

void delete_front(){
    if(isempty()){
        printf("empty\n");
        return;
    }
    else{
        printf("deleted %d",deque[f]);
        if(f==r){
            f=r=-1;
        }
        else if(f==MAX-1){
            f=0;
        }
        else{
            f++;
        }
    }
}

void delete_rear(){
    if(isempty()){
        printf("empty\n");
        return;
    }
    else{
        printf("deleted %d",deque[r]);
        if(f==r){
            f=r=-1;
        }
        else if(r==0){
            r=MAX-1;
        }
        else{
            r--;
        }
    }
}

void display(){
    if(isempty()){
        printf("empty\n");
        return;
    }
    int i=f;
    while (1){
        printf("%d",deque[i]);
        if(i==r){
            break;
        }
        i=(i+1)%MAX;
    }
}

int cqueue[MAX];
int frontc=-1, rearc=-1;

int isfullcq(){
   return frontc==(rearc+1)%MAX;
}

int isemptycq(){
    return frontc==-1;
}

void enqueuecq(){
    if(isfullcq()){
        printf("full\n");
        return;
    }
    else{
        int value;
        printf("enter value\n");
        scanf("%d",&value);
        if(frontc==-1){
            frontc=rearc=0;
        }
        else{
            rearc=(rearc+1)%MAX;
        }
        cqueue[rearc]=value;
    }
}

void dequeue(){
    if(isempty()){
        printf("empty\n");
        return;
    }
    else{
        printf("dequeued %d",cqueue[frontc]);
        if(frontc==rearc){
            frontc=rearc=-1;
        }
        else{
            frontc=(frontc+1)%MAX;
        }
    }
}


