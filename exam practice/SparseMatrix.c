#include <stdio.h>
#define MAX 10

void GetMat(int mat[][3]){
    int n;
    printf("enter the number of non zero values: \n");
    scanf("%d",&n);
    
    printf("enter the number of rows and columns: \n");
    scanf("%d %d",&mat[0][0],&mat[0][1]);
    mat[0][2]=n;
    printf("enter the row, col and value: \n");
    for(int i=1;i<=n;i++){
        printf("row %d",i);
        scanf("%d %d %d",&mat[i][0],&mat[i][1],&mat[i][2]);
        }
    }

void DisplaySparse(int mat[][3]){
    int n=mat[0][2];
    for(int i=0;i<=n;i++){
        printf("%d\t%d\t%d\n",mat[i][0],mat[i][1],mat[i][2]);
    }
}

void transpose(int mat[][3],int trans[][3]){
    
    int n=mat[0][2];
    int k=1;
    trans[0][0]=mat[0][1];
    trans[0][1]=mat[0][0];
    trans[0][2]=mat[0][2];
    for(int j=0; j<mat[0][1];j++){
        for(int i=1;i<=n;i++){
            if(mat[i][1]==j){
                trans[k][0]=mat[i][1];
                trans[k][1]=mat[i][0];
                trans[k][2]=mat[i][2];
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
        printf("cannot add these matrices\n");
        return;
    }
    int i=1; int j=1; int k=1;
    while(i<=n && j<=m){
        if(s1[i][0]<s2[j][0] || s1[i][0]==s2[j][0] && s1[i][1]<s2[j][1]){
            res[k][0]=s1[i][0];
            res[k][1]=s1[i][1];
            res[k][2]=s1[i][2];
            k++; i++;
        }
        else if(s2[j][0]<s1[i][0] || s2[j][0]==s1[i][0] && s2[j][1]<s1[i][1] ){
            res[k][0]=s2[j][0];
            res[k][1]=s2[j][1];
            res[k][2]=s2[j][2];
            j++; k++;
        }
        else{
             res[k][0]=s1[i][0];
             res[k][1]=s1[i][1];
             res[k][2]=s1[i][2]+s2[j][2];
             i++; j++; k++;
        }
    }
    while(i<=n){
        res[k][0]=s1[i][0];
        res[k][1]= s1[i][1];
        res[k][2]=s1[i][2];
        i++; k++;
    }

    while(j<=m){
        res[k][0]=s2[j][0];
        res[k][1]= s2[j][1];
        res[k][2]=s2[j][2];
        j++; k++;
    }
    res[0][2]=k-1;
}

int main(){
    int mat1[MAX][3], mat2[MAX][3], res[MAX][3];
    int choice;
    while(1){
        printf("enter choice\n");
        printf("1. transpose\n2. sum\n3. exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
            GetMat(mat1);
            printf("original matrix\n");
            DisplaySparse(mat1);
            transpose(mat1,res);
            printf("transpose\n");
            DisplaySparse(res);
            break;

            case 2:
            GetMat(mat1);
            GetMat(mat2);
            printf("matrix 1\n");
            DisplaySparse(mat1);
            printf("matrix 2\n");
            DisplaySparse(mat2);
            AddSparse(mat1,mat2,res);
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