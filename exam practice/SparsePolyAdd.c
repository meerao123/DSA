//find the sum of two sparse polynomials using arrays
#include<stdio.h>
#define MAX 10

struct term{
    int expo;
    int coeff;
};

struct term poly1[MAX], poly2[MAX], result[MAX+MAX];

int PolyAdd(struct term poly1[], int n, struct term poly2[], int m, struct term result[]){
    int i=0; int j=0; int k=0;
    while(i<n && j<m){
        if(poly1[i].expo>poly2[j].expo){
            result[k]=poly1[i];
            i++;
            k++;
        }
        else if(poly2[j].expo>poly1[i].expo){
            result[k]=poly2[j];
            j++;
            k++;
        }
        else{
            result[k].coeff=poly1[i].coeff+poly2[j].coeff;
            result[k].expo=poly1[i].expo;
            i++;
            j++;
            k++;
        }

    }
    while(i<n){
        result[k].coeff=poly1[i].coeff;
        result[k].expo=poly1[i].expo;
        i++;
        k++;
    }
    while(j<m){
        result[k].coeff=poly2[j].coeff;
        result[k].expo=poly2[j].expo;
        k++;
        j++;
    }
    return k;
}

void DisplayPoly(struct term poly[], int n){
    for(int i=0;i<n;i++){
        if(poly[i].coeff!=0){

           printf("%d",poly[i].coeff);
           if(poly[i].expo==1){
            printf("x");
           }
           else if(poly[i].expo>1){
            printf("x^%d",poly[i].expo);
           }
           
           if(i!=n-1){
            printf(" + ");
           }
        }
    }
    printf("\n");
}

int main(){
    int n,m;
    printf("enter number of terms in polynomial 1: \n");
    scanf("%d",&n);
    printf("enter polynomial 1 in descending order(coefficient and exponent): \n");
    for(int i=0;i<n;i++){
       printf("enter %d term",i+1);
        scanf("%d %d",&poly1[i].coeff,&poly1[i].expo );
    }
    printf("enter number of terms in polynomial 2: \n");
    scanf("%d",&m);
    printf("enter polynomial 2 in descending order(coefficient and exponent): \n");
    for(int i=0;i<m;i++){
        printf("enter %d term",i+1);
        scanf("%d %d",&poly2[i].coeff,&poly2[i].expo );
    }
    DisplayPoly(poly1,n);
    DisplayPoly(poly2,m);
    int total=PolyAdd(poly1,n,poly2,m,result);
    DisplayPoly(result,total);
    return 0;
}


