#include <stdio.h>
 
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void readArray (int arr[], int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void bubblesort(int arr[], int n){
    int i,j,temp,swapped;
    for(i=0;i<n-1;i++){
        swapped=0;
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped =1;
            }
        }
        if(swapped==0){
        break;
    }
    }
    
}

int main(){
    int n;
    printf("enter number of elements: \n");
    scanf("%d",&n);
    int arr[n];
    readArray(arr,n);
    printf("original array\n");
    printArray(arr,n);
     printf("sorted array\n");
    bubblesort(arr,n);
    printArray(arr,n);
   return 0;
}