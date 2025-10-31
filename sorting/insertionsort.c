#include <stdio.h>

void readArray(int arr[],int n){
    printf("enter array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void printArray(int arr[],int n){
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void insertionsort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        printArray(arr,n);
        printf("\n");
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
    insertionsort(arr,n);
    printArray(arr,n);
   return 0;
}