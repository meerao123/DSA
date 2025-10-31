#include <stdio.h>
#define MAX 10

void GetMat(int mat[][3]){
    int n;
    printf("enter number of non zero values: \n");
    scanf("%d",&n);
    mat[0][2]=n;
    printf("Enter number of rows and cols\n");
    scanf("%d %d",&mat[0][0],&mat[0][1]);
    printf("enter the row, col and value for ");
    for(int i=1;i<=n;i++){
        printf("row %d: ",i);
        scanf("%d %d %d",&mat[i][0],&mat[i][1],&mat[i][2]);
    }
}

void DisplaySparse(int mat[][3]){
    int n=mat[0][2];
    for(int i=0;i<=n;i++){
        printf("%d %d %d\n",mat[i][0],mat[i][1],mat[i][2]);
    }
}

void transpose(int mat[][3], int trans[][3]){
    int n=mat[0][2];
    trans[0][0]=mat[0][1];
    trans[0][1]=mat[0][0];
    trans[0][2]=n;
    int k=1;
    for(int i=0;i<mat[0][2];i++){
        for(int j=1;j<=n;j++){
            if(mat[j][1]==i){
                trans[k][0]=mat[j][1];
                trans[k][1]=mat[j][0];
                trans[k][2]=mat[j][2];
                k++;
            }
        }
    }
}

void AddSparse(int s1[][3], int s2[][3],int res[][3]){
    int n=s1[0][2];
    int m=s2[0][2];
    res[0][0]=s1[0][0];
    res[0][1]=s1[0][1];

    if(s1[0][0]!=s2[0][0] || s1[0][1]!=s2[0][1]){
        printf("cannot add\n");
        return;
    }
    int i=1,j=1,k=1;
    while(i<=n && j<=m){
        if(s1[i][0]<s2[j][0] ||s1[i][0]==s2[j][0] && s1[i][1]<s2[j][1]  ){
            res[k][0]=s1[i][0];
            res[k][1]=s1[i][1];
            res[k][2]=s1[i][2];
            i++;
            k++;
        }
        else if(s1[i][0]>s2[j][0] || s1[i][0]==s2[j][0] &&s1[i][1]>s2[j][1] ){
            res[k][0]=s2[j][0];
            res[k][1]=s2[j][1];
            res[k][2]=s2[j][2];
            j++;
            k++;
        }
        else{
            res[k][0]=s1[i][0];
            res[k][1]=s1[i][1];
            res[k][2]=s1[i][2]+s2[j][2];
            i++;j++;k++;
        }
    }
    while(i<=n){
         res[k][0]=s1[i][0];
            res[k][1]=s1[i][1];
            res[k][2]=s1[i][2];
            i++;
            k++;
    }
    while(j<=m){
         res[k][0]=s2[j][0];
            res[k][1]=s2[j][1];
            res[k][2]=s2[j][2];
            j++;
            k++;
    }
    res[0][2]=k-1;
}

int main(){
    int s1[MAX][3];
    int s2[MAX][3];
    int res[MAX][3];
    int choice;
    while(1){
        printf("enter choice\n");
        printf("1. transpose\n2. sum\n3. exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
            GetMat(s1);
            printf("original matrix\n");
            DisplaySparse(s1);
            transpose(s1,res);
            printf("transpose\n");
            DisplaySparse(res);
            break;

            case 2:
            GetMat(s1);
            GetMat(s2);
            printf("matrix 1\n");
            DisplaySparse(s1);
            printf("matrix 2\n");
            DisplaySparse(s2);
            AddSparse(s1,s2,res);
            printf("sum\n");
            DisplaySparse(res);
            break;

            case 3:
            return 0;

            default:
            printf("enter valid choice\n");

        }
}

}