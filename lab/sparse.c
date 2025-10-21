#include <stdio.h>
#define MAX 10
typedef struct{
    int exp;
    int coeff;
}terms;

int PolyAdd(terms p1[],int n, terms p2[],int m, terms result[]){
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(p1[i].exp==p2[j].exp){

            result[k].coeff= p1[i].coeff+p2[j].coeff;
            result[k].exp=p1[i].exp;
            i++,j++,k++;
        }
        else if(p1[i].exp>p2[j].exp){

            result[k]=p1[i];
            i++,k++;
        }
        else{
            result[k]=p2[j];
            j++,k++;
        }

    }
    while(i<n){
        result[k++]=p1[i++];
    }
    while(j<m){
        result[k++]=p2[j++];
    }
    return k;

}

void displayPoly(terms t[], int n){
    for(int i=0;i<n;i++){
        printf("%d^%d",t[i].coeff,t[i].exp);
        if(i!=n-1){
            printf(" + ");
        }
    }
}

int main(){
    terms poly1[MAX]={{5,2},{3,3},{1,4},{0,1}};
    terms poly2[MAX]={{4,2},{3,5},{0,2}};
    terms result[MAX];

    int size1=4;
    int size2=3;
    displayPoly(poly1,size1);
    printf("\n");
    displayPoly(poly2,size2);
    printf("\n");
    int resize=PolyAdd(poly1,size1,poly2,size2,result);
    displayPoly(result,resize);
    return 0;

}
