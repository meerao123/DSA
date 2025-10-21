#include <stdio.h>
#define MAX 100
#define INF 999

struct node{
    int x,y;
};

struct node queue[MAX];
int rear=-1, front=0;

int rowdir[]={-1,1,0,0};
int coldir[]={0,0,-1,1};

void enqueue(int x, int y){
    rear++;
    queue[rear].x=x ;
    queue[rear].y=y;
}

struct node dequeue(){
    return queue[front++];
}

int isValid(int x, int y, int m, int n){
    return (x>=0&&x<n&&y>=0&&y<m);
}

int main(){
    int MAZE[MAX][MAX];
    int dist[MAX][MAX];
    int n,m;
    printf("Enter number of rows and cols \n");
    scanf("%d %d",&n,&m);
    printf("Enter the maze matrix(0 for traversable and -1 for mine ): \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("[%d][%d]: ",i,j);
            scanf("%d",&MAZE[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=INF;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(MAZE[i][j]==-1){
                enqueue(i,j);
                dist[i][j]=0;
            }
        }
}
while(front<=rear){
    struct node temp=dequeue();
    int x=temp.x;
    int y=temp.y;
    for (int i=0;i<4;i++){
        int nx=x+rowdir[i];
        int ny=y+coldir[i];
        if(isValid(nx,ny,m,n)&&dist[nx][ny]==INF){
        enqueue(nx,ny);
        dist[nx][ny]=dist[x][y]+1;
    }
}
}
printf("Shortest distance: \n");
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(dist[i][j]==INF) printf("INF ");
        else printf("%d ",dist[i][j]);
    }
    printf("\n");
}
return 0;
}
