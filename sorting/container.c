#include <stdio.h>

#define MAX 100

typedef struct{
    int a,b,c;
}states;

typedef struct{
    states items[MAX];
    int front,rear;
}queue;

int CAP[]={10,7,4};

void enqueue(states s, queue *q){
    q->items[++q->rear]=s;
}

states dequeue(queue *q){
    return q->items[q->front++];
}

int isempty(queue *q){
    return q->front > q->rear;
}

int isgoal(states s){
    return s.b==2 || s.c==2;
}

int isequal(states s1, states s2){
    return s1.a==s2.a && s1.b==s2.b && s1.c ==s2.c;
}

int is_visited(states visited_list[], int visited_count, states s){
    for (int i=0;i<visited_count;i++){
        if(isequal(visited_list[i],s)){
            return 1;
        }
    }
    return 0;
}

states pour(states s, int src, int dst){
    int amt[]={s.a,s.b,s.c};
    int pour_amt= (amt[src]<(CAP[dst]-amt[dst])) ? amt[src]:(CAP[dst]-amt[dst]);
    amt[src]-=pour_amt;
    amt[dst]+=pour_amt;
    states new={amt[0],amt[1],amt[2]};
    return new;
}

int main(){
    int found=0;
    queue q;
    q.front=0;
    q.rear=-1;
    states visited_list[MAX];
    int visited_count=0;
    states start={0,7,4};
    enqueue(start,&q);
    visited_list[visited_count++]=start;

    while(!isempty(&q)){
        states current = dequeue(&q);
        if(isgoal(current)){
            found =1;
            printf("state found(%d,%d,%d)",current.a,current.b,current.c);
            break;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i!=j){
                    int amt[]={current.a,current.b,current.c};
                    if(amt[i]>0 && amt[j]<CAP[j]){
                        states next=pour(current,i,j);
                        if(!is_visited(visited_list,visited_count,next)){
                            enqueue(next,&q);
                            visited_list[++visited_count]=next;
                        }
                    }
                }
            }
        }

    }
    if(!found){
        printf("not found\n");
    }
    return 0;

}