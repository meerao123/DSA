#include<stdio.h>
void transpose(int sparse[][3]){
            int totalrows=sparse[0][2]+1;
    int transpose[totalrows][3];
    transpose[0][1]=sparse[0][0];
    transpose[0][0]=sparse[0][1];
    transpose[0][2]=sparse[0][2];
    int k=1;
    for(int j=0;j<sparse[0][1];j++){
        for(int i=1;i<=sparse[0][2];i++){
            if(sparse[i][1]==j){
                transpose[k][1]=sparse[i][0];
                transpose[k][0]=sparse[i][1];
                transpose[k][2]=sparse[i][2];
                k++;

            }
        }

    }

     printf("original matrix\n");
    for(int i=0;i<totalrows;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",sparse[i][j]);
        }
        printf("\n");
    }

    printf("transpose matrix\n");
    for(int i=0;i<totalrows;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",transpose[i][j]);
        }
        printf("\n");
    }


}


int main(){
    int n;
    printf("enter number of non zero values\n");
    scanf("%d",&n);
    int og_sparse[n+1][3];
    printf("Enter total no. of rows, cols\n");
    scanf("%d %d",&og_sparse[0][0],&og_sparse[0][1]);
    og_sparse[0][2]=n;
    printf("Enter row, col and value\n");
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&og_sparse[i][0],&og_sparse[i][1],&og_sparse[i][2]);
    }

    transpose(og_sparse);
    return 0;
}