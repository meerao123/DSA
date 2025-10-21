#include<stdio.h>
void LinearSearch(int arr[],int sk,int n){

    int i,flag=0;
    for(i=0;i<n;i++){

        if(arr[i]==sk){
            flag=1;
            break;
        }
    }
    if(flag==1){

        printf("%d found at %d",sk,i+1);
    }
    else{
        printf("%d not found",sk);
    }
}
int main(){
int a[]={4,10,11,-5,8,6};
int n=6;
printf("Enter element you want to search: ");
int s;
scanf("%d",&s);
LinearSearch(a,s,n);
}