#include <stdio.h>
#define MAX 100
typedef struct{
    int a,b,c;
}States;

typedef struct{
    States items[MAX];
    int front, rear;
}queue;

int CAP[]={10,7,4};

void enqueue(States s, queue * q){
    q->items[++q->rear]=s;
}

States dequeue(queue *q){
   return q->items[q->front++];
}

int Is_Goal(States s){
    return s.b==2 || s.c==2;
}

int is_empty(queue * q){
    return q->front>q->rear;
}

int state_equal(States s1, States s2){
    return s1.a==s2.a && s1.b==s2.b && s1.c==s2.c;
}

States pour(States s, int src, int dst){
    int amt[]={s.a,s.b,s.c};
    int pour_amt=(amt[src]<(CAP[dst]-amt[dst])) ? amt[src] : (CAP[dst]-amt[dst]);
    amt[src]-=pour_amt;
    amt[dst]+=pour_amt;
    States new_state={amt[0],amt[1],amt[2]};
    return new_state;
}

int is_visited(States visited_list[], int visited_count, States s){
    for(int i=0;i<visited_count;i++){
        if(state_equal(visited_list[i],s)){
            return 1;
        }
        
    }
    return 0;
}

int main(){
    States start= {0,7,4};
    queue q;
    q.front=0;
    q.rear=-1;
    States visited_list[MAX];
    int visited_count=0;
    int found=0;
    enqueue(start,&q);
    visited_list[++visited_count]=start;

    while(!is_empty(&q)){
        States current = dequeue(&q);

        if(Is_Goal(current)){
            found=1;
            printf("goal reached(%d %d %d)\n",current.a,current.b,current.c);
            break;
        }

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i!=j){
                    int amt[3]={current.a,current.b,current.c};
                    if(amt[i]>0 && amt[j]<CAP[j])
                    {
                        States next = pour(current,i,j);
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