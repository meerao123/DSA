#include <stdio.h>
#define MAX 100
#define INF 999

struct node{
    int x,y;
};

struct node queue[MAX*MAX];
int front=0; int rear=-1;

void enqueue(int x ,int y){
    rear++;
    queue[rear].x=x;
    queue[rear].y=y;
}

struct node dequeue(){
    return queue[front++];
}

int row_dir[]={-1,1,0,0};
int col_dir[]={0,0,-1,1};

int isvalid(int x, int y, int n, int m){
    return x>=0&&x<n && y>=0&&y<m;
}

int main(){
    int maze[MAX][MAX];
    int dist[MAX][MAX];
    int n,m;
    printf("enter no. of rows and cols\n");
    scanf("%d %d",&n,&m);
    printf("Enter the mine elements\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&maze[i][j]);
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=INF;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j]==-1){
                enqueue(i,j);
                dist[i][j]=0;
            }
        }
    }

    while(front<=rear){
        struct node temp=dequeue();
        int x=temp.x;
        int y=temp.y;
        for(int i=0;i<4;i++){
            int nx=x+row_dir[i];
            int ny=y+col_dir[i];
            if(isvalid(nx,ny,n,m)&&dist[nx][ny]==INF){
                dist[nx][ny]=dist[x][y]+1;
                enqueue(nx,ny);
                
            }
        }
    }
    printf("shortest distance :\n");
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    return 0;
   
}
